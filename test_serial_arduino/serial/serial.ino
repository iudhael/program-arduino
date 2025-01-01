#include <Servo.h> // Ou la bibliothèque pour votre moteur, selon votre type de moteur

Servo motor1;
Servo motor2;
int value1 = 0; 
int value2 =0;

void setup() {
  Serial.begin(38400); // Initialisation de la communication série
  motor1.attach(9);   // Pin pour le moteur 1
  motor2.attach(10);  // Pin pour le moteur 2
    pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readString(); // Lire les données reçues
    data.trim();                       // Nettoyer les espaces

    // Parse les données (ex: "90,120" pour deux angles de servo)
    int commaIndex = data.indexOf(',');
    if (commaIndex > 0) {
      value1 = data.substring(0, commaIndex).toInt();
       value2 = data.substring(commaIndex + 1).toInt();



      
    }
  }


      if (value1 == -900)
      {
        digitalWrite(13, LOW);
        }
        delay(1000);
      if (value2 == 120)
      {
        digitalWrite(13, HIGH);
        }
        delay(1000);

}
