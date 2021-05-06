#if !defined(ADMIN_H)
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:
    Admin(string login);
    ~Admin();
};

#endif