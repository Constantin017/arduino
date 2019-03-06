byte redPin = 11;
byte bluePin = 10;
byte greenPin = 9;

byte _delay = 20;
int val;

void setup()
{

  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);

}

void loop()
{

  for(val=255; val>0; val--)
  {
    analogWrite(redPin, val);
    analogWrite(10, 255-val);
    analogWrite(9, 128-val);
    delay(_delay);
  }
  
  for(val=0; val<255; val++)
  {
    analogWrite(redPin, val);
    analogWrite(10, 255-val);
    analogWrite(9, 128-val);
    delay(_delay);
  }
  
  Serial.println(val, DEC);
}
