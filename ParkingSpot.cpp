#include "ParkingSpot.h"

ParkingSpot::ParkingSpot(int trig, int echo, int red, int green)
  : Sensor(trig, echo), RedLed(red), GreenLed(green)
{
  Sensor.StoppingDistance = 5;
  Refresh();
}

ParkingSpot::ParkingSpot()
{
  ParkingSpot(2,3,4,5);
  
  Sensor.StoppingDistance = 5;
  Refresh();
}

bool ParkingSpot::Avialable()
{
  return(Sensor.Blocked());
}

bool ParkingSpot::Refresh()
{
  if(Avialable() && GreenLed.On())
  {
    GreenLed.TurnOff();
    RedLed.TurnOn();
  }
  
  if(!Avialable() && RedLed.On())
  {
    RedLed.TurnOff();
    GreenLed.TurnOn();
  }
}
