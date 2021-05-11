#include "Provider.h"

void Provider::addCleaner(string cleanerId)
{
    this->cleaners.push_back(cleanerId);
}

Provider::Provider(string login) : User(login)
{
    this->cleaners = vector<string>();
}
Provider::~Provider() {}