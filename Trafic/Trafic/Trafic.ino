byte redLedPin = 10;
byte yelloLedPin = 7;
byte greenLedPin = 4;

byte ownPin = 13;

void setup() {

  pinMode(ownPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yelloLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

}

void loop() {

  digitalWrite(ownPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
  delay(1000);
  digitalWrite(ownPin, LOW);
  digitalWrite(greenLedPin, LOW);

  for (byte i = 0; i < 3; i++)
  {
    delay(500);
    digitalWrite(ownPin, HIGH);
    digitalWrite(yelloLedPin, HIGH);
    delay(500);
    digitalWrite(ownPin, LOW);
    digitalWrite(yelloLedPin, LOW);
  }

  delay(500);
  digitalWrite(redLedPin, HIGH);
  delay(1000);
  digitalWrite(redLedPin, LOW);

}
