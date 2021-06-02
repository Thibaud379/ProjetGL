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

// Cherche les capteurs situés dans une zone
vector<Sensor> Control::findCloseSensors(Coords coords, int radius)
{
    // Vecteur des Capteurs de la zone
    vector<Sensor> closeSensors;
    // Parcours de tous les capteurs du fichier
    for (auto it : data.sensors)
    {
        //Si la distance entre les coordonnées du capteur et les coordonnées spécifiées est inférieure au rayon
        if (coords.dist(it.second.getCoords()) <= radius) 
        {
            closeSensors.push_back(it.second); // On ajoute le capteur à la liste
        }
    }
    return closeSensors;
}

// Calcul de la qualité de l'air avec une moyenne des mesures sur une zone et une période donnée 
Measure Control::getAirQuality(Coords coords, int radius, time_t start, time_t end)
{
    Measure m = {0, 0, 0, 0};
    int nbMeasures = 0;
    // Récupération des capteurs de la zone spécifiée
    vector<Sensor> closeSensors = findCloseSensors(coords, radius);
    for (auto i : closeSensors)
    {        
        // Récupération des mesures d'un capteur de la zone
        map<time_t, Measure> measures = i.getMeasure();
        for (auto j : measures)
        {
            // Si la date de la mesure est comprise dans la période spécifiée
            if (difftime(start, j.first) <= 0 && difftime(end, j.first) >= 0)
            {
                nbMeasures++;
                // On ajoute les mesures
                m.add(j.second); 
            }
        }
    }
    // Moyenne des mesures récupérées sur la zone et la période
    m.div(nbMeasures);

    return m;
}

// Calcul de l'impact d'un Cleaner en fonction du rayon
vector<pair<int,int>> Control::getImpact(Cleaner target, int radius)
{
    // Récupération des dates de début et de fin de l'action du Cleaner
    time_t debutCleaner = target.getTime().first;
    time_t finCleaner = target.getTime().second;
    // Vecteur contenant le rayon et l'évolution de l'indice ATMO
    vector<pair<int,int>> tabdelta;
    // Découpage du rayon en 10 portions
    for (int i = 1; i < 11; i++){
        // Calcul de la qualité de l'air avant que le Cleaner n'est agit
        Measure before = getAirQuality(target.getCoords(), (int)(i * radius / 10), 0, debutCleaner);
        // Calcul de la qualité de l'air pendant la période où le Cleaner a agit
        Measure after = getAirQuality(target.getCoords(), (int)(i * radius / 10), debutCleaner, finCleaner);
        // Ajout du rayon et de l'évolution de l'indice ATMO au vecteur
        tabdelta.push_back(make_pair((int)(i * radius / 10),after.atmosIndex() -  before.atmosIndex())  );
    }
    return tabdelta;
}
