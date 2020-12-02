#include "ParkingSpot.h"
#include "Parking.h"
#include "LC.h"

Parking Area1(ParkingSpot(2, 3, 4, 5), ParkingSpot(6, 7, 8, 9));//trig, echo, red, green
Parking Area2(ParkingSpot(10, 11, 12, 13), ParkingSpot(14, 15, 16, 17));

UltrasonicSensor entrenceSensor(18, 19); //trig, echo

LC lcd(0x3F, 16, 2);//migth be somthing else, use an I2C scanner

void setup()
{
  lcd.begin();
  lcd.backlight();
  Area1.Refresh();
  Area2.Refresh();
}

void loop()
{
  PrintAvialableSpots();
  if (entrenceSensor.Blocked())
  {
    directDriver();
  }
  else
  {
    Area1.Refresh();
    Area2.Refresh();
    delay(100);
  }
}

void PrintAvialableSpots()
{
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(Area1.AvialableSpots() + Area2.AvialableSpots());
  lcd.setCursor(3, 1);
  lcd.print("left");
}

void directDriver()
{
  lcd.setCursor(0, 1);
  if (Area1.AvialableSpots() > Area2.AvialableSpots())
  {
    lcd.print("turn rigth >");
  }
  else
  {
    lcd.print("< turn left");
  }
}
