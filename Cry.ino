#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int soundSensorPin = PA0;

void setup() {
    lcd.begin();
    lcd.backlight();
    
    Serial.begin(9600);
    
    // Configure sound sensor pin as input
    pinMode(soundSensorPin, INPUT);
}

void loop() {
    int soundValue = analogRead(soundSensorPin);
    
    Serial.println(soundValue);
    
    if (soundValue > 800) {
        // Loud cry detected
        lcd.clear();
        lcd.print("Reason: Hunger");
        Serial.println("Reason: Hunger");
    } else if (soundValue > 500) {
        lcd.clear();
        lcd.print("Reason: Discomfort");
        Serial.println("Reason: Discomfort");
    } else {
        lcd.clear();
        lcd.print("All is calm");
        Serial.println("All is calm");
    }
    
    delay(1000); 
}
