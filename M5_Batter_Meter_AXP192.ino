#include <M5Unified.h>
#include <M5GFX.h>
#include "AXP192.h"


AXP192 POWER;


void setup() {
    
    M5.begin();
    M5.Display.fillScreen(BLACK);
    M5.Display.setRotation(3);
    M5.Display.setTextSize(2);           // change text size

    delay(1000);
    POWER.begin();
    POWER.EnableCoulombcounter();  // Enable Coulomb counter.  启用库仑计数器
}

void loop() {
    
    float vin = POWER.GetVinVoltage();

    M5.Display.setCursor(200, 0);
    M5.Display.setTextColor(GREEN,BLACK);
    if(vin < 3.0)
    {
       vin = 0.0;
       M5.Display.printf("           ");
    }
    else{
      M5.Display.printf("CHARGING");
    } 
 
    M5.Display.setCursor(0, 40);
    M5.Display.setTextColor(CYAN,BLACK);
    M5.Display.printf("AXP Temp: %.1fC \r\n\n", POWER.GetTempInAXP192());
    M5.Display.printf("Bat: %.3fv \r\n\n", POWER.GetBatVoltage());
    M5.Display.printf("5V-In: %.3fv  \r\n\n", vin);
    M5.Display.printf("Bat power: %.3fmw\r\n", POWER.GetBatPower());
    M5.update();
    delay(1000);
}