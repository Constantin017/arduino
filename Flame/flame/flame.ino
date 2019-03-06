byte ctlPin = 13;
int flame = 0;
int beepPin = 9;
int val = 0;

void setup()
{

  pinMode(ctlPin, OUTPUT);
  pinMode(beepPin, OUTPUT);
  pinMode(flame, INPUT);
  pinMode(beepPin, OUTPUT);
  
}

void loop()
{

  val = analogRead(flame);
  Serial.println(val);

  if ( val >= 600 ){
    digitalWrite(beepPin, HIGH);
    digitalWrite(ctlPin, LOW);
  }
  else
  {
    digitalWrite(ctlPin, HIGH);
    digitalWrite(beepPin, LOW);  
  }
  delay(500);
  
}

