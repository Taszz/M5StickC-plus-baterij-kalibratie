// Batterij kalibratie tool voor de M5Stickc plus
// Gebruiken bij het niet corect weergeven van batterij precentage
// Batterij voledig opladen. Noteer aantal mV
// Batterij voledig leeg laten lopen todat de M5stick wordt uigeschakeld. Noteer aantal mV

#include <M5StickCPlus.h>

// Noteer hier de juiste aantal mV voor de juiste baterij precentage

int batVol = 3920; //Voltage baterij vol in mV
int batLeeg = 3300; //Voltage baterij leeg in mV

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
}

void loop() {
    
    int batteryLevel = floor(100.0 * (((M5.Axp.GetVbatData() * 1.1) - batLeeg) / (batVol - batLeeg)));
  batteryLevel = batteryLevel > 100 ? 100 : batteryLevel;
    int batteryLevelVolt = (M5.Axp.GetVbatData() * 1.1);
  
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("Bat:" + String(batteryLevel) + "%  ");  
  M5.Lcd.println("");
  M5.Lcd.println(String(batteryLevelVolt) + "mV");
 
  M5.Lcd.setCursor(0, 80);
  if(batteryLevel >= 100){
      M5.Lcd.println("Baterij laad op");   // show when M5 is plugged in
      }
      else {
        M5.Lcd.println("                   ");
      }

  
}