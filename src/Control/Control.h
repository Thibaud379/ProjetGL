#if !defined(CONTROL_H)
#define CONTROL_H

#include "AirWatcherIO.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Control
{
private:
    /* data */
    AirWatcherIO airWatcherIO;
    vector<Sensor> findCloseSensors(Coords coords, int radius);
    // Cherche les capteurs situés dans une zone
    // Cette fonction renvoie :
    //  - un vecteur contenant les Capteurs se trouvant dans la zone spécifiée

public:
    Data &data;
    list<pair<float, Sensor>> *findSimilarSensor(Sensor target, float deltaMax, time_t date);
    Measure getAirQuality(Coords coords, int radius, time_t start, time_t end);
    // alcul de la qualité de l'air avec une moyenne des mesures sur une zone et une période donnée 
    // Cette fonction renvoie :
    //  -  la moyenne de toutes les mesures de cette zone pendant une période 
    
    vector<pair<int,int>> getImpact(Cleaner target, int radius);
    // Calcul de l'impact d'un Cleaner en fonction du rayon
    // Cette fonction renvoie un vecteur contenant :
    //  -  le rayon 
    //  -  la variation de l'indice ATMO sur ce rayon

    Control();
    Control(unordered_map<string, string> files);
    ~Control();
};
#endif