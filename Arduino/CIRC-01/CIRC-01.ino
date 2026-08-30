//I've changed the original CIRC-01 code to show a "S.O.S" signal

int ledPin = 13; //LED connected to digital pin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Letter 'S'
  digitalWrite(ledPin, HIGH);
  delay(333);
  digitalWrite(ledPin, LOW);
  delay(333);
  digitalWrite(ledPin, HIGH);
  delay(333);
  digitalWrite(ledPin, LOW);
  delay(333);
  digitalWrite(ledPin, HIGH);
  delay(333);
  digitalWrite(ledPin, LOW);
  delay(1000);
  
  //letter 'O'
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(333);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(333);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);

  //letter 'S'again
   digitalWrite(ledPin, HIGH);
  delay(333);
  digitalWrite(ledPin, LOW);
  delay(333);
  digitalWrite(ledPin, HIGH);
  delay(333);
  digitalWrite(ledPin, LOW);
  delay(333);
  digitalWrite(ledPin, HIGH);
  delay(333);
  digitalWrite(ledPin, LOW);
  delay(1000);

  delay(5000);//to finish
}
