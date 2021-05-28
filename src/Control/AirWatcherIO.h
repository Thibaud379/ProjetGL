#if !defined(AIRWATCHERIO_H)
#define AIRWATCHERIO_H

#include <unordered_map>
#include <string>

#include "../Model/Coords.h"
#include "../Model/Cleaner.h"
#include "../Model/Provider.h"
#include "../Model/PrivateUser.h"
#include "../Model/Sensor.h"

using namespace std;

const string format = "%Y-%m-%d %T";
struct Data
{
    unordered_map<string, pair<string, string>> attributes;
    unordered_map<string, Cleaner> cleaners;
    unordered_map<string, Provider> providers;
    unordered_map<string, PrivateUser> privateUsers;
    unordered_map<string, Sensor> sensors;

    Data(unordered_map<string, string> files);

private:
    void loadAttributes(string path);
    void loadCleaners(string path);
    void loadProviders(string path);
    void loadSensors(string path);
    void loadMeasurements(string path);
    void loadUsers(string path);
    void loadUntrusted(string path);
};

class AirWatcherIO
{

private:
    unordered_map<string, string> files;

public:
    Data data;
    AirWatcherIO(unordered_map<string, string> _files) : files(_files), data(_files){};
};

#endif