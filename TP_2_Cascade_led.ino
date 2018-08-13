#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
int LedBleu = 7;
int LedBlanc = 6;
int LedRouge = 5;
int LedJaune = 4;
int LedVert = 3;
int LedRouge2 = 2;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long Mesure;
int Data = 1;
int compteur = 0;

void setup() {
  for (int t = 2; t < 8; t++) {
    pinMode(t, OUTPUT);
    digitalWrite(t, LOW);
  }
  Serial.begin(9600);
}

void loop() {
  Mesure = sr04.Distance();
  //Serial.print(Mesure);
  //Serial.println("cm");
  //delay(1000);
  if (Mesure > 30) {
    Data = 7;
  }
  else if (Mesure > 25) {
    Data = 6;
  }
  else if (Mesure > 20) {
    Data = 5;
  }
  else if (Mesure > 15) {
    Data = 4;
  }
  else if (Mesure > 10) {
    Data = 3;
  }
  else if (Mesure > 5) {
    Data = 2;
  }
  else {
    Data = 1;
  }
  
  Action(Data);
 
}

void Action(int n) {
  if (n > compteur) {
    for (int t = 2; t < n+1; t++) {
      digitalWrite(t, HIGH);
      delay(10);
    }
  }

  else if (n < compteur) {
    while (compteur != n) {
      digitalWrite(compteur, LOW);
      compteur--;
      delay(10);
    }
  }
  else {
    return;
  }
  compteur = n;
  return;
}

