#if !defined(SENSOR_H)
#define SENSOR_H

#include <unordered_map>
#include <map>

#include "Coords.h"

using namespace std;

typedef struct
{
    float O3, NO2, SO2, PM10;
} Measure;

class Sensor
{
private:
    map<time_t, Measure> Measures;
    Coords coords;

public:
    Sensor(Coords coords);
    ~Sensor();
};

#endif