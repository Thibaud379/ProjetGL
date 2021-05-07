#include "Sensor.h"

map<time_t, Measure> *Sensor::getMeasure()
{
    return &Measures;
}

Sensor::Sensor(Coords coords)
{
    this->coords = coords;
}

Sensor::~Sensor()
{
}
