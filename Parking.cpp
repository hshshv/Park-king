#include "Parking.h"



Parking::Parking(ParkingSpot A, ParkingSpot B)
{
  ParkingSpots[0] = A;
  ParkingSpots[1] = B;
}

int Parking::AvialableSpots()
{
  int Avialables = 0; //:)
  for (int i = 0; i < numOfParkingSpots; ++i)
  {
    if (ParkingSpots[i].Avialable())
    {
      ++Avialables;
    }
  }
  return (Avialables);
}

void Parking::Refresh()
{
  for (int i = 0; i < numOfParkingSpots; ++i)
  {
    ParkingSpots[i].Refresh();
  }
}
