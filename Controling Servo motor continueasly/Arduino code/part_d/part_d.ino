#include <Servo.h>

int potPin = A0;
int servoPin = 6;
Servo servo;
int val=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
    int readVal = analogRead(potPin);
  // Scale down the reading value
     val = map(readVal, 0, 1023, 1000, 2000);
  // Update the position of servo
    servo.writeMicroseconds(val);
    Serial.println(val);
    delay(50);
}
