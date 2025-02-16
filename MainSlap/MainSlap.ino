#include <Servo.h>
#include "servoCode.h"
#include "LedControl.h"
 
#define PLAY_E 3
#define playTime 2000

//Initialize
int micPin = A0;
int sensorValue = 0;
int tooLoud = 0;
int tootooLoud = 0;
int goodboy = 0;
int neutralVol = 95;
int sadVol = 130;
float timer = 0;
float timeThresh = 10;

LedControl lc=LedControl(12,11,10,1);

void smileyFace() {
  byte smiley[8] = {
    B00111100,  // Row 0: Eys and Mouth
    B01000010,  // Row 1: Eyes
    B10100101,  // Row 2: Eyes
    B10000001,  // Row 3: Mouth
    B10100101,  // Row 4: Mouth
    B10011001,  // Row 5: Mouth
    B01000010,  // Row 6: Mouth
    B00111100   // Row 7: Empty space
  };
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, smiley[row]);  // Set each row of the matrix to the corresponding smiley data
  }
}

void sadFace() {
  byte sad[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100
  };
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, sad[row]);  // Set each row of the matrix to the corresponding smiley data
  }

}
void neutralFace() {
  byte neutral[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10000001,
    B10111101,
    B01000010,
    B00111100
  };
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, neutral[row]);  // Set each row of the matrix to the corresponding smiley data
  }

}

void setup() {

  pinMode(PLAY_E,OUTPUT);// set the PLAY_e pin as output
  Serial.begin (9600);

  //Servo Begin
  myServo.attach(servoPin);  // Attach the servo to pin 9
  myServo.write(90);
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(micPin);
  
  if (sensorValue > 100){ // if sound reaches threshold
    tooLoud = tooLoud + 1;
    goodboy = 0;
    }

  if (tooLoud >= 8){ // if sound reaches threshold too many times
    tootooLoud = tootooLoud + 1;
  
    if (tootooLoud == 2){ // slap if too-too loud twice
      // startSlap();
      tootooLoud = 0;
      timer = timer - timer;
      }

    // play recording
    digitalWrite(PLAY_E, HIGH);
    delay(50);
    digitalWrite(PLAY_E, LOW); 

    Serial.println("Playback Started");  
    delay(playTime);  
    Serial.println("Playback Ended");
    tooLoud = 0;
    }

//ALL GOODBOY CODE
  if (goodboy == 2 && (abs(timer - timeThresh) < 0.01)){ // if been quite for long enough, give candy
    Serial.println("You get the yummy candy!");
    Serial.print("147\n");
    myServo.write(147);
    delay(3000);
    Serial.print("90\n");
    myServo.write(90);
    timer = 0;
    goodboy = 0;
  }
  else if (abs(timer - timeThresh) < 0.01){ // if been quite for long enough, give candy
    Serial.println("You get candy!");
    Serial.print("33\n");
    myServo.write(33);
    delay(3000);
    Serial.print("90\n");
    myServo.write(90);
    timer = 0;
    goodboy++;
  }

//END GOODBOY CODE
    
  //main count
  timer = timer + 0.1;


  if (sensorValue < neutralVol){
    smileyFace();
  }
  else if (sensorValue>neutralVol && sensorValue<sadVol){
    neutralFace();
    //delay(600);
    } 
  else if (sensorValue>sadVol){
    sadFace();
    //delay(600);
  }

  Serial.println(sensorValue, DEC);
  Serial.print("Too Loud: ");
  Serial.println(tooLoud);
  Serial.print("Too Too Loud: ");
  Serial.println(tootooLoud);

  Serial.print("goodboy counter:");
  Serial.println(timer);
  // Serial.println("Time: ");
  // Serial.println(timer);

  delay(100);

}