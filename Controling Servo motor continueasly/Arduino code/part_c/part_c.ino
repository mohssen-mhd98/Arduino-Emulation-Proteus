 #include <Servo.h>

#include <FS.h>
Servo myservo;
int input_value;
int converted_value;

void setup() {
  myservo.attach(6);
  Serial.begin(9600);
}

void loop() {
}

void serialEvent() {
  input_value = Serial.parseInt();
  converted_value = map(input_value,-90, 90, 1000, 2000);
  Serial.print("read value is: ");
  Serial.println(input_value);
  Serial.print("Converted value is: ");
  Serial.println(converted_value);

  myservo.writeMicroseconds(converted_value);
}
