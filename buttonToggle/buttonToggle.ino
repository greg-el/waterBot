int inPin = 2;         
int outPin = 7;       

int state = HIGH;      
int reading;           
int previous = LOW;    


unsigned long time = 0;           
unsigned long debounce = 200UL;   
void setup() {
  pinMode(inPin,  INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  reading = digitalRead(inPin);
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH) {
      state = LOW;

    } else {
      state = HIGH;

    time = millis();
    }

  }
  digitalWrite(LED_BUILTIN, state);
  previous = reading;
}
