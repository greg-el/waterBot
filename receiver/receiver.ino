#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
       
int outPin = 7;        

void setup() {
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
  mySwitch.enableReceive(0); //Pin 2
}

void loop() {
  if (mySwitch.available()) {
    Serial.print(mySwitch.getReceivedValue());
    Serial.print("\n");
    Serial.print(mySwitch.getReceivedBitlength());
    Serial.print("\n");
    Serial.print(mySwitch.getReceivedDelay());
    Serial.print("\n");
    //Serial.print(mySwitch.getReceivedRawdata());
    //Serial.print("\n");
    Serial.print(mySwitch.getReceivedProtocol());
    Serial.print("\n");
    if (mySwitch.getReceivedValue() == 420) {
      digitalWrite(outPin, HIGH);
      Serial.print("on");
    }
    if (mySwitch.getReceivedValue() == 69) {
      digitalWrite(outPin, LOW);
      Serial.print("off");
    }
    mySwitch.resetAvailable();
  }
}
