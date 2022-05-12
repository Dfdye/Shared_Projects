Four air quality/VOC sensors (MiCS5524, SGP30, CCS811, and BME680) have been connected to an Arduino Nano to allow simultaneous moninoring through a single USB connection.  

VOC_Multi-Sensor_Data_Logger.vi is written in LabVIEW Community Edition (https://www.ni.com/en-us/shop/labview/select-edition/labview-community-edition.html) and is provided for non-commercial use only.  

The Simple_sensor_bracket.stl is provided as a bare-bones bracket to allow mounting of the 4 sensors and an arduino Nano.  The Nano is intended to be mounted using hot glue, which isn't pretty, but works!  To remove hot glue, apply isopropyl alcohol to the hot glue and gently begin peeling the hot glue away.  

Sketches necessary for Arduino Nano software:
Wire.h
SPI.h
Adafruit_Sensor.h
Adafruit_BME680.h
Adafruit_CCS811.h
Adafruit_SGP30.h

All libraries can be downloaded via library manager in Arduino software.  


Pin connections for sensors to Arduino Nano

Arduino Nano
5V	>	+5V (bus)	
Gnd >	Gnd (bus)
Gnd >	Gnd (bus)
A0	>	MiCS5524 Ao
A4	>	SDA (bus)
A5	>	SLC (bus)


MiCS5524 > Arduino Pins
5V	> +5V (bus)
Gnd > Gnd (bus)
Ao	> A0
En	> NC

SGP30
Vin	>	+5V (bus)
1V8 >	NC
GND >	Gnd (bus)
SLC	>	A5 (bus)
SDA >	A4 (bus)

CCS811
VCC	>	+5V (bus)
GND >	Gnd (bus)
SLC	>	A5 (bus)
SDA >	A4 (bus)
WAK >	Gnd (bus)
INT >	NC
RST >	NC
ADD >	NC

BME680
VCC	>	+5V (bus)
GND >	Gnd (bus)
SLC	>	A5 (bus)
SDA >	A4 (bus)
SD0 >	NC
CS	>	NC