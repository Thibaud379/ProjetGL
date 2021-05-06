#if !defined(COORDS_H)
#define COORDS_H

class Coords
{
private:
    float latitude;
    float longitude;

public:
    Coords();
    Coords(float latitude, float longitude);
    ~Coords();
};

#endif