#include <Servo.h>


Servo myServo;  // Create a Servo object to control the arm

int restPosition = 0;  // Servo's initial position (back position)
int triggerPosition = 90;  // Servo's forward position (trigger position)
int delayTime = 1000;  // Time in milliseconds for the delay between movements

void setup() {
  myServo.attach(9);  // Attach the servo to pin 9
  myServo.write(restPosition);  // Start with the arm at rest (back position)
  delay(1000);  // Wait for 1 second
}

void loop() {
  // Move the arm to the trigger position (forward)
  myServo.write(triggerPosition);  // Move the arm to the trigger position
  delay(delayTime);  // Wait for the arm to reach the forward position (1 second)

  // Return the arm to the rest position (back)
  myServo.write(restPosition);  // Move the arm back to the rest position
  delay(delayTime);  // Wait for the arm to return to the back position

  // Add more actions or repeat the loop as needed
}
