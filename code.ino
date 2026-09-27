const int buzzerPin = 8; // Buzzer pin

// array for the 6 LED pins
const int ledPins[] = {7, 6, 5, 4, 3, 2};
const int numLeds = 6;

#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_F5  698

void setup() {
  pinMode(buzzerPin, OUTPUT);
  
  // setup all pins from the array as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  playJingleBells();
  
  // Turn off all LEDs during a very short reset
  allLedsOff();
  delay(100); 
}

// the actual song
void playJingleBells() {
  // "Jingle bells, jingle bells..."
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_E5, 400); delayWithLed(200);
  
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_E5, 400); delayWithLed(200);
  
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_G5, 200); delayWithLed(100);
  playNote(NOTE_C5, 250); delayWithLed(100);
  playNote(NOTE_D5, 150); delayWithLed(100);
  playNote(NOTE_E5, 600); delayWithLed(400);

  // "Oh what fun it is to ride..."
  playNote(NOTE_F5, 200); delayWithLed(100); 
  playNote(NOTE_F5, 200); delayWithLed(100);
  playNote(NOTE_F5, 200); delayWithLed(100);
  playNote(NOTE_F5, 200); delayWithLed(100);
  playNote(NOTE_F5, 200); delayWithLed(100);
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_E5, 100); delayWithLed(50);
  playNote(NOTE_E5, 100); delayWithLed(50);
  
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_D5, 200); delayWithLed(100);
  playNote(NOTE_D5, 200); delayWithLed(100);
  playNote(NOTE_E5, 200); delayWithLed(100);
  playNote(NOTE_D5, 400); delayWithLed(200);
  playNote(NOTE_G5, 400); delayWithLed(200);
}

//we are not playing the full song


// this plays the note and lights up a specific LED
// the variable keeps track of which LED is next
int currentLedTrack = 0; 

void playNote(int noteFrequency, int duration) {
  allLedsOff(); 

  // light up current LED in the cycle
  digitalWrite(ledPins[currentLedTrack], HIGH);

  //move to the next LED
  currentLedTrack = (currentLedTrack + 1) % numLeds;

  tone(buzzerPin, noteFrequency, duration);
  delay(duration); 
}



void delayWithLed(int duration) {
  // flash 6th LED on pauses
  if (duration >= 200) {
    allLedsOff();
    digitalWrite(ledPins[5], HIGH); 
  } else {
    allLedsOff();
  }
  delay(duration);
}

// turns all lights off
void allLedsOff() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
