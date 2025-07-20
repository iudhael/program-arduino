//#include <SoftPWM.h>

//#define ENA A0  // Broche PWM
int ENA = 10;
int IN1 = 5;  // Direction
int IN2 = 6;   // Direction

void setup() {
    //SoftPWMBegin(); // Initialise SoftPWM
    //SoftPWMSet(ENA, 0); // Met le moteur à l'arrêt
    //pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
}

void loop() {
    
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    //SoftPWMSet(ENA, 255); 
    analogWrite(ENA, 255);

    //delay(20000); // Attendre 3 secondes

        // Arrêter le moteur
    //SoftPWMSet(ENA, 0);
    //delay(10000);

    
    //digitalWrite(IN1, LOW);
    //digitalWrite(IN2, HIGH);
    //SoftPWMSet(ENA, 250); 
    //analogWrite(ENA, 250);

    //delay(20000); // Attendre 3 secondes


}
