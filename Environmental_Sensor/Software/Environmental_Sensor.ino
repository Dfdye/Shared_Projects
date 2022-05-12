/***************************************************************************
  This test software is based on sketches developed by Adafruit for the 
  CBME680 and SGP30 sensors.  Information about these sensors can be found at: 
  
  http://www.adafruit.com/products/3660

  The SGP30, and BME680 sensors use I2C to communicate.  

  Libraries can be downloaded for the these sensors from the Arduino library
  manager.

  Written by dfdye/Dr. Dave for personal use.  If you are worried about licensing 
  this software, I have really bad news for you!  It's probably pretty awful.
  But let's call it a BSD license just to be in line with the sources I used.

----------------------------------------------------------------------------
SOURCE DOCUMENTATION
----------------------------------------------------------------------------
  This is a library for the BME680 gas, humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME680 Breakout
  ----> http://www.adafruit.com/products/3660

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

---------------------------------------------------------------------------

 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include "Adafruit_SGP30.h"

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C
//Adafruit_BME680 bme(BME_CS); // hardware SPI
//Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

Adafruit_SGP30 sgp;

/* return absolute humidity [mg/m^3] with approximation formula
* @param temperature [°C]
* @param humidity [%RH]
*/
uint32_t getAbsoluteHumidity(float temperature, float humidity) {
    // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
    const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature)); // [g/m^3]
    const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity); // [mg/m^3]
    return absoluteHumidityScaled;
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("BME680 and SGP30 sensor test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring.");
    while (1);
  }  
  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms

  if (! sgp.begin()){
    Serial.println("Could not find a valid SGP30 sensor, check wiring.");
    while (1);
  }

}

int counter = 0;
void loop() {

//BME680 Reading
  if (! bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }
  Serial.print("Temperature (deg C): ");
  Serial.println(bme.temperature);

  Serial.print("Pressure (hPa): ");
  Serial.println(bme.pressure / 100.0);
  
  Serial.print("Humidity (%): ");
  Serial.print(bme.humidity);
    
  Serial.println();


// SGP30 Measurement
// ITemperature and humidity readings are passed from the BME680 sensor to the SGP30

  float temperature = (bme.temperature); // [°C]
  float humidity = (bme.humidity); // [%RH]
  sgp.setHumidity(getAbsoluteHumidity(temperature, humidity));

  if (! sgp.IAQmeasure()) {
    Serial.println("SGP30 Measurement failed");
    return;
  }
  Serial.print("SGP30 TVOC (ppb): "); Serial.println(sgp.TVOC);
  Serial.println();  
  delay(5000);

}
