//un afficheur 7 segments avec des servos-moteurs (afficheur 7servo)
#include <Servo.h>

#define nbreServo 7
Servo Servo7[nbreServo];

#define L 10 // 10 lignes
int data[L][nbreServo] = {
  {90, 90, 90, 90, 90, 90,0},   //0

  {0, 90, 90, 0, 0, 0, 0},      //1

  {90, 90, 0, 90, 90, 0, 90},   //2

  {90, 90, 90, 90, 0, 0, 90},   //3

  {0, 90, 90, 0, 0, 90, 90},    //4

  {90, 0, 90, 90, 0, 90, 90},   //5

  {90, 0, 90, 90, 90, 90, 90},  //6

  {90, 90, 90, 0, 0, 0, 0},     //7

  {90, 90, 90, 90, 90, 90, 90}, //8

  {90, 90, 90, 90, 0, 90, 90},  //9
};

unsigned long previousTime = 0;

int i = 0;

void setup() {

  Serial.begin(9600);


  for (int i = 0; i < nbreServo; i++)
  {
    Servo7[i].attach(i + 2);
    Servo7[i].write(0);
  }

}

void loop() {
  unsigned long currentTime = millis();


  if(currentTime - previousTime >= 1000)
  {
    Serial.println(i);
    for (int j = 0; j < nbreServo; j++)
    {
      Servo7[j].write(data[i][j]);
    }
    //Serial.println("t");
    previousTime = currentTime;
    
    i++;
    if (i ==L){
      i = 0;

    }
  }
}
