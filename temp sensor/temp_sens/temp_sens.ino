byte ctlPin = 13;
int potPin = 0;
int val;
int dat;

void setup()
{

  pinMode(ctlPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{

  val = analogRead(0);
  dat = (125 * val) >> 8;
  
  Serial.print("Tep: ");
  Serial.print(dat);
  Serial.println("C");

  if ( dat > 20 ){
    digitalWrite(ctlPin, HIGH);
  }
  
  delay(500);
}
