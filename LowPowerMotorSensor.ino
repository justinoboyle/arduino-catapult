#include <Servo.h> 

int servoPin = 3; 
int buttonPin = 13;

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

const int THRESH = 20;

// defines variables
long duration;
int distance;

Servo servo; 
void setup() { 
   servo.attach(servoPin); 
//   servo.write(90);
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
bool b = false;
int i =0;
void loop() { 
int dist = readDistance();
if(dist < THRESH) {
  
  servo.write(b ? 180 : 90);
  Serial.print(readDistance());
  b = !b;
  
  while(abs(readDistance()-dist) <= 15) {}
  int t2 = millis();
  while(millis() - t2 < 200) {}
  servo.write(b ? 180 : 90);
   b = !b;
  int t = millis();
    while(millis() - t < 1000) {}

  Serial.print("\nBoop\n");
}

}

int readDistance() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
return distance;
  
}



bool btnUp() {
  return digitalRead(buttonPin) == LOW;
}

void waitForDown() {
   while(btnUp()) {}
}

void waitForUp() {
   while(!btnUp()) {}
}
