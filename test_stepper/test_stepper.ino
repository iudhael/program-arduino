#include <AccelStepper.h>
// Stepper M----------------------------------------------------------------
int setepperMStep = 7;
int setepperMDir = 6;
AccelStepper setepperM(1, setepperMStep, setepperMDir);  // 1 pour A4988
float motorMSpeed = 10;
float  maxSpeed = 10000.0;

// Stepper D----------------------------------------------------------------
int setepperDStep = 11;
int setepperDDir = 10;
AccelStepper setepperD(1, setepperDStep, setepperDDir);  // 1 pour A4988

void setup() {
  // put your setup code here, to run once:
  setepperM.setMaxSpeed(maxSpeed);
  setepperM.setAcceleration(5000.0);


  setepperD.setMaxSpeed(maxSpeed);
  setepperD.setAcceleration(5000.0);
}

void loop() {
  // put your main code here, to run repeatedly:
    setepperM.setSpeed(100);
    setepperD.setSpeed(100);

    setepperM.run();
    setepperD.run();
}
