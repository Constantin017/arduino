byte BASE = 2;
byte NUM = 6;

byte ownPin = 13;

void setup()
{

  for (int i = BASE; i < BASE + NUM; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(ownPin, OUTPUT);
}

void loop()
{

  digitalWrite(ownPin, LOW);
  for(int i = BASE; i< BASE + NUM; i++)
  {
    digitalWrite(i, LOW);
    delay(200);  
  }

  digitalWrite(ownPin, HIGH);
  for(int i = BASE; i< BASE + NUM; i++)
  {
    digitalWrite(i, HIGH);
    delay(200);  
  }

  
}
