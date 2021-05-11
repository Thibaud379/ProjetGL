#include "PrivateUser.h"

void PrivateUser::addSensor(string sensorId)
{
    this->sensors.push_back(sensorId);
}

PrivateUser::PrivateUser(string login) : User(login)
{
    this->trusted = true;
}

PrivateUser::~PrivateUser()
{
}