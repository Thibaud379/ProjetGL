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
    map<time_t, Measure> *measures;
    Coords coords;
    string id;

public:
    static int atmosIndex(Measure m);
    bool addMeasure(time_t, Measure);

    map<time_t, Measure> *getMeasure(){return measures;};
    Coords getCoords() { return coords; }
    string getId() { return id; }

    Sensor(Coords coords = Coords(), string id = "null");
    ~Sensor();
};

#endif