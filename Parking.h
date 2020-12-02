#include "ParkingSpot.h"

#ifndef Parking_h
#define Parking_h

class Parking
{
  public:
    Parking(ParkingSpot A, ParkingSpot b);
    int AvialableSpots();
    void Refresh();
  private:
    static const int numOfParkingSpots = 2;
    ParkingSpot ParkingSpots[numOfParkingSpots];
};

#endif
