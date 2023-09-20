int led = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr = analogRead(A1);
  ldr = (int) ldr / 4;
  analogWrite(led, 255-ldr);
  delay(50);
}
