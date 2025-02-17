// Declare variables
const int forwardPin = 7;
const int backwardPin = 8;
const int motorSpeedPin = 9; // PWM pin for motor speed control
const int delayTime = 2000;

void setup() {
  // Set pin modes
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // Stop motor
  Serial.println("sfod");
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, LOW);
  analogWrite(motorSpeedPin, 0); // Stop motor completely
  delay(delayTime);

  // Spin forward at slower speed
  digitalWrite(forwardPin, HIGH);
  digitalWrite(backwardPin, LOW);
  analogWrite(motorSpeedPin, 32); // Set motor speed to 50% of full speed (adjust for your needs)
  delay(delayTime);

  // Stop motor
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, LOW);
  analogWrite(motorSpeedPin, 0);
  delay(delayTime);

  // Spin backward at slower speed
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, HIGH);
  analogWrite(motorSpeedPin, 32); // Set motor speed to 50%
  delay(delayTime);
}