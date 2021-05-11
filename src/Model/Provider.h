#if !defined(PROVIDER_H)
#define PROVIDER_H

#include <vector>
#include "User.h"

class Provider : public User
{
private:
    vector<string> cleaners;

public:
    void addCleaner(string cleanerId);
    vector<string> *getCleaners() { return &cleaners; }

    Provider(string login = "");
    ~Provider();
};

#endif