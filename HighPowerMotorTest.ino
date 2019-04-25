int PowerPin = 10;               

void setup()
{
  pinMode(PowerPin, OUTPUT);     
  digitalWrite(PowerPin, HIGH);   
}

void loop() {
  digitalWrite(PowerPin, HIGH);
  delay(1000);
  digitalWrite(PowerPin, LOW);
  delay(1000);

}
