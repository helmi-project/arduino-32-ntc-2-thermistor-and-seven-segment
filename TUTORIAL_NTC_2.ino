/*
   TUTORIAL NTC PADA ARDUINO
   MEMBACA NILAI ANALOG DARI NTC

   Pinout  :
   NTC -> A1
   CLK -> D10
   DIO -> D11
*/

#include "EcadioNTC.h"

#include <Arduino.h>
#include <TM1637Display.h>

#define NTC_PIN A1
#define CLK 10
#define DIO 11

//inisiasi 
TM1637Display display(CLK, DIO);
NTC temper(NTC_PIN);

void setup() {
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  delay(100);
  Serial.println("Baca suhu NTC pada Arduino");
  display.setBrightness(0x0f);
}

void loop() {
  float suhu;
  suhu = temper.getTemperature();
  Serial.print("Temperature pada board : ");
  Serial.print(suhu);
  Serial.write(0xC2);//simbol derajat
  Serial.write(0xB0);//simbol derajat
  Serial.println("C");

  display.showNumberDec(suhu, false);


  delay(1000);

}
