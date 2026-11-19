#include <Wire.h>                       // I2C library
#include <LiquidCrystal_I2C.h>          // screen library
LiquidCrystal_I2C lcd(0x27, 16, 2);     // address 0x27, 16 columns, 2 rows


const int Main_Green = 23;
const int Main_Yellow = 22;
const int Main_Red = 21;
const int Side_Green = 19;
const int Side_Yellow = 18;
const int Side_Red = 5;

const int Buzzer = 2;
const int Trig_Sensor = 4;
const int Echo_Sensor = 15;


void setup() {
  
pinMode(Main_Green, OUTPUT);
pinMode(Main_Yellow, OUTPUT);
pinMode(Main_Red, OUTPUT);
pinMode(Side_Green, OUTPUT);
pinMode(Side_Yellow, OUTPUT);
pinMode(Side_Red, OUTPUT);
pinMode(Buzzer, OUTPUT);
pinMode(Trig_Sensor, OUTPUT);
pinMode(Echo_Sensor, INPUT);

Wire.begin(16, 17);   // Start I2C: SDA = 16 (RX2), SCL = 17 (TX2)
lcd.init();           // Wake up the LCD
lcd.backlight();      // Turn on the LCD light

lcd.setCursor(0, 0);              //before any cars gets detected, it displays that side street is clear
lcd.print("Side Street");
lcd.setCursor(0, 1);
lcd.print("is clear");


}

void loop() {

digitalWrite(Main_Green, HIGH);
digitalWrite(Side_Red, HIGH);

digitalWrite(Trig_Sensor, LOW);    // Trig OFF (make sure it starts at LOW)
delayMicroseconds(2);              // wait 2 µs so LOW is stable
digitalWrite(Trig_Sensor, HIGH);   // Trig ON: start of the "measure" pulse
delayMicroseconds(10);             // keep it ON for 10 µs (the sensor needs at least 10)
digitalWrite(Trig_Sensor, LOW);    // Trig OFF: pulse finished, so the sensor sends the sound

long duration = pulseIn(Echo_Sensor, HIGH, 30000);    // Measure how long Echo stays HIGH (sound travel time, in µs). 0 = no echo.
                                    
long distance = duration / 58;          // Converting time to distance


if (distance > 0 && distance <= 5) {

  lcd.clear();                                  // erase old text
  lcd.setCursor(0, 0);                          // row 1
  lcd.print("Car detected");
  lcd.setCursor(0, 1);                          // row 2
  lcd.print("on side street");


  digitalWrite(Buzzer, HIGH);                 //BEEP twice when car detected 
  delay(200);
  digitalWrite(Buzzer, LOW);
  delay(200);
  digitalWrite(Buzzer, HIGH);
  delay(200);
  digitalWrite(Buzzer, LOW);

  delay(1000);                              //Main stays green 1 more second, and we dont write digitalWrite because its already Green
  
  digitalWrite(Main_Green, LOW);
  digitalWrite(Main_Yellow, HIGH);
  delay(3000);

  digitalWrite(Main_Yellow, LOW);         //All red (safety buffer)
  digitalWrite(Main_Red, HIGH);
  delay(2000);

  digitalWrite(Side_Red, LOW);            //Side becomes green
  digitalWrite(Side_Green, HIGH);
  delay(6000);

  digitalWrite(Side_Green, LOW);          //Side becomes yellow  
  digitalWrite(Side_Yellow, HIGH);
  delay(3000);

  digitalWrite(Side_Yellow, LOW);         //All red (safety buffer)
  digitalWrite(Side_Red, HIGH);
  delay(2000);

  digitalWrite(Main_Red, LOW);           //Back to main green, kept for at least 10 s
  digitalWrite(Main_Green, HIGH);


  lcd.clear();                                  //it erases the screen
  lcd.setCursor(0, 0);                          // row 1
  lcd.print("Side Street");
  lcd.setCursor(0, 1);                          // row 2
  lcd.print("is clear");


  delay(10000);
}

  
delay(60);      //short pause between sensor measurements

}
