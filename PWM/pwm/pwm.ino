int ledpin = 13;


void setup() {

  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, HIGH);

}

void loop() {

  delay(1000);
  digitalWrite(ledpin, LOW);
  delay(1000);
  digitalWrite(ledpin, HIGH);

}
