#define Rx 19
#define Tx 18
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPinOut =  9;      // the number of the LED pin outgoing
const int ledPinIn = 5; // the number of the LED pin incoming
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinOut, OUTPUT);
  pinMode(ledPinIn, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin (9600); // Se t t o No l i n e ending ;
  Serial1.begin (9600); // type a char , then h i t e n t e r
  delay(500) ;
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPinOut, HIGH);
    char outgoing = 'v' ; // Read c h a r a c t e r , send t o XBee
    Serial1.print (outgoing) ;
  }
    else {
    digitalWrite(ledPinOut,LOW);
    }
  if (Serial1.available ()) { // I s da ta a v a i l a b l e from XBee?
      char incoming = Serial1.read () ; // Read c h a r a c t e r ,
      Serial.println (incoming) ; // send t o S e r i a l Monitor
      if(incoming !='v'){
        digitalWrite(ledPinIn, HIGH);
        delay(300);
        digitalWrite(ledPinIn, LOW);
      }
      else {
        digitalWrite(ledPinIn, LOW);  //look up how to use digitalWrite function (Lab2 Manual)
      }
  }
      
    delay (50) ;
  }


