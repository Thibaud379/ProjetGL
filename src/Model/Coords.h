#if !defined(COORDS_H)
#define COORDS_H

const float EARTHRADIUS = 6371;

class Coords
{


private:

    float latitude;
    float longitude;

public:
    float dist(Coords* ce);
    Coords(float latitude, float longitude);
    Coords();
    ~Coords();
};

#endif