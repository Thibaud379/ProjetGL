#if !defined(CLEANER_H)
#define CLEANER_H

#include <ctime>
#include "Coords.h"

class Cleaner
{
private:
    Coords coords;
    time_t beginTime;
    time_t endTime;

public:
    Cleaner(Coords c, time_t begin, time_t end);
    Cleaner();
    ~Cleaner();
};

#endif