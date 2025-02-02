#include "htData.h"
#include "lcdDisplay.h"



HTSensor htData{A0};          // create temperature and humidity sensor object
lcdDisplay screen{};          // create LCD screen object

void setup() 
{
  Serial.begin(9600);         // serial setup
  screen.init();              // LCD screen display set up
}

void loop() 
{
  htData.readSensor();        // update data
  htData.serialPrint();       // print data to serial
  
  
  // print data to LCD screen
  screen.updateValues( htData.getH(), htData.getT());

 
  delay(htData.getDelay());   // delay data until sensor can update again
}
