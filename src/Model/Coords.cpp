#include "Coords.h"

Coords::Coords()
{
    this->latitude = 0;
    this->longitude = 0;
}

Coords::Coords(float latitude, float longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}

Coords::~Coords()
{
}