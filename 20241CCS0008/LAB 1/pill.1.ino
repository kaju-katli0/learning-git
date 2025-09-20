#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Use 0x3F if 0x27 doesn't work

void setup() {
  Wire.begin();
  Serial.begin(9600);   // Start serial communication
  rtc.begin();

  // Uncomment this line if you're setting the time the first time:
  // rtc.adjust(DateTime(F(_DATE), F(TIME_)));

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Pill Clock");
  delay(2000);
  lcd.clear();
}

void loop() {
  DateTime now = rtc.now();

  // Format time with leading zeros
  char timeStr[9];
  sprintf(timeStr, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

  // Show on LCD
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(6, 0);
  lcd.print(timeStr);

  // Show on Serial Monitor
  Serial.print("Current Time: ");
  Serial.println(timeStr);

  delay(1000); // Update every second
}