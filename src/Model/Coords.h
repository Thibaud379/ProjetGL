#if !defined(COORDS_H)
#define COORDS_H

#include <iostream>

const float EARTHRADIUS = 6371;
using namespace std;
class Coords
{

private:
    float latitude;
    float longitude;

public:
    float dist(const Coords &c);
    Coords(float latitude, float longitude);
    Coords();
    ~Coords();
    friend ostream &operator<<(ostream &, const Coords &);
};

#endif