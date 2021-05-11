#if !defined(PUSER_H)
#define PUSER_H

#include <vector>
#include "User.h"

class PrivateUser : public User
{
private:
    bool trusted;
    vector<string> sensors;

public:
    void addSensor(string sensorId);
    vector<string> *getSensors() { return &this->sensors; }

    void setTrusted(bool trusted) { this->trusted = trusted; }
    bool isTrusted() { return this->trusted; }
    
    PrivateUser(string login = "");
    ~PrivateUser();
};

#endif