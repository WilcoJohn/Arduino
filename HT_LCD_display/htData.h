#include <SimpleDHT.h>

class HTSensor
{
private:
  byte m_temperature{ 0 };
	byte m_humidity{ 0 };
	byte m_data[40]{ 0 };
  int m_delay{ 1000 };
  int m_pinSensor{ A0 };
  SimpleDHT11 m_sensor{};


public:
  HTSensor(int sensorPin, int delay = 1000)
  : m_pinSensor{ sensorPin },
    m_delay{ delay }
  {}

 ~HTSensor() = default;




  
  // make read and write simpler/ neater for interface
  void serialPrint() const
	{
		Serial.print("T = "); Serial.print(this->getT()); Serial.println(" °C");
		Serial.print("H = "); Serial.print(this->getH()); Serial.println(" %");
	}

	void readSensor()
	{
		if (m_sensor.read(m_pinSensor, &m_temperature, &m_humidity, m_data))
		{
			Serial.println("Read DHT11 failed");
      return;
		}
	}



  // Getters and setters
  inline byte getH_byte() const{ return m_humidity;};
  inline byte getT_byte() const{ return m_temperature;}
  inline byte getData_byte() const{ return m_data;};

  inline int getH() const{ return (int)m_humidity;}
  inline int getT() const{ return (int)m_temperature;}

  inline int getDelay() const { return m_delay;}
  void setDelay(int delay) { m_delay = delay;}

  inline int getPin() const { return m_pinSensor;}
  void setPin(int pin) { m_pinSensor = pin;}
};








