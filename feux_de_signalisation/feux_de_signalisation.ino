
/* 2 feux de signalisation*/

const int led_rouge_feux_1 = 2;
const int led_jaune_feux_1 = 3;
const int led_verte_feux_1 = 4;

const int led_rouge_feux_2 = 5;
const int led_jaune_feux_2 = 6;
const int led_verte_feux_2 = 7;


void setup() {
  // put your setup code here, to run once:
  // initialisation en sortie de toutes les broches
  pinMode(led_rouge_feux_1, OUTPUT);
  pinMode(led_jaune_feux_1, OUTPUT);
  pinMode(led_verte_feux_1, OUTPUT);
  
  pinMode(led_rouge_feux_2, OUTPUT);
  pinMode(led_jaune_feux_2, OUTPUT);
  pinMode(led_verte_feux_2, OUTPUT);

  // initialisation de l'etat des led allumee ou eteinte
  digitalWrite(led_rouge_feux_1, LOW);
  digitalWrite(led_jaune_feux_1, HIGH);
  digitalWrite(led_verte_feux_1, HIGH);


  digitalWrite(led_rouge_feux_2, LOW);
  digitalWrite(led_jaune_feux_2, HIGH);
  digitalWrite(led_verte_feux_2, HIGH);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  // première séquence
 digitalWrite(led_rouge_feux_1, HIGH);
 digitalWrite(led_verte_feux_1, LOW);

 delay(3000);

 // deuxième séquence
  digitalWrite(led_verte_feux_1, HIGH);
  digitalWrite(led_jaune_feux_1, LOW);

  delay(2000);

  // troisième séquence
  digitalWrite(led_jaune_feux_1, HIGH);
  digitalWrite(led_rouge_feux_1, LOW);

  delay(2000);

  /* deuxième partie du programme, on s'occupe du feux numéro 2*/

  // première séquence
  digitalWrite(led_rouge_feux_2, HIGH);
  digitalWrite(led_verte_feux_2, LOW);

  delay(3000);

  // deuxième séquence
  digitalWrite(led_verte_feux_2, HIGH);
  digitalWrite(led_jaune_feux_2, LOW);

  delay(2000);

  // deuxième séquence
  digitalWrite(led_jaune_feux_2, HIGH);
  digitalWrite(led_rouge_feux_2, LOW);

  delay(2000);






}
