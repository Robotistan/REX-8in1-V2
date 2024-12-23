import bluetooth
import time
from machine import Pin, PWM

# Bluetooth Low Energy (BLE) Class
class ESP32_BLE:
    """
    A class for handling BLE communication on ESP32 devices.
    Features:
    - Advertising a custom service and characteristic.
    - Reading and writing data from BLE clients.
    - Executing custom callbacks on data write events.
    """
    def __init__(self, name="REX 8in1", service_uuid=None, characteristic_uuid=None, on_write_callback=None):
        """
        Initialize the BLE service with a name, UUIDs, and optional callback for write events.
        :param name: The BLE device name (default: "REX 8in1").
        :param service_uuid: UUID for the BLE service (default: "6E400001-B5A3-F393-E0A9-E50E24DCCA9E").
        :param characteristic_uuid: UUID for the BLE characteristic (default: "6E400002-B5A3-F393-E0A9-E50E24DCCA9E").
        :param on_write_callback: Optional function to handle data written by clients.
        """
        self.name = name
        self.service_uuid = bluetooth.UUID(service_uuid or "6E400001-B5A3-F393-E0A9-E50E24DCCA9E")
        self.characteristic_uuid = bluetooth.UUID(characteristic_uuid or "6E400002-B5A3-F393-E0A9-E50E24DCCA9E")
        self.on_write_callback = on_write_callback
        self.ble = bluetooth.BLE()
        self.ble.active(True)
        self.connections = set()  # To track connected BLE devices
        self.buffer = None        # Store the latest data written to the characteristic
        self.char_handle = None   # Handle for the characteristic
        self._setup_ble()         # Initialize BLE services

    def _setup_ble(self):
        """
        Internal function to set up the BLE service and characteristic, and start advertising.
        """
        self.ble.irq(self._ble_irq)  # Register the BLE IRQ handler
        service = (
            self.service_uuid,
            ((self.characteristic_uuid, bluetooth.FLAG_READ | bluetooth.FLAG_WRITE | bluetooth.FLAG_NOTIFY,),),
        )
        ((self.char_handle,),) = self.ble.gatts_register_services((service,))  # Register the service
        self.ble.gatts_set_buffer(self.char_handle, 100)  # Optional: Set buffer size for the characteristic
        self._advertise()  # Start advertising

    def _ble_irq(self, event, data):
        """
        Internal IRQ handler for BLE events.
        Handles connection, disconnection, and data write events.
        """
        if event == 1:  # _IRQ_CENTRAL_CONNECT
            conn_handle, _, _ = data
            self.connections.add(conn_handle)  # Track the connection
            #print(f"Device connected: Connection Handle {conn_handle}")
        elif event == 2:  # _IRQ_CENTRAL_DISCONNECT
            conn_handle, _, _ = data
            self.connections.discard(conn_handle)  # Remove the connection
            #print(f"Device disconnected: Connection Handle {conn_handle}")
            self._advertise()  # Restart advertising after disconnection
        elif event == 3:  # _IRQ_GATTS_WRITE
            conn_handle, attr_handle = data
            if attr_handle == self.char_handle:  # Check if data is written to the correct characteristic
                buf = self.ble.gatts_read(attr_handle)  # Read the incoming data
                self.buffer = [byte for byte in buf]  # Convert data to a list of integers
                # Call the user-provided callback, if available
                if self.on_write_callback:
                    self.on_write_callback(self.buffer)

    def _advertise(self):
        """
        Internal function to start advertising the BLE service.
        """
        print("Starting advertising...")
        adv_data = self._advertising_payload(self.name, [self.service_uuid])
        self.ble.gap_advertise(100, adv_data)  # Advertise at 100 ms intervals

    def _advertising_payload(self, name=None, services=None):
        """
        Helper function to generate BLE advertising payload.
        :param name: Name of the BLE device.
        :param services: List of service UUIDs to advertise.
        :return: Byte array for the advertising payload.
        """
        payload = bytearray()
        if name:
            payload += bytearray((len(name) + 1, 0x09)) + name.encode('utf-8')
        if services:
            for uuid in services:
                b = bytes(uuid)
                payload += bytearray((len(b) + 1, 0x03)) + b
        return payload

    def get_data(self):
        """
        Retrieve the latest data written to the characteristic.
        :return: List of bytes representing the data.
        """
        return self.buffer

    def clear_data(self):
        """
        Clear the received data buffer.
        """
        self.buffer = None
        
# Servo Motor Control Class
class Servo:
    """
    A class for controlling servo motors using PWM signals.
    Features:
    - Customizable frequency, duty cycle, and angle range.
    - Smooth movement by setting angles.
    """
    __servo_pwm_freq = 50   # Default frequency for servos (50 Hz)
    __min_u10_duty = 26 - 0 # Minimum duty cycle (10-bit value)
    __max_u10_duty = 123- 0 # Maximum duty cycle (10-bit value)
    min_angle = 0           # Minimum angle for the servo
    max_angle = 180         # Maximum angle for the servo
    current_angle = 0.001   # Current angle of the servo

    def __init__(self, pin):
        """
        Initialize the servo motor on the specified pin.
        :param pin: Pin number for the servo motor.
        """
        self.__initialise(pin)

    def update_settings(self, servo_pwm_freq, min_u10_duty, max_u10_duty, min_angle, max_angle, pin):
        """
        Update the servo settings for custom configurations.
        """
        self.__servo_pwm_freq = servo_pwm_freq
        self.__min_u10_duty = min_u10_duty
        self.__max_u10_duty = max_u10_duty
        self.min_angle = min_angle
        self.max_angle = max_angle
        self.__initialise(pin)

    def move(self, angle):
        """
        Move the servo to the specified angle.
        :param angle: Target angle for the servo.
        """
        # Round angle to avoid unnecessary adjustments
        angle = round(angle, 2)
        if angle == self.current_angle:
            return
        self.current_angle = angle
        # Calculate duty cycle for the target angle
        duty_u10 = self.__angle_to_u10_duty(angle)
        self.__motor.duty(duty_u10)

    def __angle_to_u10_duty(self, angle):
        """
        Convert angle to a corresponding duty cycle.
        :param angle: Angle to convert.
        :return: Duty cycle value.
        """
        return int((angle - self.min_angle) * self.__angle_conversion_factor) + self.__min_u10_duty

    def __initialise(self, pin):
        """
        Initialize the PWM settings for the servo.
        """
        self.current_angle = -0.001
        self.__angle_conversion_factor = (self.__max_u10_duty - self.__min_u10_duty) / (self.max_angle - self.min_angle)
        self.__motor = PWM(Pin(pin))
        self.__motor.freq(self.__servo_pwm_freq)
