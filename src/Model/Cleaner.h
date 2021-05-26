#if !defined(CLEANER_H)
#define CLEANER_H

#include <ctime>
#include "Coords.h"
using namespace std;
class Cleaner
{
private:
    Coords coords;
    time_t beginTime;
    time_t endTime;
    string id;

public:
    Coords getCoords() { return coords; }
    string getId() { return id; }
    pair<time_t, time_t> getTime() { return make_pair(beginTime, endTime); }
    Cleaner(Coords c, time_t begin, time_t end, string id = "null");
    Cleaner();
    ~Cleaner();
};

#endif