int servoPin = 9;
int pulseWidth;

void setup() {

  pinMode(servoPin, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  pulseWidth = random(500, 2480);

  digitalWrite(servoPin, HIGH);
  
  delayMicroseconds(pulseWidth);
  
  digitalWrite(servoPin, LOW);
  
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  

}
