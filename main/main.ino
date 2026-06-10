// Communication between teensy and cytron motor driver
// Pin 2 - DIR (tells the motor driver which direction to spin)
// Pin 3 - PWM (tells the motor driver how fast to spin (0=stop;255=full speed))

void setup() {
  pinMode(2, OUTPUT);  // tells teensy pin 2 is sending signals not receiving
  pinMode(3, OUTPUT);

  Serial.begin(9600);  // Sets communcation at 9600 baud (necessary for print statements)
  Serial.println("Cytron ready");
  digitalWrite(2, HIGH);  // Motor driver should spin the motor forward
}

void loop() {
  Serial.println("Sending PWM signal...");
  analogWrite(3, 128);  // Motor at half speed
  delay(2000);
  analogWrite(3, 0); // sets PWM to 0;
  delay(1000);
}