// RGB senzor TCS34725


#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725();
//Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

uint16_t r, g, b, c, teplotaBarev, lux;

void setup(void) {

  Serial.begin(9600);
 
  if (tcs.begin()) {
    Serial.println(" TCS34725.");
  } else {
    Serial.println("sensor.");
    while (1);
  }
}

void loop(void) {
  
  tcs.setInterrupt(false);
  delay(60);

  tcs.getRawData(&r, &g, &b, &c);
  
  tcs.setInterrupt(true);
  
  teplotaBarev = tcs.calculateColorTemperature(r, g, b);
  
  lux = tcs.calculateLux(r, g, b);
  
  Serial.print("color temperature: "); Serial.print(teplotaBarev, DEC); Serial.print(" Kelvin - ");
  Serial.print("intensity illuminated: "); Serial.print(lux, DEC); Serial.print(" lux - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
  if(r>g && r>b)
  Serial.println("red");
    else if(g>r && g>b)
  Serial.println("green");
   else if(b>g && b>r)
  Serial.println("blue");
  else
  Serial.println("no color ");
 
  delay(300);
}
