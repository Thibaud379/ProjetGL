#include "Cleaner.h"

Cleaner::Cleaner(Coords c, time_t begin, time_t end, string id)
{
    this->coords = c;
    this->beginTime = begin;
    this->endTime = end;
    this->id = id;
}

Cleaner::Cleaner() : coords(), beginTime(), endTime()
{
    
}

Cleaner::~Cleaner()
{
}
