This environmental sensor uses a BME680 to measure temperature, air pressure, and relative humidity, and an SGP30 to measure VOC content in the air.  You may ask, "Why not use the VOC sensor on the BME680?", and that would be an excellent question!  In my testing, I have found that the BME680 sensor is not reliably sensitive to cyclic aromatic hydrocarbons, specifically styrene, and thus makes a poor sensor for my application, which is air monitoring around 3D printers that print ABS (which releases styrene when printed).

Both of the environmental sensors are connected to an Arduino via an I2C interface*.  Temperature and relative humidity measurements from the BME680 are used to calculate absolute humidity, which is then passed to the SGP30.  

Readings from both sensors are output via a serial interface. Since it has proven unsuitable for my purposes, the BME680 VOC measurement is not output.    

For data acquisition and logging, I have written a VI in LabVIEW Community Edition.  This software is available free of charge on PC, Mac, and Linux platforms for non-commercial purposes ( https://www.ni.com/en-us/shop/labview/select-edition/labview-community-edition.html )


*All of the back-end libraries for the Arduino software were originally written and provided by Adafruit, so please support them since they provide so much cool stuff to the community for free.
