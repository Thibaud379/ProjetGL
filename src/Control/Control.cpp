
#include "Control.h"
#include <algorithm>

Control::Control(unordered_map<string, string> files) : airWatcherIO(files), data(airWatcherIO.data)
{
}

Control::~Control()
{
}

bool cmp(const pair<float, Sensor> &lhs, const pair<float, Sensor> &rhs) { return lhs.first < rhs.first; }

list<pair<float, Sensor>> *Control::findSimilarSensor(Sensor target, float deltaMax, time_t date)
{
    //Liste des capteurs similaires au capteur de référence
    list<pair<float, Sensor>> *result = new list<pair<float, Sensor>>;

    //Mesures pour le capteur de référence :
    Measure ref = target.getMeasure().find(date)->second;

    float delt;
    for (auto it : data.sensors)
    {
        //Mesures pour le capteur considéré
        //Tester find et at
        Measure mes = it.second.getMeasure().find(date)->second;

        //calcul de l'écart au capteur de référence

        //Si l'écart est inférieur à deltaMax : on rajoute le capteur et son écart dans la liste
        delt = Measure::delta(ref, mes);
        if (delt <= deltaMax)
        {
            result->push_back(make_pair(delt, it.second));
        }
    }

    result->sort(cmp);
    return result;
}

vector<Sensor> Control::findCloseSensors(Coords coords, int radius)
{
    vector<Sensor> closeSensors;

    for (auto it : data.sensors)
    {
        if (coords.dist(it.second.getCoords()) < radius)
        {
            closeSensors.push_back(it.second);
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

        map<time_t, Measure> measures = i.getMeasure();

        for (auto j : measures)
        {
            if (difftime(j.first, start) < 0 && difftime(end, j.first) > 0)
            {
                nbMeasures++;
                m.add(j.second);
            }
        }
    }
    m.div(nbMeasures);

    return m.atmosIndex();
}

vector<int> Control::getImpact(Cleaner target, int radius)
{
    time_t debutCleaner = target.getTime().second;
    vector<int> tabdelta;
    for (int i = 1; i < 25; i++)
    {
        const int before = getAirQuality(target.getCoords(), (int)(i * radius / 25), 0, debutCleaner);

        const int after = getAirQuality(target.getCoords(), (int)(i * radius / 25), debutCleaner, numeric_limits<time_t>::max());

        tabdelta.push_back(after - before);
    }

    return tabdelta;
}
