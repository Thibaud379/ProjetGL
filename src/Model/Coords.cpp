#include "Coords.h"
#include <cmath>

float Coords::dist(Coords *c)
{
    float dLat = this->latitude - c->latitude;
    float dLong = this->longitude - c->longitude;
    dLat *= M_PI / 180;
    dLong *= M_PI /180;

    float a = sin(dLat/2)*sin(dLat/2) + sin(dLong/2)*sin(dLong/2) * cos(M_PI*this->latitude/180)*cos(M_PI*c->latitude/180);
    float b = 2 * atan2(sqrt(a),sqrt(1-a));
    return EARTHRADIUS * b;

}

Coords::Coords(float latitude, float longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}

Coords::Coords()
{
    this->latitude = 0;
    this->longitude = 0;
}

Coords::~Coords()
{
}