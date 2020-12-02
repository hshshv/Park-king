#include "Arduino.h"
#include "UltrasonicSensor.h"
#include "Led.h"

#ifndef ParkingSpot_h
#define ParkingSpot_h

class ParkingSpot
{
  public:
    ParkingSpot(int trig, int echo, int red, int green);
    ParkingSpot();
    bool Avialable();
    bool Refresh();
  private:
    UltrasonicSensor Sensor;
    Led RedLed;
    Led GreenLed;
};

#endif
