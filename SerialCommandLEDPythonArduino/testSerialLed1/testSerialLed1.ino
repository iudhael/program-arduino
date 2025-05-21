//marche bien
// allumage de 6 leds


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
  static String buffer = ""; // Stocke les données reçues
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\r') { // Fin des données
      processData(buffer); // Traiter les données reçues
      buffer = ""; // Réinitialiser le buffer
    } else {
      buffer += c; // Ajouter le caractère au buffer
    }
  }
}

void processData(String data) {
  // Extraire les valeurs
  int values[15] = {0};
  int idx = 0;
  char *token = strtok(data.c_str(), " ");
  while (token != nullptr && idx < 15) {
    values[idx++] = atof(token); //atof pour une conversion en float de token
    token = strtok(nullptr, " ");
  }

  // Assigner les valeurs
  if (idx == 15) {
    cmd1 = String(values[0]);
    cmd2 = String(values[1]);
    cmd3 = String(values[2]);
    R0 = String(values[3]);
    R0_value = values[4];
    R1 = String(values[5]);
    R1_value = values[6];
    R2 = String(values[7]);
    R2_value = values[8];
    R3 = String(values[9]);
    R3_value = values[10];
    R4 = String(values[11]);
    R4_value = values[12];
    R5 = String(values[13]);
    R5_value = values[14];

    // Allumer/Éteindre les LEDs
    digitalWrite(13, R0_value == 40.00 ? HIGH : (R0_value == -40.00 ? LOW : digitalRead(13)));
    digitalWrite(12, R1_value == 40.00 ? HIGH : (R1_value == -40.00 ? LOW : digitalRead(12)));
    digitalWrite(11, R2_value == 40.00 ? HIGH : (R2_value == -40.00 ? LOW : digitalRead(11)));
    digitalWrite(10, R3_value == 40.00 ? HIGH : (R3_value == -40.00 ? LOW : digitalRead(10)));
    digitalWrite(9, R4_value == 40.00 ? HIGH : (R4_value == -40.00 ? LOW : digitalRead(9)));
    digitalWrite(8, R5_value == 40.00 ? HIGH : (R5_value == -40.00 ? LOW : digitalRead(8)));






  }
  Serial.print("Nombre de valeurs reçues : "); Serial.println(idx);
  Serial.print("R0_value "); Serial.println(R0_value);
  Serial.print("R1_value "); Serial.println(R1_value);
  Serial.print("R2_value "); Serial.println(R2_value);
  Serial.print("R3_value "); Serial.println(R3_value);
  Serial.print("R4_value "); Serial.println(R4_value);
  Serial.print("R5_value "); Serial.println(R5_value);
}
