
void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(LED_BUILTIN, HIGH);
  
}


void loop() {

  digitalWrite(LED_BUILTIN, LOW);
  
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(5000);

}
