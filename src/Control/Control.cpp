
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
    for (auto it : *(d->attributes))
    {
        cout << it.first << ", " << it.second.first << ", " << it.second.second << endl;
    }

    return 0;
}