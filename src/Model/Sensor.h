#if !defined(SENSOR_H)
#define SENSOR_H

#include <unordered_map>
#include <map>

#include "Coords.h"

using namespace std;

struct Measure
{
    float O3, NO2, SO2, PM10;
    void add(const Measure &m)
    {
        this->NO2 += m.NO2;
        this->SO2 += m.SO2;
        this->O3 += m.O3;
        this->PM10 += m.PM10;
    }
    static float delta(const Measure &m1, const Measure m2)
    {
        return abs(m1.NO2 - m2.NO2) / m1.NO2 + abs(m1.O3 - m2.O3) / m1.O3 + abs(m1.PM10 - m2.PM10) / m1.PM10 + abs(m1.SO2 - m2.SO2 / m1.SO2);
    }
    void div(int n)
    {
        this->NO2 /= n;
        this->O3 /= n;
        this->SO2 /= n;
        this->PM10 /= n;
    }

    const int atmosIndex();
};

class Sensor
{
private:
    map<time_t, Measure> measures;
    Coords coords;
    string id;

public:
    bool addMeasure(time_t, Measure);

    map<time_t, Measure> &getMeasure() { return measures; };
    Coords getCoords() { return coords; }
    string getId() { return id; }

    Sensor(Coords coords = Coords(), string id = "null");
    ~Sensor();
};

#endif