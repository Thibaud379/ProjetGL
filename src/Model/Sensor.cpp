#include "Sensor.h"

const int Measure::atmosIndex()
{
    int athmo = 1;
    const int max = 9;
    const int iO3[max] = {29, 54, 79, 104, 129, 149, 179, 209, 239};
    const int iSO2[max] = {39, 79, 119, 159, 199, 249, 299, 399, 499};
    const int iNO2[max] = {29, 54, 84, 109, 134, 164, 199, 274, 399};
    const int iPM10[max] = {6, 13, 20, 27, 34, 41, 49, 64, 79};

    for (int i = max - 1; i >= 0; i--)
    {
        if (this->O3 > iO3[i] || this->SO2 > iSO2[i] || this->NO2 > iNO2[i] || this->PM10 > iPM10[i])
        {
            athmo = i + 2;
            break;
        }
    }

    return athmo;
}

bool Sensor::addMeasure(time_t t, Measure m)
{
    return this->measures.emplace(t, m).second;
}

Sensor::Sensor(Coords coords, string id) : measures()
{
    this->coords = coords;
    this->id = id;
}

Sensor::~Sensor()
{
}
