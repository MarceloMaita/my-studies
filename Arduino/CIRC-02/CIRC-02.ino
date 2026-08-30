//I've changed the CIRC-02 to make a Formula 1 starting procedure lights
//LED pin variables
int ledPins[] = {2, 3, 4, 5, 6};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i<5; i++){
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  oneAfterAnotherNoLoop();


}

void oneAfterAnotherNoLoop(){
  int delayTime = 1000;
  //lighting LED 01
  digitalWrite(ledPins[0], HIGH);
  delay(delayTime);

  //lighting LED 02
  digitalWrite(ledPins[1], HIGH);
  delay(delayTime);

  //lighting LED 03
  digitalWrite(ledPins[2], HIGH);
  delay(delayTime);

  //lighting LED 04
  digitalWrite(ledPins[3], HIGH);
  delay(delayTime);

  //lighting LED 05
  digitalWrite(ledPins[4], HIGH);
  delay(delayTime);

  //turning off all LEDs at once - There is no delay, so the turn oof should worf for all of them.
  ///*
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  delay(5*delayTime);
  //*/


}
