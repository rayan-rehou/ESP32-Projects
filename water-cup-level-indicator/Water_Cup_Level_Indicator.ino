#include <Wire.h>                       // I2C library
#include <LiquidCrystal_I2C.h>          // screen library
LiquidCrystal_I2C lcd(0x27, 16, 2);     // address 0x27, 16 columns, 2 rows


const int Led_Green = 19;
const int Led_Red = 21;
const int Buzzer = 4;
const int Trig_Sensor = 22;
const int Echo_Sensor = 23;

void setup() {

Wire.begin(18, 5);      // SDA = 18 and SCL = 5
lcd.init();             // Activates the screen
lcd.backlight();        // Turns on the light

lcd.setCursor(0, 0);
lcd.print("Water: 0 cm");
lcd.setCursor(0, 1);
lcd.print("Fill: 0%");


pinMode(Led_Green, OUTPUT);
pinMode(Led_Red, OUTPUT);
pinMode(Buzzer, OUTPUT);
pinMode(Trig_Sensor, OUTPUT);
pinMode(Echo_Sensor, INPUT);

}

void loop() {

digitalWrite(Trig_Sensor, LOW);
delayMicroseconds(2);
digitalWrite(Trig_Sensor, HIGH);
delayMicroseconds(10);
digitalWrite(Trig_Sensor, LOW);

long duration = pulseIn(Echo_Sensor, HIGH);
float distance = duration / 58.0 ;

float water = 13.6 - distance;
float percentage = water /12 *100 ; 

lcd.setCursor(0, 0);
lcd.print(String("Water: ") + water + " cm   ");
lcd.setCursor(0, 1);
lcd.print(String("Fill: ") + percentage + " %   ");

if (percentage >= 80){
  digitalWrite(Buzzer, HIGH);
  digitalWrite(Led_Red, HIGH);
  digitalWrite(Led_Green, LOW);
}
else {
  digitalWrite(Buzzer, LOW);
  digitalWrite(Led_Red, LOW);
  digitalWrite(Led_Green, HIGH);
}


delay(200);
}
