//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
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

void loop() { 
  //smileyface();
  //test();
  //delay(delaytime);
  //sadFace();
  neutralFace();

  //rows();
  //columns();
  //single();
}
