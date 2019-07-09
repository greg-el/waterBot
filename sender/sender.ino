#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

int inPin = 2;         
int outPin = 7;       

int state = HIGH;      
int reading;           
int previous = LOW;    
int message;
unsigned long time = 0;           
unsigned long debounce = 200UL;   

void setup() {
  pinMode(inPin,  INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
  mySwitch.setPulseLength(400);
  mySwitch.setProtocol(1);  
}

void loop() {
  reading = digitalRead(inPin);
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH) {
      state = LOW;
      message = 69;
    } else {
      state = HIGH;
      message = 420;
      time = millis(); 
    }
  }
  digitalWrite(LED_BUILTIN, state);
  digitalWrite(outPin, state);
  mySwitch.send(message, 24);
  previous = reading;
}
