<xml xmlns="https://developers.google.com/blockly/xml"><variables><variable id="FZ86#j3#_JP/FPP~r^=Q">position1</variable><variable id="n2k:}J,s]8fmL?,pImJA">position2</variable><variable id="%}k-XcC~/stzVVnoxJ9M">position3</variable><variable id="Q:o5]fUOTl870pIy+mT{">position4</variable><variable id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</variable><variable id="L6cQF3^J`nsvFUar;~cd">Servo_Motor</variable><variable id="^8iP!S|r|$C3w.^TNnik">DC_Motor</variable><variable id=")@~@)uF/d*Ot?ZI:HItT">last_mode</variable></variables><block type="Robotistan_Start" id="zzU3|,JgGiN857[?$}]^" x="-330" y="-510"><next><block type="variables_set" id="^Hp-GAIu6~Y+$i$yitN!"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field><value name="VALUE"><block type="math_number" id=",ezrUf*fFaS_c}n]h?E."><field name="NUM">0</field></block></value><next><block type="variables_set" id="b_drZB_QzQIge3dhH`%Y"><field name="VAR" id="L6cQF3^J`nsvFUar;~cd">Servo_Motor</field><value name="VALUE"><block type="math_number" id="T7U?h`y*+#,3BR/yc1;)"><field name="NUM">1</field></block></value><next><block type="variables_set" id=".VnpD_A]E@7#1v[o${$F"><field name="VAR" id="^8iP!S|r|$C3w.^TNnik">DC_Motor</field><value name="VALUE"><block type="math_number" id="^q/j1f3NBAoX%4=OkU}~"><field name="NUM">0</field></block></value><next><block type="variables_set" id="GPCef/fu(E~.v)#c10[}"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field><value name="VALUE"><block type="math_number" id="z,Ez}J]Ryqp+rXR~y67k"><field name="NUM">90</field></block></value><next><block type="variables_set" id="^eX*jSp7%Gzw#[f6mm{:"><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field><value name="VALUE"><block type="math_number" id="%ER$Q2:|l{s5;y(d(/-["><field name="NUM">90</field></block></value><next><block type="variables_set" id="/?^5gtYj6]oqR.+!t9NH"><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field><value name="VALUE"><block type="math_number" id="!)#:Xv6EC!+u%ICj|7^z"><field name="NUM">90</field></block></value><next><block type="variables_set" id="E_g}7JX~r4dchdH7Osqd"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field><value name="VALUE"><block type="math_number" id="KhVnnbm4$uABFL@qe7ql"><field name="NUM">90</field></block></value><next><block type="control_forever" id="HvKle(vH[c+HC!0x|_nz"><statement name="DO"><block type="controls_if" id="o8fbO-`-,W;gIEpe-`43"><value name="IF0"><block type="dabbleIsConnected" id="ii2MGA#BKFqy^9LtbCoX"/></value><statement name="DO0"><block type="dabbleRun" id="m^U(8,=jcK$vyTvL!HX1"/></statement></block></statement></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block><block type="dabbleDefinition" id="R}#V4*[LpRxyLL}*S3%m" x="-10" y="-410"><statement name="DO"><block type="globalVariables" id="IJ7@,VK@=*df,kB*U_@i"><mutation items="7"/><value name="ADD0"><block type="variables_get" id="Vv0EZx4|K`QI%i/mP-/,"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field></block></value><value name="ADD1"><block type="variables_get" id="DV#7~n-to*$`T#vF=[~W"><field name="VAR" id="^8iP!S|r|$C3w.^TNnik">DC_Motor</field></block></value><value name="ADD2"><block type="variables_get" id="l75YE4-@:p,)wFt.p]QE"><field name="VAR" id="L6cQF3^J`nsvFUar;~cd">Servo_Motor</field></block></value><value name="ADD3"><block type="variables_get" id="[SH)#Dai6vY:8h,-$5$e"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field></block></value><value name="ADD4"><block type="variables_get" id="B?,hUudbzRy)_b[VzCr("><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field></block></value><value name="ADD5"><block type="variables_get" id="gT]2!G|u[KsM/C|h}e!0"><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field></block></value><value name="ADD6"><block type="variables_get" id="d,3fw?E9duP=#9TDmHwW"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field></block></value><next><block type="variables_set" id="ynCwpmj2#SXhgWPpC%=)"><field name="VAR" id=")@~@)uF/d*Ot?ZI:HItT">last_mode</field><value name="VALUE"><block type="variables_get" id="3r~[RQoV?*ABG.5S7~K?"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field></block></value><next><block type="controls_if" id="`NxMbZOnJ~+?WjQ`~9E-"><mutation xmlns="http://www.w3.org/1999/xhtml" elseif="1" else="1"></mutation><value name="IF0"><block type="dabbleGiveCommand" id="WSQy/?8ZEZFM:U[RiIjz"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x02,0x00,0x00])</field></block></value><statement name="DO0"><block type="variables_set" id="orEp|1gem);b){^$y!kc"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field><value name="VALUE"><block type="variables_get" id="tu|8/;#w!#/rXfK]4*%P"><field name="VAR" id="L6cQF3^J`nsvFUar;~cd">Servo_Motor</field></block></value></block></statement><value name="IF1"><block type="dabbleGiveCommand" id="9WsB5cnG!F3+x=kP,E8r"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x01,0x00,0x00])</field></block></value><statement name="DO1"><block type="variables_set" id="GDE1uJzdEUj0=wSyG+fX"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field><value name="VALUE"><block type="variables_get" id="Y.v+Gr#q*PqKh90au,Jb"><field name="VAR" id="^8iP!S|r|$C3w.^TNnik">DC_Motor</field></block></value></block></statement><statement name="ELSE"><block type="variables_set" id="kAyYz)Xy1pBZJC#B(*F}"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field><value name="VALUE"><block type="variables_get" id="bv+!/TIWHPk|9?dHDJK_"><field name="VAR" id=")@~@)uF/d*Ot?ZI:HItT">last_mode</field></block></value></block></statement><next><block type="controls_if" id="A?_pjtZefxRE?4}2+}^~"><mutation xmlns="http://www.w3.org/1999/xhtml" else="1"></mutation><value name="IF0"><block type="logic_compare" id="L8ve%sl!/*.[[O]s~13;"><field name="OP">EQ</field><value name="A"><block type="variables_get" id="#[c|Jx?g*da8.^BV`rJI"><field name="VAR" id="kb6RcW/6*k#4sfzu[;j/">Motor_Type</field></block></value><value name="B"><block type="variables_get" id="HHZ[cGCSHM{1F(kvp--k"><field name="VAR" id="L6cQF3^J`nsvFUar;~cd">Servo_Motor</field></block></value></block></value><statement name="DO0"><block type="controls_if" id="yT7LdDEDAbPWTms{U#X3"><value name="IF0"><block type="dabbleGiveCommand" id="{oJ(ft_~H`$MAE0)o[v}"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x01,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="PVLA+W@]K5eE4-bW~,O#"><value name="IF0"><block type="logic_compare" id="67^AdM_eFM]a*;U:2)/4"><field name="OP">GT</field><value name="A"><block type="variables_get" id="KVLFnXsK)yY73A!yrHjp"><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field></block></value><value name="B"><block type="math_number" id=".iM?4[4{OS#TA!L$Ljjx"><field name="NUM">0</field></block></value></block></value><statement name="DO0"><block type="math_change" id="u#kB9,=Dt|Xk$a2QXw=/"><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field><value name="DELTA"><shadow type="math_number" id="MbBHE52a({g[|t0j]l3."><field name="NUM">-5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="%Zc48TyYjo|{Ww(pf2w^"><value name="IF0"><block type="dabbleGiveCommand" id="WfTA^3e-dqttf8V*zW)I"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x02,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="H8:knr:kC2:pqMht$TX5"><value name="IF0"><block type="logic_compare" id=")7*xBc}NRdu[*kIqmiiz"><field name="OP">LT</field><value name="A"><block type="variables_get" id="yxl.31efd]9[03Pa7D6y"><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field></block></value><value name="B"><block type="math_number" id=";~}L!53Vhb#?L+)|5~?y"><field name="NUM">140</field></block></value></block></value><statement name="DO0"><block type="math_change" id="p%}(JQ2XVm`bKFZ[42s)"><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field><value name="DELTA"><shadow type="math_number" id="(sM`$R=:j3aIrM|gTl=w"><field name="NUM">5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="lY=qdqZ}^n_d9Hx%P2k-"><value name="IF0"><block type="dabbleGiveCommand" id="bJVB/_Uy1ol_i{t!h$N]"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x04,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="T^34SHuyIBh4:7x62BtZ"><value name="IF0"><block type="logic_compare" id="[if0}6b|9p1w6@$KN1r$"><field name="OP">GT</field><value name="A"><block type="variables_get" id="G:xQrmpX9?gF/xS477*U"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field></block></value><value name="B"><block type="math_number" id="sSO#E2fkSZ|MN*WX/XlY"><field name="NUM">40</field></block></value></block></value><statement name="DO0"><block type="math_change" id="0@%LZv*r~RJ@4E;=+mG+"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field><value name="DELTA"><shadow type="math_number" id="]1SA|HIZGV[~f4zu}~-2"><field name="NUM">-5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="X8hEr^K-,lkTuf.jW]T]"><value name="IF0"><block type="dabbleGiveCommand" id="!$myPI(,4/cOM{P+=UVK"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x08,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="QODp],AA.A:W6,r#X-_}"><value name="IF0"><block type="logic_compare" id="#tOHmew;k;=UW719vkW5"><field name="OP">LT</field><value name="A"><block type="variables_get" id="dv;A7mW4Ql1(T+`n@d-m"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field></block></value><value name="B"><block type="math_number" id="4FC6_0aRk5c8{|JNH%bf"><field name="NUM">140</field></block></value></block></value><statement name="DO0"><block type="math_change" id="~gFbAkY}cO{nt=+c}2^g"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field><value name="DELTA"><shadow type="math_number" id="ytW4$Bq6N5hx{q%JBDx-"><field name="NUM">5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="j4Tv3]DaBWh3j0kcWZQ^"><value name="IF0"><block type="dabbleGiveCommand" id="Hwt:,?}n%`@jtz+U?C1o"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x04,0x00,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="g,Jb:kv/W]tNjC7+7Jxw"><value name="IF0"><block type="logic_compare" id="i14.~-{^,_KWOX%b_RT+"><field name="OP">LT</field><value name="A"><block type="variables_get" id="$R@shBm$fQkY$OwWu~L["><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field></block></value><value name="B"><block type="math_number" id="#N-SkssZW4B)3yF0aKgH"><field name="NUM">150</field></block></value></block></value><statement name="DO0"><block type="math_change" id="9tB1fODDeg6SzvXdD4}#"><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field><value name="DELTA"><shadow type="math_number" id="7guKxz-9n-mB#!iW.FR0"><field name="NUM">5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="wx0a4aESHy;Ov%^!ft;="><value name="IF0"><block type="dabbleGiveCommand" id="U;VA]=c}F;6f78GNk.{4"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x20,0x00,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="67c3PWhf*P+1rvl+=?!^"><value name="IF0"><block type="logic_compare" id="+XNp=ixQU`5D@aakoP|:"><field name="OP">LT</field><value name="A"><block type="variables_get" id="cCy0Ct}*dyHoDOy)oTEJ"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field></block></value><value name="B"><block type="math_number" id="$/F8xtJEN::2;y4JW`eb"><field name="NUM">160</field></block></value></block></value><statement name="DO0"><block type="math_change" id="*txjE}7DA7e=U|WuP!dD"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field><value name="DELTA"><shadow type="math_number" id="%*AtwjJ1pkN)^bO4AJ|G"><field name="NUM">5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="J]}VI|7yY3TQC4y.qx87"><value name="IF0"><block type="dabbleGiveCommand" id="oQzuX+_!CzKA7T|)_.Zg"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x08,0x00,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="l`iks#!2CFm?-H,LL]jP"><value name="IF0"><block type="logic_compare" id="OEE``o%.p}JuqP*-`u25"><field name="OP">GT</field><value name="A"><block type="variables_get" id="M^?jfCb):P8)CLrn3Tr2"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field></block></value><value name="B"><block type="math_number" id="d(yuLuPtp.][VI7;8Fwn"><field name="NUM">40</field></block></value></block></value><statement name="DO0"><block type="math_change" id="Pd~nR_?YXn!2vT`j,G09"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field><value name="DELTA"><shadow type="math_number" id="~*+|1d6WQXuzwD1=d]^M"><field name="NUM">-5</field></shadow></value></block></statement></block></statement><next><block type="controls_if" id="AIjdv95HEr^DGh3UnM]^"><value name="IF0"><block type="dabbleGiveCommand" id="X*V(8pCHUE;8BOUUz1RY"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x10,0x00,0x00])</field></block></value><statement name="DO0"><block type="controls_if" id="ecSyaUq?MSo#`[hH=4#Y"><value name="IF0"><block type="logic_compare" id="CfwJ;G$0.}P%^mRC7:Oj"><field name="OP">GT</field><value name="A"><block type="variables_get" id="I`D-(EtUw//GZ{w7g_[k"><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field></block></value><value name="B"><block type="math_number" id="(gcnyq!wtUS)V3}OrWWx"><field name="NUM">30</field></block></value></block></value><statement name="DO0"><block type="math_change" id="$;McDVy(]6p{Q.3CQi^."><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field><value name="DELTA"><shadow type="math_number" id="%a@70fRJ}{UGp,zuC]R4"><field name="NUM">-5</field></shadow></value></block></statement></block></statement><next><block type="servoMotor" id="L@;E^f:eOv7:%}h$lAJt"><field name="MOTOR">1</field><value name="ANGLE"><shadow type="math_positive_number" id="0w.goah8}0WmpwWtY!L!"><field name="NUM">180</field></shadow><block type="variables_get" id="RncM@[+~88e,h2_,!aFg"><field name="VAR" id="FZ86#j3#_JP/FPP~r^=Q">position1</field></block></value><next><block type="servoMotor" id="k]:up?:t^qXC8F.FRSl="><field name="MOTOR">2</field><value name="ANGLE"><shadow type="math_positive_number" id="ChLSE@.N/Y#V1*82F;:["><field name="NUM">180</field></shadow><block type="variables_get" id=";|Id8!|MuNShFW%Lj8{J"><field name="VAR" id="n2k:}J,s]8fmL?,pImJA">position2</field></block></value><next><block type="servoMotor" id="?PaP^W*^w;qGuW9*Ff]6"><field name="MOTOR">3</field><value name="ANGLE"><shadow type="math_positive_number" id="`GM9??|;tp5P[Q|$jyi4"><field name="NUM">180</field></shadow><block type="variables_get" id="tw+(bSR~{p4m;tAoKRGd"><field name="VAR" id="%}k-XcC~/stzVVnoxJ9M">position3</field></block></value><next><block type="servoMotor" id="9Df.x?Dc`?XhZc~s6!mu"><field name="MOTOR">4</field><value name="ANGLE"><shadow type="math_positive_number" id="3;Kd{w|Gb%fB$b`0.}X1"><field name="NUM">180</field></shadow><block type="variables_get" id="i!#rB|1ByAuRN;=tU|.$"><field name="VAR" id="Q:o5]fUOTl870pIy+mT{">position4</field></block></value></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></next></block></statement><statement name="ELSE"><block type="controls_if" id="ShO$!$GfY:%eLl=x%.m?"><mutation xmlns="http://www.w3.org/1999/xhtml" elseif="3" else="1"></mutation><value name="IF0"><block type="dabbleGiveCommand" id="o*bP3kdYd2CSP@Hhf:#F"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x01,0x00])</field></block></value><statement name="DO0"><block type="DirectionSpeed" id="BrvwoOV:g3-%z3Np@BjQ"><field name="Direction">forward</field><value name="SPEED"><shadow type="math_positive_number" id="8lTVk4*8ar(^$pN:=vK~"><field name="NUM">100</field></shadow></value></block></statement><value name="IF1"><block type="dabbleGiveCommand" id="b%5s}q)MVVw0!T[yk5u)"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x02,0x00])</field></block></value><statement name="DO1"><block type="DirectionSpeed" id="wKdeZAvyY/{%eGh(t|]^"><field name="Direction">backward</field><value name="SPEED"><shadow type="math_positive_number" id=":]gLc~}7jR-Czk,?VuaT"><field name="NUM">100</field></shadow></value></block></statement><value name="IF2"><block type="dabbleGiveCommand" id="w5*}N^nbYjcuBl]y_BM]"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x04,0x00])</field></block></value><statement name="DO2"><block type="DirectionSpeed" id="}mV^y/!F]q^sB3Y05hp9"><field name="Direction">left</field><value name="SPEED"><shadow type="math_positive_number" id="Wu[*|nh6f-RX:udU[+D1"><field name="NUM">100</field></shadow></value></block></statement><value name="IF3"><block type="dabbleGiveCommand" id="ERCn%dnBoA`KKv;v#|0l"><field name="VALUE">bytearray([0xff,0x01,0x01,0x01,0x02,0x00,0x08,0x00])</field></block></value><statement name="DO3"><block type="DirectionSpeed" id="#{=)XTZX:{[yw#tRyA]L"><field name="Direction">right</field><value name="SPEED"><shadow type="math_positive_number" id="bOo`X?V.2D)!]f~)Y7$}"><field name="NUM">100</field></shadow></value></block></statement><statement name="ELSE"><block type="stopMotors" id="5$T9uGgGq5Y=HRT1!OMb"/></statement></block></statement></block></next></block></next></block></next></block></statement></block></xml>