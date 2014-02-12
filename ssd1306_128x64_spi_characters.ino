/*********************************************************************
This sketch displays the full characterset of Adafruit's Monochrome OLEDs
based on SSD1306 drivers. I used the 128x64 OLED and purchased everything
from Limor's excellent Adafruit shop! The OLED has a very high quality
display.

  ------> http://www.adafruit.com/category/63_98

Required hardware:
  -Arduino (Tested both Uno Rev3 and Micro)
  -SSD1306 128x64 OLED display
  
*********************************************************************/
#include <Wire.h>                
#include <Adafruit_GFX.h>        /* OLED/LCD Gisplay grapshics libraey */
#include <Adafruit_SSD1306.h>    /* OLED Graphics dipslay              */

/* 
   To use this OLED driver you will need to download the Adafruit
   OLED library and include it in your libraries folder. I used Adafruit's
   128x64 OLED. It uses the SSD1306 driver and this sketch uses an SPI
   interface to the OLED for a speedy refresh!
   
   Connections for the Adafruit 128x64 SPI OLED (5V Capable)
   ===========
   Connect OLED_MOSI(DATA) 9
   Connect OLED_CLS(Clock) 10
   Connect OLED_DC(SAO) 11
   Connect OLED_RESET 8 (NOTE: Adafruit's examples use 13)   
   Connect OLED_CS 12
   Connect OLED_VDD(Vin) to 3.3V DC (Although can handle 5VDC)
   Connect OLED_GROUND to common ground

   Connections for the LED output indicator
   ============
   Connect LED digital out 13

*/

#define OLED_CS 12
#define OLED_DC 11    // Also labeled SA0 on OLED 
#define OLED_CLK 10
#define OLED_MOSI 9   // Labeled DATA on OLED 
#define OLED_RESET 8  // Changed this from 13 to 8 TO accomodate LED flash
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/* Check to make sure the OLED display is 128x64 in size, if not stop!  */
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int led=13;

/************************************************************************/
/*    Test Draw Character                                               */
/*                                                                      */
/************************************************************************/

void testdrawchar(void) {
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }    
  display.display();
  delay(10000);
}


/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void)  
{
  Serial.begin(9600);
 
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done

  /* Inform we are going to print the entire characther set text. */           
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Printing complete");
  display.println("character set ");
  display.println("for reference.");
  display.display();
  delay(3000);
 
} 

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void)  
{
  testdrawchar();
  
}

