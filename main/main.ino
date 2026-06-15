// Communication between teensy and cytron motor driver
// Pin 2 - DIR (tells the motor driver which direction to spin)
// Pin 3 - PWM (tells the motor driver how fast to spin (0=stop;255=full speed))

// NOTE NEVER GO ABOVE 182 (12V)
// 255 = 16.8V (too much but provided by battery)
// 182 = ~12V (perfect) - highest can go

#include <Encoder.h>

Encoder rearEnc(4, 5);

void setup() {
  pinMode(2, OUTPUT);  // tells teensy pin 2 is sending signals not receiving
  pinMode(3, OUTPUT);

  Serial.begin(9600);  // Sets communcation at 9600 baud (necessary for print statements)
  Serial.println("Cytron with encoder test");
  digitalWrite(2, HIGH);  // Motor driver should spin the motor forward
}

void loop() {
  // motor control
  Serial.println("Sending PWM signal...");
  analogWrite(3, 128);  // Motor at half speed

  // encoder reading
  long position = rearEnc.read();
  Serial.println(position);
  
  delay(2000);

  // motor control
  analogWrite(3, 0); // sets PWM to 0;

  // encoder reading
  position = rearEnc.read();
  Serial.println(position);

  delay(1000);
}