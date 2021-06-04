#if !defined(CONSOLE_H)
#define CONSOLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <locale.h>

#include <ctime>
#include "../Control/Control.h"
#include "../Model/Cleaner.h"

using namespace std;

class Console
{

private:
    Control airWatch;

    void split(const string &chaine, char delimiteur, vector<string> &elements);
    // Sépare une chaîne de caractère en fonction d'un délimiteur

    bool formatLLR(string choice);
    // Vérification du format d'une entrée latitude;longitude;rayon pour des statistiques
    // Cette fonction renvoie :
    //   - vrai, si le format est conforme
    //   - faux, si le format n'est pas conforme

    bool formatIR(string choice);
    // Vérification du format d'une entrée ID;rayon pour un cleaner
    // Cette fonction renvoie :
    //   - vrai, si le format est conforme
    //   - faux, si le format n'est pas conforme

    bool formatD(string choice);
    // Vérification du format d'une entrée JJ/MM/AAAA
    // Cette fonction renvoie :
    //   - vrai, si le format est conforme
    //   - faux, si le format n'est pas conforme

    bool formatDD(string choice);
    // Vérification du format d'une entrée JJ/MM/AAAA;JJ/MM/AAAA pour des statistiques
    // Cette fonction renvoie :
    //   - vrai, si le format est conforme
    //   - faux, si le format n'est pas conforme

    bool formatLLRDD(string choice);
    // Vérification du format d'une entrée latitude;longitude;rayon;JJ/MM/AAAA;JJ/MM/AAAA pour des statistiques
    // Cette fonction renvoie :
    //   - vrai, si le format est conforme
    //   - faux, si le format n'est pas conforme

    time_t parseDate(string date);
    // Parse une string ayant le format JJ/MM/AAAA, en date
    // Cette fonction renvoie la date parsée

public:
    Console(unordered_map<string, string> files);
    ~Console();

    void accueil();
    //Menu principal

    void menuAgency();
    //Menu de l'agence

    void menuPrivateUser();
    // Menu de l'utilisateur privé

    void menuProvider();
    // Menu d'une entreprise

    void statistics();
    // Menu des statistiques

    void selectZone();
    // Qualité de l'air dans une zone spécifiée

    void similarSensor();

    void selectTime();
    // Qualité de l'air dans une période spécifiée

    void selectZoneAndTime();
    // Qualité de l'air dans une zone et une période spécifiées

    void badFormat(string menu);
    // Retour lors d'un mauvais format entré

    void points();
    // Affichage des points d'un utilisateur

    void impactAirCleaner();
    // Impact d'un airCleaner sur un rayon donné
};
#endif