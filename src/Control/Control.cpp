
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

vector<Sensor> findCloseSensors(Coords coordonnees, int rayon, Data *d)
{
    unordered_map<string, Sensor> *mesSensors = d->sensors;
    vector<Sensor> capteurDansLaZone;

    for (unordered_map<string, Sensor>::iterator it = (*mesSensors).begin(); it != (*mesSensors).end(); it++)
    {
        Sensor tmp = it->second;
        Coords lesCoords = tmp.getCoords();
        if (coordonnees.dist(&lesCoords) < rayon)
        {
            capteurDansLaZone.push_back(it->second);
        }
    }

    return capteurDansLaZone;
}

int calcAirQuality(Coords coordonnees, int rayon, time_t datDebut, time_t datFin, Data *d)
{
    Measure m = {0, 0, 0, 0};
    int nbLMesurePriseEnCompte = 0;
    vector<Sensor> capteursDeLaZone;
    capteursDeLaZone = findCloseSensors(coordonnees, rayon, d);

    for (vector<Sensor>::iterator i = capteursDeLaZone.begin(); i != capteursDeLaZone.end(); i++)
    {

        map<time_t, Measure> mesuresCapteur;
        mesuresCapteur = *(i->getMeasure());

        for (map<time_t, Measure>::iterator j = mesuresCapteur.begin(); j != mesuresCapteur.end(); j++)
        {
            if (difftime(j->first, datDebut) < 0 && difftime(datFin, j->first) > 0)
            {
                nbLMesurePriseEnCompte++;
                m.NO2 += j->second.NO2;
                m.SO2 += j->second.SO2;
                m.PM10 += j->second.PM10;
                m.O3 += j->second.O3;
            }
        }
    }
    m.NO2 /= nbLMesurePriseEnCompte;
    m.SO2 /= nbLMesurePriseEnCompte;
    m.PM10 /= nbLMesurePriseEnCompte;
    m.O3 /= nbLMesurePriseEnCompte;

    return Sensor::atmosIndex(m);
}

vector<int> determinerImpacte(Cleaner monCleaner, int rayon, Data *d)
{
    time_t debutCleaner = monCleaner.getTime().second;
    int tabAvant[25];
    int tabApres[25];
    vector<int> tabEcart;
    for (int i = 0; i < 25; i++)
    {
        tabAvant[i] = calcAirQuality(monCleaner.getCoords(), (int)(i * rayon / 25), time(0), debutCleaner, d);
    }
    for (int i = 0; i < 25; i++)
    {
        tabApres[i] = calcAirQuality(monCleaner.getCoords(), (int)(i * rayon / 25), debutCleaner, time(0), d);
    }
    for (int i = 0; i < 25; i++)
    {
        tabEcart.push_back(tabAvant[i] - tabApres[i]);
    }

    return tabEcart;
}
