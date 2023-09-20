#include <Servo.h>

int servoPin = 6;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {

  for(int i=0;i<=180;i++){
    servo.write(i);
    Serial.println(i);
    delay(50);
  }
  delay(10);
   for(int i=180;i>=0;i--){
    servo.write(i);
    Serial.println(i);
    delay(50);
  }
  

}
