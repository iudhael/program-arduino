#include <SoftwareSerial.h>
//int rxd=1, txd=0;
//2 est le rx de l'arduino et 3 son tx
int rxd=3, txd=2;
SoftwareSerial Serialhc05(txd, rxd);

String msg;
String Incoming_value;

void setup() {
  pinMode(13, OUTPUT);
  //Serial.println("ENTER AT Commands:");
  Serialhc05.begin(9600);
  Serial.begin(9600);
}
void loop() {
  readSerialPort();

  if (Serialhc05.available()) {
    
    Serial.write(Serialhc05.read());
    Serial.println("t");
  }

}
void readSerialPort() {
  msg = "";

    delay(10);
    if (Serialhc05.available() > 0) {
      char c = Serialhc05.read();  //gets one byte from serial buffer
      msg += c;
      

      Incoming_value = msg;

      Serial.println("incoming_value : "+ Incoming_value);
      Serial.println("msg : "+ msg);
      
      if (Incoming_value == "1")
        digitalWrite(13, HIGH);
      else if (Incoming_value == "0")
        digitalWrite(13, LOW);

    }
  
}