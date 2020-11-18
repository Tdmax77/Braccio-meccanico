// www.ProgettiArduino.com
// Pan tilt controllato da joystick

#include <Servo.h>
char tasto = 0;
int Servo_A_Pin = 11;
int Servo_B_Pin = 10;
int Servo_C_Pin = 9;
int Servo_D_Pin = 5;
int Pin_A = A0;
int Pin_B = A1;
int Pin_C = A2;
int Pin_D = A3;
int A_Min = 0;
int A_Max = 180;
int B_Min = 20;
int B_Max = 60;
int C_Min = 30;
int C_Max = 90;
int D_Min = 0;
int D_Max = 90;

Servo A;
Servo B;
Servo C;
Servo D;

int A_PotValue;
int A_Position = 97;   //30-204
int B_PotValue;
int B_Position = 90;   //85 -100
int C_PotValue;
int C_Position = 65; //13 92
int D_PotValue;
int D_Position = 55; //66  

void setup()
{
  Serial.begin(9600);
  A.attach(Servo_A_Pin);
  B.attach(Servo_B_Pin);
  C.attach(Servo_C_Pin);
  D.attach(Servo_D_Pin);
}

void loop()
{

  tasto = Serial.read();
  switch (tasto) {
    case 'a':
      A_Position = A_Position + 5;
      break;

    case 'd':
      A_Position = A_Position - 5;
      break;

    case 'w':
      B_Position = B_Position + 5;
      break;

    case 'x':
      B_Position = B_Position - 5;
      break;

    case 'j':
      C_Position = C_Position + 5;
      break;

    case 'l':
      C_Position = C_Position - 5;
      break;

    case 'i':
      D_Position = D_Position + 5;
      break;

    case ',':
      D_Position = D_Position - 5;
      break;


  }
  A_PotValue  = analogRead(Pin_A);
  B_PotValue  = analogRead(Pin_B);
  C_PotValue  = analogRead(Pin_C);
  D_PotValue  = analogRead(Pin_D);
  // A_Position  = map(A_PotValue, 0, 1023, A_Min , A_Max);
  //B_Position  = map(B_PotValue, 0, 1023, B_Max , B_Min );
  // C_Position  = map(C_PotValue, 0, 1023, C_Max , C_Min );
  // D_Position  = map(D_PotValue, 0, 1023, D_Min , D_Max);
  A.write(A_Position);
  Serial.print("valore di A  ");
  Serial.println(A_Position);
  
  B.write(B_Position);
  Serial.print("valore di B  ");
  Serial.println(B_Position);
  
  C.write(C_Position);
  Serial.print("valore di C  ");
  Serial.println(C_Position);
 
  D.write(D_Position);
  Serial.print("valore di D  ");
  Serial.println(D_Position);
  delay(20);
}
