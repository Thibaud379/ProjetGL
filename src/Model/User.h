#if !defined(USER_H)
#define USER_H

#include <string>

using namespace std;

class User
{
protected:
    string login;
    string password;
    bool connected;

public:
    bool connect();
    void disconnect();
    string getLogin() { return this->login; }
    User(string login);
    ~User();
};

#endif