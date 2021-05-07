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

typedef struct
{
    unordered_map<string, pair<string, string>> *attributes;
    unordered_map<string, Cleaner> *cleaners;
    unordered_map<string, Provider> *providers;
    unordered_map<string, PrivateUser> *privateUsers;
    unordered_map<string, Sensor> *sensors;

} Data;

class AirWatcherIO
{
public:
    static Data *loadFiles(unordered_map<string, string> files);

private:
    static void loadAttributes(Data* d, string path);
    static void loadCleaners(Data* d, string path);

};

#endif