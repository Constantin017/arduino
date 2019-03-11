int dataPin = 2;
int clockPin = 5;
int latchPin = 4;
int ledState = 2;

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop()
{

  for(int i=0;i<256;i++){
    ledState = i;
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ledState);
    digitalWrite(latchPin, HIGH);
    delay(1000);  
  }
  
}
