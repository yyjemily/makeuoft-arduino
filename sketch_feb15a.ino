#include <LedControl.h>
#include "Arduino.h"

int DIN = 12; // Pin number 
int CS =  11;
int CLK = 10;

  byte c[8]=     {0x7E,0x7E,0x60,0x60,0x60,0x60,0x7E,0x7E};
  byte eight[8]= {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E};
  byte s[8]=     {0x7E,0x7C,0x60,0x7C,0x3E,0x06,0x3E,0x7E};
  byte dot[8]=   {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
  byte o[8]=     {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E};
  byte nine[8] = {
  B01111110,  // 0x7E in binary
  B01111110,  // 0x7E in binary
  B01100110,  // 0x66 in binary
  B01111110,  // 0x7E in binary
  B01111110,  // 0x7E in binary
  B01100110,  // 0x66 in binary
  B01111110,  // 0x7E in binary
  B01111110   // 0x7E in binary
};


LedControl lC = LedControl(DIN,CLK,CS,0);

void setup() {
  // put your setup code here, to run once:
  //initialize input and output pins 


}

void loop() {
  printByte(c);
  delay(1000); //delay 1 sec 

}

void printByte(byte character [])
{
    int i = 0;
    for(i=0;i<8;i++)
    {
       lC.setRow(0,i,character[i]);
    }
}
