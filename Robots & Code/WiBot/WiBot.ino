//Wi-Bot

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Arduino.h>
#include <analogWrite.h>


#define MotorA1 15
#define MotorA2 23

#define MotorB1 32
#define MotorB2 33

#define MotorC1 5
#define MotorC2 4

#define MotorD1 14
#define MotorD2 27

#define horn 2
void setup() {
  pinMode(horn, OUTPUT);
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);

  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);

  pinMode(MotorC1, OUTPUT);
  pinMode(MotorC2, OUTPUT);

  pinMode(MotorD1, OUTPUT);
  pinMode(MotorD2, OUTPUT);

  Serial.begin(115200);
  Dabble.begin("REX_ROBOT");
}

void loop() {
  //Bu fonksiyon mobil cihazdan gelen bilgilerin güncel tutulması için kullanılır.
  Dabble.processInput();
  //ilk olarak araç dursun
  dur();
  //bu bölümde basılan düğmeye göre ne iş yapılacağını belirliyoruz
  Serial.print("Dümeye basıldı: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("İleri");
    forward();//aracı ileri süren fonksiyon
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Geri");
    geri();//aracı geri süren fonksiyon
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Sola");
    left();
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Sağa");
    right();
  }

  //gamepad üzerindeki diğer fonksiyonlar
  //istersek bunlara da görevler atayabiliriz.

  if (GamePad.isSquarePressed())
  {
    Serial.print("Kare");

  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Daire");
    for (int i = 0; i < 3; i++)
    {
      forward();
      tone(horn, 330);
      delay(300);
      left();
      tone(horn, 430);
      delay(300);
      right ();
      tone(horn, 530);
      delay(300);
      tone(horn, 630);
      left();
      delay(300);
      noTone(2);
    }
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Çarpı");
    digitalWrite(horn, HIGH);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Üçgen");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  //analog modda joypad kullanılırsa açı değerleri alınarak da yine görev yapılabilir.

  int a = GamePad.getAngle();
  Serial.print("Açı: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Yarıçap: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_ekseni: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_ekseni: ");
  Serial.println(d);
  Serial.println();


}

//aracın hareketi için motorları süreceğimiz fonksiyonlar
void forward() { // ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);
}


void right() { // sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, HIGH);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, HIGH);
  digitalWrite(MotorD2, LOW);

}
void left() { // sola dönme hareketi için fonksiyon tanımlıyoruz.
 
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, HIGH);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);

}


void dur() { // durma hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, LOW);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, LOW);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, LOW);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, LOW);

}
void geri() { // geri hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorA1, LOW);
  digitalWrite(MotorA2, HIGH);

  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

  digitalWrite(MotorC1, LOW);
  digitalWrite(MotorC2, HIGH);

  digitalWrite(MotorD1, LOW);
  digitalWrite(MotorD2, HIGH);

}
