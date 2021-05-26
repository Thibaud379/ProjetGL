
#include "Control.h"
#include <algorithm>

Control::Control(unordered_map<string, string> files)
{
    data = AirWatcherIO::loadFiles(files);
}

Control::~Control()
{
    data->free();
    delete data;
}

bool cmp(const pair<float, Sensor> &lhs, const pair<float, Sensor> &rhs) { return lhs.first < rhs.first; }

list<pair<float, Sensor>> Control::findSimilarSensor(Sensor target, float deltaMax, time_t date)
{
    //Liste des capteurs similaires au capteur de référence
    list<pair<float, Sensor>> result;

    //Mesures pour le capteur de référence :
    Measure ref = target.getMeasure()->find(date)->second;

    float deltaNO2, deltaSO2, deltaO3, deltaPM10;
    float delta;

    unordered_map<string, Sensor>::iterator it;
    for (auto it : *data->sensors)
    {
        //Mesures pour le capteur considéré
        //Tester find et at
        Measure mes = it.second.getMeasure()->find(date)->second;

        //calcul de l'écart au capteur de référence
        deltaNO2 = (ref.NO2 - mes.NO2) / ref.NO2;
        deltaO3 = (ref.O3 - mes.O3) / ref.O3;
        deltaPM10 = (ref.PM10 - mes.PM10) / ref.PM10;
        deltaSO2 = (ref.SO2 - mes.SO2) / ref.SO2;

        delta = abs(deltaNO2) + abs(deltaO3) + abs(deltaSO2) + abs(deltaPM10);

        //Si l'écart est inférieur à deltaMax : on rajoute le capteur et son écart dans la liste
        if (delta <= deltaMax)
        {
            result.push_back(make_pair(delta, it.second));
        }
    }

    result.sort(cmp);
    return result;
}

vector<Sensor> Control::findCloseSensors(Coords coords, int radius)
{
    vector<Sensor> closeSensors;

    for (unordered_map<string, Sensor>::iterator it = data->sensors->begin(); it != data->sensors->end(); it++)
    {
        if (coords.dist(it->second.getCoords()) < radius)
        {
            closeSensors.push_back(it->second);
        }
    }
    return closeSensors;
}

int Control::getAirQuality(Coords coords, int radius, time_t start, time_t end)
{
    Measure m = {0, 0, 0, 0};
    int nbMeasures = 0;
    vector<Sensor> closeSensors = findCloseSensors(coords, radius);

    for (auto i : closeSensors)
    {

        map<time_t, Measure> *measures = i.getMeasure();

        for (auto j : *measures)
        {
            if (difftime(j.first, start) < 0 && difftime(end, j.first) > 0)
            {
                nbMeasures++;
                m.NO2 += j.second.NO2;
                m.SO2 += j.second.SO2;
                m.PM10 += j.second.PM10;
                m.O3 += j.second.O3;
            }
        }
    }
    m.NO2 /= nbMeasures;
    m.SO2 /= nbMeasures;
    m.PM10 /= nbMeasures;
    m.O3 /= nbMeasures;

    return Sensor::atmosIndex(m);
}

vector<int> Control::getImpact(Cleaner target, int radius)
{
    time_t debutCleaner = target.getTime().second;
    int before, after;
    vector<int> tabdelta;
    for (int i = 1; i < 25; i++)
    {
        before = getAirQuality(target.getCoords(), (int)(i * radius / 25), 0, debutCleaner);

        after = getAirQuality(target.getCoords(), (int)(i * radius / 25), debutCleaner, numeric_limits<time_t>::max());

        tabdelta.push_back(after - before);
    }

    return tabdelta;
}
