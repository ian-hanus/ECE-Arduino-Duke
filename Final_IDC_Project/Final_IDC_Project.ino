#include <Servo.h>
#include <SoftwareSerial.h>
#include<LiquidCrystal.h>

#define Rx 19 //Recieving XBee Pin
#define Tx 18 // Transmitting XBee Pin
#define NOTE_B0  31 // Musical notes for song
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define melodyPin 5

int melody[] = { //song melody
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

Servo servoL;
Servo servoR;

SoftwareSerial lcd(5, 18);

const int ledPinOut =  12;      // the number of the LED pin outgoing
const int ledPinIn = 13; // the number of the LED pin incoming

void setup() {
  // put your setup code here, to run once:
  lcd.begin(9600);
  Serial.begin(9600);
  Serial1.begin(9600);
  servoL.attach(12);
  servoR.attach(13);
  pinMode(10, INPUT); //Left Line-Follow QTI
  pinMode(9, INPUT); //Center Line-Follow QTI
  pinMode(8, INPUT); //Right Line-Follow QTI
  pinMode(6, INPUT); // Sensor QTI
  pinMode(5, OUTPUT); 
  pinMode(4, OUTPUT); // Yellow sensing LED
  pinMode(3, OUTPUT); // Red sensing LED
  pinMode(11, OUTPUT); // Green light show LED 
  pinMode(7, OUTPUT);  // Red light show LED
  pinMode(ledPinOut, OUTPUT); // Outgoing Communication Pin
  pinMode(ledPinIn, OUTPUT); // Incoming Communication Pin
}

void loop() {
  // put your main code here, to run repeatedly:
  long right = rcTime(10);
  long center = rcTime(9);
  long left = rcTime(8);
  Serial.print("right= ");
  Serial.println(right);
  Serial.print("center= ");
  Serial.println(center);
  Serial.print("left= ");
  Serial.println(left);
  long thresh = 340;
  int i = 0;

  if (left < thresh && center > thresh && right < thresh) {
    servoL.writeMicroseconds(1580);
    servoR.writeMicroseconds(1420);
    delay(20);
  }
  else if (left < thresh && center < thresh && right < thresh) {
    servoL.writeMicroseconds(1540);
    servoR.writeMicroseconds(1460);
    delay(10);
  }
  else if (left > thresh && center < thresh && right < thresh) {
    servoL.writeMicroseconds(1300);
    servoR.writeMicroseconds(1300);
    delay(100);
  }
  else if (left < thresh && center < thresh && right > thresh) {
    servoL.writeMicroseconds(1700);
    servoR.writeMicroseconds(1700);
    delay(100);
  }
  else if (left > thresh && center > thresh && right < thresh) {
    servoL.writeMicroseconds(1420);
    servoR.writeMicroseconds(1420);
    delay(100);
  }
  else if (left < thresh && center > thresh && right > thresh) {
    servoL.writeMicroseconds(1580);
    servoR.writeMicroseconds(1580);
    delay(100);
  }
  else if (left > thresh && center > thresh && right > thresh) {
    servoL.writeMicroseconds(1500);
    servoR.writeMicroseconds(1500);
    delay(1000);
    servoL.writeMicroseconds(1400);
    servoR.writeMicroseconds(1600);
    delay(400);
    servoL.writeMicroseconds(1700);
    servoR.writeMicroseconds(1500);
    delay(1200);
    servoL.writeMicroseconds(1500);
    servoR.writeMicroseconds(1500);
    delay(100);
    servoL.writeMicroseconds(1600);
    servoR.writeMicroseconds(1400);
    delay(950);
    servoL.writeMicroseconds(1500);
    servoR.writeMicroseconds(1500);
    i = 1;
    int myscore = 0;
    delay(1000);

    while (i < 4) {
      long sensor = rcTime(6);
      Serial.print("sensor QTI = ");
      Serial.println(sensor);
      if (sensor > 900 && sensor < 1400) {
        //digitalWrite(3, HIGH);
        //digitalWrite(4, LOW);
        Serial.print("Duck"); // yellow only
        myscore = 'c';
      }
      else if (sensor < 900) {
        //digitalWrite(3, LOW);
        //digitalWrite(4, HIGH);
        Serial.print("Pencil");//red only
        myscore = 'b';
      }
      else if (sensor > 1400) {
        //digitalWrite(3, HIGH);
        //digitalWrite(4, HIGH);
        Serial.print("Eight Ball"); //red and yellow
        myscore = 'a';
      }
      else {
        //digitalWrite(3, LOW);
        //digitalWrite(4, LOW);
        Serial.print("Nothing");
      }
      delay(200);
      char outgoing = myscore;
      Serial1.print(outgoing);
      delay(100);
      Serial1.print(outgoing);
      delay(100);
      Serial1.print(outgoing);
      delay(10);
      servoL.writeMicroseconds(1500);
      servoR.writeMicroseconds(1500);
      int incoming;

      while (1) {
        receive();
      }
    }
  }
}

void receive() {  // receiving score from sentry bot
  if (Serial1.available()) {
    char incoming = Serial1.read();
    Serial.println(incoming);
    if (incoming == '0') {  // if the modulus 3 is 0, turn red LED on and do a dance
      //tone(piezopin,1000,500);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      servoL.writeMicroseconds(1600);
      servoR.writeMicroseconds(1400);
      delay(500);
      servoL.writeMicroseconds(1500);
      servoR.writeMicroseconds(1500);
      delay(1000);
      servoL.writeMicroseconds(1450);
      servoR.writeMicroseconds(1550);
      delay(500);

      servoL.writeMicroseconds(1550);
      servoR.writeMicroseconds(1450);
      delay(1000);

      servoL.writeMicroseconds(1400);
      servoR.writeMicroseconds(1400);
      delay(920);

      servoL.writeMicroseconds(1600);
      servoR.writeMicroseconds(1600);
      delay(1004);

      servoL.writeMicroseconds(1500);
      servoR.writeMicroseconds(1500);
      delay(250);
      servoL.writeMicroseconds(1600);
      servoR.writeMicroseconds(1400);
      delay(860);

      servoL.writeMicroseconds(1420);
      servoR.writeMicroseconds(1420);
      delay(600);

      servoL.writeMicroseconds(1580);
      servoR.writeMicroseconds(1580);
      delay(750);

      servoL.writeMicroseconds(1450);
      servoR.writeMicroseconds(1450);
      delay(3000);

      servoL.writeMicroseconds(1500);
      servoR.writeMicroseconds(1500);
      delay(25000);

    }
    if (incoming == '1') { // if the modulus 3 is a one, turn yellow LED on and blink the red one repeatedly
      //tone(piezopin,1000,500)
      digitalWrite(7, LOW);
      digitalWrite(11, HIGH);
      Serial1.println ("q");
      delay(5000);
      int i = 1;
      while ( i < 300 ) {
        digitalWrite(7, HIGH);
        digitalWrite(11, HIGH);
        delay(100);
        digitalWrite(7, LOW);
        delay(100);
        digitalWrite(11, LOW);
        digitalWrite(7, HIGH);
        delay(100);
        i =  i + 1;
      }
    }
    if (incoming == '2') { // if the modulus 3 is a two, turn both LEDs on and sing the Mario theme song
      //tone(piezopin,1000,500);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      Serial1.println ("r");
      sing(1);
      sing(1);
      sing(2);
      delay(5000);
    }
  }
}

int song = 0;
void sing(int s) {  //code for singing the Mario song
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(melodyPin, underworld_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }

  } else {

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  }
}


void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);

}

long rcTime(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(5);
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW);
  long time = micros();
  while (digitalRead(pin));
  time = micros() - time;
  return time;
  delay(1000000);
}

