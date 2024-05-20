byte pin7 = 0;
void setup() {
  pinMode (13, OUTPUT);
  pinMode (7, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite (13, HIGH);
  delay (1000);

  digitalWrite (13, LOW);
  delay (1000);

  pin7 = digitalRead(7);
  Serial.println(pin7);
}
