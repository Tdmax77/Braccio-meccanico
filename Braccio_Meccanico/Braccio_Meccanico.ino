/* Questo programma serve a pilotare un braccetto meccanico con 4 servomotori:
 *  ho implementato dei limiti di corsa per i vari movimenti ed in più ho messo una condizione 
 *  per la quale l'apertura della pinza funziona solo all'estremo del joystick e l'apertura della stessa 
 *  è bloccata se il braccio si sta muovendo 
 *  
 */

#include <Servo.h>
char tasto = 0;
int Servo_A_Pin = 11;
int Servo_B_Pin = 10;
int Servo_C_Pin = 9;
int Servo_D_Pin = 5;
int const Pin_A = A0; //  rotazione
int const Pin_B = A3; //  braccio sx
int const Pin_C = A2; //  braccio dx
int const Pin_D = A1; //  pinza

int Joy_A = 50; //rotazione
int Joy_B = 50; //braccio
int Joy_C = 50; //pinza
int Joy_D = 50; // braccio

Servo A;
Servo B;
Servo C;
Servo D;

int A_PotValue;
int A_Position;  //30-204
int B_PotValue;
int B_Position;  //85 -100
int C_PotValue;
int C_Position; //25 105
int D_PotValue;
int D_Position; //0 100

void setup()
{
  Serial.begin(9600);
  A.attach(Servo_A_Pin);
  B.attach(Servo_B_Pin);
  C.attach(Servo_C_Pin);
  D.attach(Servo_D_Pin);
  A_Position = 97;
  B_Position = 90;
  C_Position = 65;
  D_Position = 55;

}

void loop()
{
  tastiera();
  A_Position = constrain (A_Position, 30, 204);
  B_Position = constrain (B_Position, 85, 100);
  C_Position = constrain (C_Position, 25, 105);// servo  di destra, comando di destra
  D_Position = constrain (D_Position, 0, 100);
  A_PotValue  = analogRead(Pin_A);
  B_PotValue  = analogRead(Pin_B);
  C_PotValue  = analogRead(Pin_C);
  D_PotValue  = analogRead(Pin_D);
  Joy_A = map(A_PotValue, 0, 1023, 0 , 100);
  Joy_B = map(B_PotValue, 0, 1023, 0 , 100);
  Joy_C = map(C_PotValue, 0, 1023, 0 , 100);
  Joy_D = map(D_PotValue, 0, 1023, 0 , 100);


  if (Joy_A < 25) {                           //estremo muove +2
    A_Position = A_Position + 2;
  }
  else if ((Joy_A >= 25) && (Joy_A < 45)) {   //mezza corsa  muove +1
    A_Position = A_Position + 1;
  }
  else if ((Joy_A > 55) && (Joy_A < 75))  {   //mezza corsa  muove +1
    A_Position = A_Position - 1;
  }
  else if (Joy_A >= 75) {                     //estremo muove +2
    A_Position = A_Position - 2;
  }

//Impostazioni PINZA ******************
  
  if ((Joy_B < 1) && (Joy_C > 45) && (Joy_C < 55)) {
    B_Position = B_Position - 2;
  }
    else if ((Joy_B >= 100) && (Joy_C > 45) && (Joy_C < 55))  {
    B_Position = B_Position + 2;
  }
//Impostazioni PINZA ******************


  
  if (Joy_C < 25) {
    C_Position = C_Position - 2;
  }
  else if ((Joy_C >= 25) && (Joy_C < 45)) {
    C_Position = C_Position - 1;
  }
  else if ((Joy_C > 55) && (Joy_C < 75))   {
    C_Position = C_Position + 1;
  }
  else if (Joy_C >= 75) {
    C_Position = C_Position + 2;
  }


  
  if (Joy_D < 25) {
    D_Position = D_Position - 2;
  }
  else if ((Joy_D >= 25) && (Joy_D < 45)) {
    D_Position = D_Position - 1;
  }
  else if ((Joy_D > 55) && (Joy_D < 75))   {
    D_Position = D_Position + 1;
  }
  else if (Joy_D >= 75) {
    D_Position = D_Position + 2;
  }

  A.write(A_Position);  //Rotazione
  B.write(B_Position);
  C.write(C_Position);  //Pinza
  D.write(D_Position);

  delay(50);
}





void tastiera() {
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
}
