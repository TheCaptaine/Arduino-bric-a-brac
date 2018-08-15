#define latchPin 11
#define clockPin 9
#define dataPin 12
#define LedBlue 8
#define LedGreen 7
#define LedRed 6
#define attente 50

byte leds = 0;
int BlueValue;
int GreenValue;
int RedValue;

void setup() {
  for(int t = 6; t < 9; t++) {
    pinMode(t, OUTPUT);
    digitalWrite(t, HIGH);
    if (t == 7) {
      digitalWrite(t, LOW);
    }
  }
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int t = 0; t < 7; t++) {
    Prin();
  }
  
  for(int y = 0; y < 2; y++) {
    for(int t = 0; t < 22; t++) {
      MAJ(0, HIGH);
      MAJ(7, HIGH);
      delay(50);
      MAJ(3, HIGH);
      MAJ(4, HIGH);
      delay(50);
      MAJ(3, LOW);
      MAJ(4, LOW);
      delay(50);
      MAJ(0, LOW);
      MAJ(7, LOW);
    }
    for(int t = 0; t < 21; t++) {
      MAJ2(255);
      MAJ2(0);
    }
  }
  for(int y = 0; y < 4; y++) {
    for(int t = 0; t < 5; t++) {
      Prin();
    }
    for(int t = 0; t < 20; t++) {
        MAJ2(255);
        MAJ2(0);
      }
      if (y == 3) {
          for(int t = 0; t < 3; t++) {
        Prin();
      }
      for(int t = 0; t < 17; t++) {
          MAJ2(255);
          MAJ2(0);
        }
      }
  }
}

void MAJ(int desiredPin, boolean desiredState) {
  bitWrite(leds,desiredPin,desiredState);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void MAJ2(byte n) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, n);
  digitalWrite(latchPin, HIGH);
  delay(100);
}

void Prin() {
  for(int t = 0; t < 8; t++) {
      MAJ(t, HIGH);
      delay(attente);
      MAJ(t, LOW);
    }
    for(int t = 7; t >= 0; t--) {
    MAJ(t, HIGH);
    delay(attente);
    MAJ(t, LOW);
    }
}
