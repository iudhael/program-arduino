//un afficheur 7 segments avec des servos-moteurs (afficheur 7servo)

#include <Servo.h>

#define nbreServo 7


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();

#define SERVOMIN 125
#define SERVOMAX 625


#define L 10 // 10 lignes
int data[L][nbreServo] = {
  {SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2,SERVOMIN},   //0

  {SERVOMIN, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMIN, SERVOMIN, SERVOMIN},      //1

  {SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMAX/2},   //2

  {SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMIN, SERVOMAX/2},   //3

  {SERVOMIN, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMIN, SERVOMAX/2, SERVOMAX/2},    //4

  {SERVOMAX/2, SERVOMIN, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMAX/2, SERVOMAX/2},   //5

  {SERVOMAX/2, SERVOMIN, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2},  //6

  {SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMIN, SERVOMIN, SERVOMIN},     //7

  {SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2}, //8

  {SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMAX/2, SERVOMIN, SERVOMAX/2, SERVOMAX/2},  //9
};

unsigned long previousTime = 0;

int i = 0;




void setup() {

  Serial.begin(9600);
  myServo.begin();
  myServo.setPWMFreq(60);


  for (int i = 0; i < nbreServo; i++)
  {
     myServo.setPWM(i, 0, SERVOMIN);

  }


 
}

void loop() {
  unsigned long currentTime = millis();



  if(currentTime - previousTime >= 1000)
  {
    Serial.println(i);
    for (int j = 0; j < nbreServo; j++)
    {
      myServo.setPWM(j, 0, data[i][j]);

    }
    //Serial.println("t");
    previousTime = currentTime;
    
    i++;
    if (i ==L){
      i = 0;

    }
  }


 


}
