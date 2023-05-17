//Enkaz Dinleme - Fatih Karakaya
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <MQ135.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(1200);
  pinMode(A0,INPUT); // pin A0 voltaj değeri
  pinMode(2,INPUT);  // pin 2 0-1 değeri
  pinMode(3,HIGH); // LED kontrol
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("       NAK");
  lcd.setCursor(0,1);
  lcd.print(" ARAMA KURTARMA");
  delay(1000);
  lcd.init();
}

void loop()
{
  float sensorValue = (analogRead(A0)*(0.783));   // voltaj değerinin 0.783 katı -Kalibrasyon gerekir:
  int soundValue = (digitalRead(2));
  Serial.println(sensorValue);
  delay(100);        // 100 ms gecikme
  lcd.setCursor(0,0);
  lcd.print("Gaz:");
  lcd.print(sensorValue);
  lcd.print(" PPM ");
  lcd.print(soundValue);
  //delay(10); 
  lcd.setCursor(0,1);
  if (sensorValue >= 150 && soundValue == 0) {
  lcd.print("Muhtemel canli!!"); 
  delay(1000); }
  else
  {
  lcd.print("Gozle ve Dinle!");
  } 
} 
