int BoutonPoussoir = 10;
int LedRouge = 11;
boolean etat;


void setup() {
	pinMode(BoutonPoussoir, INPUT);
	pinMode(LedRouge, OUTPUT);
	Serial.begin(9600);
  etat = false;

}

void loop() {
  boolean lecture = digitalRead(BoutonPoussoir);
  
  if (lecture) {
    if (!etat) {
      etat = true;
    }
    else {
      etat = false;
    }
    delay(1000);
  }
     allumer(etat);
  
  
}

void allumer(boolean n) {
  if (n) {
     return digitalWrite(LedRouge, HIGH);
  
   }
  else {
  return digitalWrite(LedRouge, LOW);
  }
  }




