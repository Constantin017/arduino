#include <IRremote.h>

class Led{
private:
  byte pin;
  bool light;
  long value;
public:
  Led(byte p, long key){
    light = false;
    pin = p;
    value = key;
  }
  void check(long key){
    if ( value == key ){
      toggle(); 
    }
  }
  void toggle(){
    light = !light;
    action();
  }
  void on(){
    light = true;
    action();
  }
  void off(){
    light = false;
    action();
  }
  void action(){
    digitalWrite(pin, light ? HIGH : LOW);
  }
  void init()
  {
    pinMode(pin, OUTPUT);
  }
};

Led LED1(2, 0x00FF6897);
Led LED2(3, 0x00FF9867);
Led LED3(4, 0x00FFB04F);
Led LED4(5, 0x00FF30CF);
Led LED5(6, 0x00FF18E7);
Led LED6(7, 0x00FF7A85);

int on = 0;
int RECV_PIN = 11;

long turnOn = 0x00FF629D;

long toggle = 0x00FF02FD;

long turnOff = 0x00FFA857;

long toggleLeft = 0x00FF22DD;

long toggleRight = 0x00FFC23D;


unsigned long last = millis();

IRrecv irrecv(RECV_PIN);
decode_results results;

void dump(decode_results *results) {
  int count = results->rawlen;

  if (results->decode_type == UNKNOWN)
  {
    Serial.println("Could not decode message");
  }
  else
  {

    if (
      results->decode_type == NEC
      || results->decode_type == SONY
      || results->decode_type == RC5
      || results->decode_type == RC6
    ) {

      Serial.print("Decoded ");
      Serial.print(results->decode_type);
      Serial.print(" : ");
      Serial.print(results->value, HEX);
      Serial.print(" (");
      Serial.print(results->bits, DEC);
      Serial.println(" bits)");

    }

    Serial.print("Raw (");
    Serial.print(count, DEC);
    Serial.print("); ");

    for (int i = 0; i < count; i++)
    {
      if ( (i % 2) == 1 )
      {
        Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
      }
      else
      {
        Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
      }
      Serial.print("");
    }
    Serial.println("");
  }
}

void setup() {

  pinMode(13, OUTPUT);
  
  pinMode(RECV_PIN, INPUT);
  
  LED1.init();
  LED2.init();
  LED3.init();
  LED4.init();
  LED5.init();
  LED6.init();

  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {

  if ( irrecv.decode(&results) )
  {

    if ( millis() - last > 250 )
    {
      on = !on;
      digitalWrite(13, on ? HIGH : LOW);
      dump(&results);
    }

    if ( results.value == toggleLeft )
    {
      LED1.toggle();
      LED2.toggle();
      LED3.toggle();
    }

    if ( results.value == toggleRight )
    {
      LED4.toggle();
      LED5.toggle();
      LED6.toggle();
    }

    if ( results.value == turnOn )
    {
      LED1.on();
      LED2.on();
      LED3.on();
      LED4.on();
      LED5.on();
      LED6.on();
    }

    if ( results.value == turnOff )
    {
      LED1.off();
      LED2.off();
      LED3.off();
      LED4.off();
      LED5.off();
      LED6.off();
    }

    if ( results.value == toggle )
    {
      LED1.toggle();
      LED2.toggle();
      LED3.toggle();
      LED4.toggle();
      LED5.toggle();
      LED6.toggle();
    }

    LED1.check(results.value);
    LED2.check(results.value);
    LED3.check(results.value);
    LED4.check(results.value);
    LED5.check(results.value);
    LED6.check(results.value);
        
    last = millis();
    irrecv.resume();

  }

}
