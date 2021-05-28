#include "Control/Control.h"
#include <unordered_map>
#include <ctime>

time_t parseTime(string time)
{
    struct tm t = tm();
    strptime(time.c_str(), format.c_str(), &t);
    return mktime(&t);
}

int main(int argc, char **argv)
{
    unordered_map<string, string> files = {
        {"attributes", "data/attributes.csv"},
        {"cleaners", "data/cleaners.csv"},
        {"providers", "data/providers.csv"},
        {"measurements", "data/measurements.csv"},
        {"sensors", "data/sensors.csv"},
        {"users", "data/users.csv"},
        {"usersUntrusted", "data/usersUntrusted.csv"}};

    Control c(files);
    list<pair<float, Sensor>> *l = c.findSimilarSensor(c.data.sensors.at("Sensor0"), 1000, parseTime("2019-01-04 12:00:00"));
    for (auto e : *l)
    {
        cout << e.first << "  -  " << e.second.getId() << endl;
    }

    return 0;
}