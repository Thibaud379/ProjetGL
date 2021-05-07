#include "Sensor.h"

bool Sensor::addMeasure(time_t t, Measure m)
{
    return this->Measures.emplace(t, m).second;
}

map<time_t, Measure> *Sensor::getMeasure()
{
    return &Measures;
}

Sensor::Sensor(Coords coords)
{
    this->coords = coords;
    this->Measures = map<time_t, Measure>();
}

Sensor::~Sensor()
{
}
