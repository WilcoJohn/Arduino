#include <Wire.h>
#include <LiquidCrystal_I2C.h>


class lcdDisplay
{
  private:
  LiquidCrystal_I2C m_lcd{ 0x27, 16, 2 }; //  Make sure sda and scl pins are correcty connected for LCD display to use. 
                                          //  Currently the "0x27" is set up for arduino-UNO 
  
  public:
  lcdDisplay() = default;

  init()
  {
    // start screen
    m_lcd.init();
    m_lcd.backlight();

    // Print temperature line
    m_lcd.setCursor(0,0);
    m_lcd.print("Temp.:        ");
    m_lcd.write(223);
    m_lcd.print("C");

    // Print humidity line
    m_lcd.setCursor(0,1);
    m_lcd.print("Humidity:      %");
  }


  void updateValues(int humidity, int temperature)
  {
    // check if humidity is 2 or 3 digits long and set cursor accordingly
    m_lcd.setCursor((humidity >= 100) ? 12 : 13, 1);
    m_lcd.print(humidity);

    // check if temperature is 2 or 3 digits long and set cursor accordingly
    m_lcd.setCursor((temperature >= 100) ? 11 : 12 ,0);
    m_lcd.print(temperature);
  }
};