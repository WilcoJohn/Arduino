#include "htData.h"



HTSensor htData{A0};

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  htData.read();
  htData.print();

  delay(htData.getDelay());
}
