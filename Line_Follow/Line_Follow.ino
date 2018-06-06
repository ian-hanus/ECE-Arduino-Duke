#include <Servo.h>

Servo servoL;
Servo servoR;

void setup() {
  Serial.begin(9600);
  servoL.attach(12);
  servoR.attach(13);
  pinMode(10, INPUT); //LEFT
  pinMode(9, INPUT); //CENTER
  pinMode(8, INPUT); //RIGHT
}

long rcTime(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin,HIGH);
  delay(5);
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW);
  long time = micros();
  while(digitalRead(pin));
  time = micros() - time;
  return time;
}

void loop() {
  
  long right = rcTime(10);
  long center = rcTime(9);
  long left = rcTime(8);
  Serial.print("right= ");
  Serial.println(right);
  Serial.print("center= ");
  Serial.println(center);
  Serial.print("left= ");
  Serial.println(left);
  long thresh = 275;
  
  if (left < thresh && center > thresh && right < thresh) {
    servoL.writeMicroseconds(1700);
    servoR.writeMicroseconds(1300);
    delay(20);
  }
  else if (left < thresh && center < thresh && right < thresh) {
    servoL.writeMicroseconds(1600);
    servoR.writeMicroseconds(1400);
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
  else if (left > thresh && center > thresh && right > thresh) {
    servoL.writeMicroseconds(1500);
    servoR.writeMicroseconds(1500);
    delay(1000);
    servoL.writeMicroseconds(1700);
    servoR.writeMicroseconds(1300);
    delay(200);
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
}


