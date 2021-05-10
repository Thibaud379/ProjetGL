
#include "AirWatcherIO.h"
#include <iostream>
#include <list>

int main(int argc, char **argv)
{
    unordered_map<string, string> files = {
        {"attributes", "data/attributes.csv"},
        {"cleaners", "data/cleaners.csv"},
        {"providers", "data/providers.csv"},
        {"measurements", "data/measurements.csv"},
        {"sensors", "data/sensors.csv"},
        {"users", "data/users.csv"},
        {"usersUntrusted", "data/usersUntrusted.csv"}};

    Data *d = AirWatcherIO::loadFiles(files);
    for (auto it : *(d->sensors->at("Sensor0").getMeasure()))
    {
        cout << it.first << ": " << it.second.NO2 << ", " << it.second.O3 << endl;
    }

    return 0;
}

list<pair<Sensor, float>> trouverCapteurSimilaire(Sensor mySensor, float ecartMax, unordered_map<string, Sensor> *sensors, time_t date)
{
    //Liste des capteurs similaires au capteur de référence
    list<pair<Sensor, float>> result;

    //Mesures pour le capteur de référence :
    Measure ref = mySensor.getMeasure()->find(date)->second;

    float ecartNO2, ecartSO2, ecartO3, ecartPM10;
    float ecart;

    unordered_map<string, Sensor>::iterator it;
    for (auto it : *sensors)
    {
        //Mesures pour le capteur considéré
        //Tester find et at
        Measure capt = it.second.getMeasure()->at(date);

        //calcul de l'écart au capteur de référence
        ecartNO2 = (ref.NO2 - capt.NO2) / ref.NO2;
        ecartO3 = (ref.O3 - capt.O3) / ref.O3;
        ecartPM10 = (ref.PM10 - capt.PM10) / ref.PM10;
        ecartSO2 = (ref.SO2 - capt.SO2) / ref.SO2;

        ecart = abs(ecartNO2) + abs(ecartO3) + abs(ecartO3) + abs(ecartPM10);

        //Si l'écart est inférieur à ecartMax : on rajoute le capteur et son écart dans la liste
        if (ecart <= ecartMax)
        {
            pair<Sensor, float> coupleCapteurEcart(it.second, ecart);
            //coupleCapteurEcart.first=it;
            //coupleCapteurEcart.second=ecart;

            //Placement de la paire au bon endroit dans la liste (liste triée par écart croissant)
            if (result.empty())
            {
                result.push_front(coupleCapteurEcart);
            }
            else
            {
                auto rank = result.begin();
                rank++;
                for (auto iterate : result)
                {
                    if (iterate.second > coupleCapteurEcart.second)
                    {
                        result.insert(rank, coupleCapteurEcart);
                        break;
                    }
                }
            }
        }
    }

    return result;
}