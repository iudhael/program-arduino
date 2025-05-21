// allumage de 6 led led

String cmd1 = "", cmd2 =  "", cmd3 =  "", R0 = "",  R1 =  "", R2 =  "", R3 =  "",  R4 = "", R5 = "";

float R0_value = 0, R1_value = 0, R2_value = 0, R3_value = 0, R4_value = 0, R5_value = 0;


void setup() {
  Serial.begin(38400); // Initialisation de la communication série


  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  axeValues();



  // Allumer/Éteindre les LEDs
  // Allumer/Éteindre les LEDs
  digitalWrite(13, R0_value == 40.00 ? HIGH : (R0_value == -40.00 ? LOW : digitalRead(13)));
  digitalWrite(12, R1_value == 40.00 ? HIGH : (R1_value == -40.00 ? LOW : digitalRead(12)));
  digitalWrite(11, R2_value == 40.00 ? HIGH : (R2_value == -40.00 ? LOW : digitalRead(11)));
  digitalWrite(10, R3_value == 40.00 ? HIGH : (R3_value == -40.00 ? LOW : digitalRead(10)));
  digitalWrite(9, R4_value == 40.00 ? HIGH : (R4_value == -40.00 ? LOW : digitalRead(9)));
  digitalWrite(8, R5_value == 40.00 ? HIGH : (R5_value == -40.00 ? LOW : digitalRead(8)));

  /*if (R0_value == 40.00)
    {
    digitalWrite(13, 1);
    }
    else if (R0_value == -40.00)
    {
    digitalWrite(13, 0);
    }

    if (R1_value == 40.00)
    {
    digitalWrite(12, 1);
    }
    else if (R1_value == -40.00)
    {
    digitalWrite(12, 0);
    }

    if (R2_value == 40.00)
    {
    digitalWrite(11, 1);
    }
    else if (R2_value == -40.00)
    {
    digitalWrite(11, 0);
    }



    if (R3_value == 40.00)
    {
    digitalWrite(10, 1);
    }
    else if (R3_value == -40.00)
    {
    digitalWrite(10, 0);
    }


    if (R4_value == 40.00)
    {
    digitalWrite(9, 1);
    }
    else if (R4_value == -40.00)
    {
    digitalWrite(9, 0);
    }


    if (R5_value == 40.00)
    {
    digitalWrite(8, 1);
    }
    else if (R5_value == -40.00)
    {
    digitalWrite(8, 0);
    }*/







}

void axeValues()
{
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\r'); // Lire les données reçues
    data.trim();                       // Nettoyer les espaces

    // Permet de chercher l'espace à partir de l'indice prciser idx1+1 Avec idx1+1 don cherche l'espace à l'indice idx1+1
    // le +11 est ajouter pur ignorer l'espace à l'indice idx1
    int idx1 = data.indexOf(' ');
    int idx2 = data.indexOf(' ', idx1 + 1);
    int idx3 = data.indexOf(' ', idx2 + 1);
    int idx4 = data.indexOf(' ', idx3 + 1);
    int idx5 = data.indexOf(' ', idx4 + 1);

    int idx6 = data.indexOf(' ', idx5 + 1);
    int idx7 = data.indexOf(' ', idx6 + 1);
    int idx8 = data.indexOf(' ', idx7 + 1);
    int idx9 = data.indexOf(' ', idx8 + 1);
    int idx10 = data.indexOf(' ', idx9 + 1);
    int idx11 = data.indexOf(' ', idx10 + 1);
    int idx12 = data.indexOf(' ', idx11 + 1);
    int idx13 = data.indexOf(' ', idx12 + 1);
    int idx14 = data.indexOf(' ', idx13 + 1);


    // Extraire les valeurs
    if (idx1 > 0 && idx2 > 0 && idx3 > 0 && idx4 > 0 && idx5 > 0 && idx6 > 0 && idx7 > 0 && idx8 > 0 && idx9 > 0 && idx10 > 0 && idx11 > 0 && idx12 > 0 && idx13 > 0 && idx14 > 0 ) {
      //ici on recupere les caracteres se trouvant entre les indice preciser
      cmd1 = data.substring(0, idx1);
      cmd2 = data.substring(idx1 + 1, idx2) ;
      cmd3 = data.substring(idx2 + 1, idx3);

      R0 = data.substring(idx3 + 1, idx4);
      R0_value = data.substring(idx4 + 1, idx5).toFloat();

      R1 = data.substring(idx5 + 1, idx6);
      R1_value = data.substring(idx6 + 1, idx7).toFloat();

      R2 = data.substring(idx7 + 1, idx8);
      R2_value = data.substring(idx8 + 1, idx9).toFloat();

      R3 = data.substring(idx9 + 1, idx10);
      R3_value = data.substring(idx10 + 1, idx11).toFloat();

      R4 = data.substring(idx11 + 1, idx12);
      R4_value = data.substring(idx12 + 1, idx13).toFloat();

      R5 = data.substring(idx13 + 1, idx14);
      R5_value = data.substring(idx14 + 1).toFloat();



      Serial.println("data : " + data);
      Serial.print("data R1 : "); Serial.println(R1_value);
      Serial.print("R0_value "); Serial.println(R0_value);
      Serial.print("R1_value "); Serial.println(R1_value);
      Serial.print("R2_value "); Serial.println(R2_value);
      Serial.print("R3_value "); Serial.println(R3_value);
      Serial.print("R4_value "); Serial.println(R4_value);
      Serial.print("R5_value "); Serial.println(R5_value);

    }

  }
}
