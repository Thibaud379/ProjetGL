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

public:
    Coords getCoords() { return coords; }
    pair<time_t, time_t> getTime() { return make_pair(beginTime, endTime); }
    Cleaner(Coords c, time_t begin, time_t end);
    Cleaner();
    ~Cleaner();
};

#endif