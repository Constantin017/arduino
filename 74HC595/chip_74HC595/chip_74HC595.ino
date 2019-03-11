int _data = 2;
int _clock = 5;
int _latch = 4;
int ledState = 0;

void setup()
{
  pinMode(_data, OUTPUT);
  pinMode(_clock, OUTPUT);
  pinMode(_latch, OUTPUT);
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop()
{

  delay(500);
  digitalWrite(13, HIGH);
  
  digitalWrite(_latch, LOW);
  shiftOut(_data, _clock, MSBFIRST, ledState);
  digitalWrite(_latch, HIGH);
  
  delay(500);
  digitalWrite(13, LOW);
  
}
