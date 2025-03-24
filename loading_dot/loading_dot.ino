#include <LiquidCrystal_I2C.h>

  // Ecran ----------------------------------------------------------------
  LiquidCrystal_I2C lcd(0x27, 20, 4);

  unsigned long previousTime = 0;
  int i = 0;
  void setup() {
  Serial.begin(9600);  // Initialiser la communication série


  lcd.init();
  lcd.backlight();


  }

  void loop() {
  const String spinner[] = {".", "..", "..."};  // Animation de chargement
  const int spinnerLength = sizeof(spinner) / sizeof(spinner[0]);
  unsigned long currentTime = millis();

  lcd.setCursor(9, 2);         // Positionner le curseur au début de la 1ère ligne



  if (currentTime - previousTime >= 200)
  {


    // Retour au début de la ligne
    lcd.print(spinner[i]);    // Affiche le caractère actuel
    //delay(200);                  // Pause pour l'animation


    previousTime = currentTime;

    i++;
    if (i == 4)
    {
      i = 0;
    lcd.clear();

    }

  }

  }
