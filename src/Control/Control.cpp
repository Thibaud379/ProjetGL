
#include "AirWatcherIO.h"
#include <iostream>

int main(int argc, char **argv)
{
    unordered_map<string, string> files = {
        {"attributes", "data/attributes.csv"},
        {"cleaners", "data/cleaners.csv"},
        {"providers", "data/providers.csv"},
        {"measurements", "data/measurements.csv"},
        {"sensors", "data/sensors.csv"},
        {"users", "data/users.csv"},
        {"usersUntrusted", "datausersUntrusted.csv"}};

    Data *d = AirWatcherIO::loadFiles(files);
    for (auto it : *(d->sensors->at("Sensor0").getMeasure()))
    {
        cout << it.first << ": " << it.second.NO2<<", "<<it.second.O3 << endl;
    }

    return 0;
}