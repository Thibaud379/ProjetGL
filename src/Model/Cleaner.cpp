#include "Cleaner.h"

Cleaner::Cleaner(Coords c, time_t begin, time_t end)
{
    this->coords = c;
    this->beginTime = begin;
    this->endTime = end;
}
Cleaner::Cleaner() : coords(), beginTime(), endTime()
{
}
Cleaner::~Cleaner()
{
}
