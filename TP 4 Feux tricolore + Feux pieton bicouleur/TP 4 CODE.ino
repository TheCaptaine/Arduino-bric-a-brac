#define latchPin 11
#define clockPin 9
#define dataPin 12
#define Button 10
#define DelayV 6000 
#define DelayO 1000
#define attente 50

long ends;
long timer;
byte leds;

void setup() {
  for(int t = 9; t < 13; t++) {
    pinMode(t, OUTPUT);
    if(t == 10) {
      pinMode(t, INPUT_PULLUP);
    }
  }
  Serial.begin(9600);
}

void loop() {
  Serial.println("sortie");
  for(int t = 7; t > 4; t--) {
    if (t == 6) {
      triche(t);
    }
    Maj(t, HIGH);
    if(t == 7) {
      Maj(4, LOW);
      Maj(3, HIGH);
      timer = millis();
      while ((millis() - timer < 6000) && (digitalRead(Button) == HIGH)) {
        ends = timer;
    }
    }
    
      Serial.println(millis() - ends);
      if(millis() - ends < 2000) {
        Serial.print("delay(1000);");
        delay(1000);
      }
      else if(millis() - ends < 3000) {
        Serial.print("delay(2000);");
        delay(2000);
      }
    else(t == 5); {
      delay(DelayO);
    }
    Maj(t, LOW);
  }
}


void Maj(int desiredPin, boolean desiredState) {
  bitWrite(leds, desiredPin, desiredState);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void triche(int n) {
  Maj(7, HIGH);
      Maj(3, LOW);
      Maj(4, HIGH);
      delay(1000);
      Maj(7, LOW);
      Maj(n, HIGH);
     return delay(DelayV);
}

