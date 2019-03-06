byte ctlpin = 13;
byte ledpin = 11;
byte buttonpin = 7;
int val;

void setup()
{

  pinMode(ctlpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);

}

void loop()
{

  val = digitalRead(buttonpin);

  if (val == LOW)
  {
    digitalWrite(ledpin, LOW);
    digitalWrite(ctlpin, HIGH);
  }
  else
  {
    digitalWrite(ledpin, HIGH);
    digitalWrite(ctlpin, LOW);
  }

}
