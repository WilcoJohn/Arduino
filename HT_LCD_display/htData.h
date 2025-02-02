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
  HTSensor(int sensorPin, int delay = 10000)
  : m_pinSensor{ sensorPin },
    m_delay{ delay }
  {}


  void print() const
	{
		Serial.print("T = "); Serial.print((int)m_temperature); Serial.println(" °C");
		Serial.print("H = "); Serial.print((int)m_humidity); Serial.println(" %");
	}

	void read()
	{
		if (m_sensor.read(m_pinSensor, &m_temperature, &m_humidity, m_data))
		{
			Serial.println("Read DHT11 failed");
      return;
		}
	}

  byte getH_byte() const{ return m_humidity;};
  byte getT_byte() const{ return m_temperature;}
  byte getData_byte() const{ return m_data;};

  int getH() const{ return (int)m_humidity;}
  int getT() const{ return (int)m_temperature;}

  int getDelay() const { return m_delay;}
  void setDelay(int delay) { m_delay = delay;}

  int getPin() const { return m_pinSensor;}
  void setPin(int pin) { m_pinSensor = pin;}
};








