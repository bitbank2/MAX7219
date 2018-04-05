#include <max7219.h>
//
// MAX7219 Demo program
// Written by Larry Bank
// Project started 3/10/2018
//
#define SELECT_PIN 3
// Pins used for 'bit-banged' version
#ifndef USE_SPI
#define CLOCK_PIN 4
#define DATA_PIN 1
#endif // !USE_SPI

void setup() {
  // put your setup code here, to run once:
maxInit(4, 0, CLOCK_PIN, DATA_PIN, SELECT_PIN); // initialize (turn on) the controllers in the strip and set mode 0 (pixels)
}

void loop() {
  // put your main code here, to run repeatedly:
  int i, j, iPitch;
  char cTemp[32];
  byte bImg[24 * 8];

  iPitch = 24;
  memset(bImg, 0, iPitch*8);
  
  for (i=0; i<100; i++)
  {
     sprintf(cTemp, "BitBank MAX7219 #%02d", i);
     maxDrawString(cTemp, bImg, iPitch, 1); // draw digits into "image" buffer 
     for (j=0; j<iPitch*8; j++)
     {   
        maxSendImage(bImg, iPitch);
        maxScrollBitmap(bImg, iPitch, 1);
        delay(40);
     } // for j 
  } // for i

}
