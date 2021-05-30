
#include "AirWatcherIO.h"
#include <iostream>
#include <list>
using namespace std;

class Control
{
private:
    /* data */
    AirWatcherIO airWatcherIO;
    vector<Sensor> findCloseSensors(Coords coords, int radius);

public:
    Data &data;
    list<pair<float, Sensor>> *findSimilarSensor(Sensor target, float deltaMax, time_t date);
    int getAirQuality(Coords coords, int radius, time_t start, time_t end);
    vector<int> getImpact(Cleaner target, int radius);
    Control();
    Control(unordered_map<string, string> files);
    ~Control();
};
