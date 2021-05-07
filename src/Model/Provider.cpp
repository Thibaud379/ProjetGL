#include "Provider.h"

void Provider::addCleaner(string cleanerId)
{
    this->cleaners.push_back(cleanerId);
}

Provider::Provider(vector<string> cleaners,string login) : User(login)
{
    this->cleaners = cleaners;
}

Provider::Provider(string login) : User(login) {}
Provider::~Provider() {}