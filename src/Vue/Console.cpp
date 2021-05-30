#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <stdexcept>

#include <ctime>
#include "../Control/Control.h"
#include "../Model/Cleaner.h"

using namespace std;

class Console
{

private:
    /* data */
    
    Control airWatch;
public:
    Console(unordered_map<string, string> files);
    ~Console();

    void menuAgency();
    void menuPrivateUser();
    void menuProvider();
    void statistics();
    void selectZone();
    void selectTime();
    void selectZoneAndTime();
    void badFormat(string menu);
    void points();
    void impactAirCleaner();

    void split(const string &chaine, char delimiteur, vector<string> &elements);
    bool formatLLR(string choice);
    bool formatIR(string choice);
};

int main(int argc, char **argv)
{
    unordered_map<string, string> files = {
        {"attributes", "../../data/attributes.csv"},
        {"cleaners", "../../data/cleaners.csv"},
        {"providers", "../../data/providers.csv"},
        {"measurements", "../../data/measurements.csv"},
        {"sensors", "../../data/sensors.csv"},
        {"users", "../../data/users.csv"},
        {"usersUntrusted", "../../data/usersUntrusted.csv"}};

    Console airWatch(files);

    time_t timer;
    struct tm y2k = {0};
    double seconds;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 119; y2k.tm_mon = 11; y2k.tm_mday = 1;

    timer=mktime(&y2k);
    cout<<asctime(localtime(&timer))<<endl;



    // cout<<airWatch.formatIR("192;128")<<endl;
    // cout<<airWatch.formatLLR("192.5{128")<<endl;
    // cout<<airWatch.formatLLR("ici;128");
    return 0;
}

bool Console::formatIR(string choice){
    vector<string> elementDuChoice ;
    char delimiteur = ';';
    split(choice, delimiteur , elementDuChoice);

    float temp;
    try{
        int cpt=0;
        for(vector<string>::iterator it = elementDuChoice.begin();it!=elementDuChoice.end();it++){
            string test=(*it);
            if(cpt == 0 )
                temp = stoi(test);
            if( cpt == 1 )
                temp = stof(test);
            cpt++;
            cout<<temp<<endl;
        }
        if(cpt!=2){
            return false;
        }

    }catch(exception &e){//invalid_argument &e){
        return false;
    }

    return true;
}

bool Console::formatLLR(string choice){
    vector<string> elementDuChoice ;
    char delimiteur = ';';
    split(choice, delimiteur , elementDuChoice);

    try{
        int cpt=0;
        for(vector<string>::iterator it = elementDuChoice.begin();it!=elementDuChoice.end();it++){
            string test=(*it);
            float temp = stof(test);
            cpt++;
        }
        if(cpt!=3){
            return false;
        }

    }catch(exception &e){//invalid_argument &e){
        return false;
    }

    return true;
}

void Console::split(const string &chaine, char delimiteur, vector<string> &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}


Console::Console(unordered_map<string,string> files):airWatch(files)
{
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                              Bienvenue sur AirWatcher                           +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+      - Vous faites parti de l'agence tapez               1                      +"<<endl;
    cout<<"+      - Vous êtes un utilisateur privé tapez              2                      +"<<endl;
    cout<<"+      - Vous faites parti d'une entreprise tapez          3                      +"<<endl;
    cout<<"+      - Vous souhaitez quitter l'application tapez        4                      +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            menuAgency();
        }else if(strcmp(choice,"2")==0){
            menuPrivateUser();
        }else if(strcmp(choice,"3")==0){
            menuProvider();
        }
        
    }
}

void Console::menuAgency(){
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                AirWatcher                                       +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+      - Pour Accéder aux statistiques tapez                          1           +"<<endl;
    cout<<"+      - Pour inscrire un nouveau fournisseur (privé) tapez           2           +"<<endl;
    cout<<"+      - Pour consulter l'impact d'un AirCleaner                      3           +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            statistics();
        }else if(strcmp(choice,"2")==0){
            cout<<"Cette fonctionnalité n'a pas été implémentée"<<endl;
        }else if(strcmp(choice,"3")==0){
            impactAirCleaner();
        }
    }
}


void Console::menuPrivateUser(){
    
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                AirWatcher                                       +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+      - Pour Accéder aux statistiques tapez                          1           +"<<endl;
    cout<<"+      - Pour consulter le solde de points tapez                      2           +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            statistics();
        }else if(strcmp(choice,"2")==0){
            points();
        }
    }
}

void Console::menuProvider(){
    
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                AirWatcher                                       +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+      - Pour Accéder aux statistiques tapez                          1           +"<<endl;
    cout<<"+      - Pour consulter l'impact d'un AirCleaner                      2           +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            statistics();
        }else if(strcmp(choice,"2")==0){
            impactAirCleaner();
        }
    }
}
void Console::impactAirCleaner(){
    //========================================Pour consulter l'impact d'un AirCleaner========================================
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+  Entrez l'id du AirCleaner voulu et le rayon autour de ce dernier au format     +"<<endl;
    cout<<"+                                     \"ID;rayon(m)\"                             +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(formatIR(choice)){
        //Pour une commande au bon format
        vector<string> elementDuChoice ;
        char delimiteur = ';';
        split(choice, delimiteur , elementDuChoice);
        vector<string>::iterator it=elementDuChoice.begin();
        string id="Cleaner"+*it;
        it++;
        string rayon=*it;
        
        
        Cleaner monCleaner=airWatch.data.cleaners.at(id);
        vector<int> impactAirCleaner=airWatch.getImpact(monCleaner, stoi(rayon));
        for(vector<int>::iterator it = impactAirCleaner.begin();it!=impactAirCleaner.end();it++){
            int test=(*it);
            cout<<test<<endl;
        }

        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                         Sur ce rayon le AirCleaner "<<id<<"                          +"<<endl;
        cout<<"+                               À un impact de XX,XX%                             +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    }else{
        badFormat("airCleaner1");
    }
}

void Console::points(){
    //===========================================Pour consulter le solde de points==========================================

    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+                               Vous avez actuellement                            +"<<endl;
    cout<<"+                                     XXXX point(s)                               +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;

}


void Console::statistics(){
    //=============================================Pour accéder aux statistiques=============================================
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+      - Pour sélectionner une zone tapez                         1               +"<<endl;
    cout<<"+      - Pour sélectionner une période de temps tapez             2               +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+    Vous pouvez combiner les 2 fonctionnalitées précédentes en tapant 3          +"<<endl;
    cout<<"+  Pour voir les statistiques sur toutes la zone sans limitations sur la période  +"<<endl;
    cout<<"+  faites \"Entrer\"                                                              +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;

    char choice[100];
    fscanf(stdin,"%99s",choice);
    
    if(strcmp(choice,"1")==0){
        selectZone();
    }else if(strcmp(choice,"2")==0){
        selectTime();
    }else if(strcmp(choice,"3")==0){
        selectZoneAndTime();
    }
          
}

void Console::selectZone(){
    //Pour 1 (seul):
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+         Entrez les coordonnées et le rayon autour du point au format            +"<<endl;
    cout<<"+                            \"latitude;longitude;rayon(m)\"                      +"<<endl;
    cout<<"+  Vous pouvez sélectionner un rayon nul si vous voulez accéder aux valeurs de la +"<<endl;
    cout<<"+                        qualité de l'air pour un point précis                    +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(formatLLR(choice)){ 
        
        //Pour une commande au bon format
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                      La valeur de la qualité de l\'air est                       +"<<endl;
        cout<<"+                                     XXX,XX                                      +"<<endl;
        cout<<"+         ------------------------------------------------------------            +"<<endl;
        cout<<"+         |    O3     |     SO2        |    NO2        |   PM10      |            +"<<endl;
        cout<<"+         |----------------------------------------------------------|            +"<<endl;
        cout<<"+         |  XXX,XX   |    XXX,XX      |   XXX,XX      |  XXX,XX     |            +"<<endl;
        cout<<"+         ------------------------------------------------------------            +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    }else{
        badFormat("stats");
    }
}

void Console::selectTime(){
    //Pour 2 (seul)
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+                        Entrez la période voulue au format                       +"<<endl;
    cout<<"+                              \"JJ/MM/AAAA;JJ/MM/AAAA\"                          +"<<endl;
    cout<<"+ Vous pouvez mettre deux fois la même date si vous voulez accéder aux valeurs de +"<<endl;
    cout<<"+                     qualité de l'air pour une date précise                      +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(true){                               //if(format(choice))
        //Pour une commande au bon format
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                      La valeur de la qualité de l'air est                       +"<<endl;
        cout<<"+                                     XXX,XX                                      +"<<endl;
        cout<<"+         ------------------------------------------------------------            +"<<endl;
        cout<<"+         |    O3     |     SO2        |    NO2        |   PM10      |            +"<<endl;
        cout<<"+         |----------------------------------------------------------|            +"<<endl;
        cout<<"+         |  XXX,XX   |    XXX,XX      |   XXX,XX      |  XXX,XX     |            +"<<endl;
        cout<<"+         ------------------------------------------------------------            +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    }else{
        badFormat("stats");
    }
}

void Console::selectZoneAndTime(){
    //Pour 3
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+Entrez les coordonnées et le rayon autour du point ainsi que la période au format+"<<endl;
    cout<<"+              \"latitude;longitude;rayon(m);JJ/MM/AAAA;JJ/MM/AAAA\"              +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(true){                               //if(format(choice))
        vector<string> elementDuChoice ;
        char delimiteur = ';';
        split(choice, delimiteur , elementDuChoice);
        vector<string>::iterator it=elementDuChoice.begin();
        float latitude=stof(*it);
        it++;
        float longitude=stof(*it);
        it++;
        int rayon=stoi(*it);
        it++;
        time_t start;
        it++;
        time_t end;

        struct tm y2k = {0};
        
        y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
        y2k.tm_year = 119; y2k.tm_mon = 0; y2k.tm_mday = 1;

        start=mktime(&y2k);
        cout<<"start :"<<asctime(localtime(&start))<<endl;
        y2k.tm_mon=1;
        end=mktime(&y2k);
        cout<<"end :"<<asctime(localtime(&end))<<endl;
        

        Measure airQuality=airWatch.getAirQuality(Coords(latitude, longitude),rayon,start, end);
        int indice=airQuality.atmosIndex();
        cout<<"qualité de l'air :"<<indice<<endl;
        cout<<"O3 :"<<airQuality.O3<<endl;
        cout<<"SO2 :"<<airQuality.SO2<<endl;
        cout<<"NO2 :"<<airQuality.NO2<<endl;
        cout<<"PM10 :"<<airQuality.PM10<<endl;

        //Pour une commande au bon format
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                      La valeur de la qualité de l'air est                       +"<<endl;
        cout<<"+                                     XXX,XX                                      +"<<endl;
        cout<<"+         ------------------------------------------------------------            +"<<endl;
        cout<<"+         |    O3     |     SO2        |    NO2        |   PM10      |            +"<<endl;
        cout<<"+         |----------------------------------------------------------|            +"<<endl;
        cout<<"+         |  XXX,XX   |    XXX,XX      |   XXX,XX      |  XXX,XX     |            +"<<endl;
        cout<<"+         ------------------------------------------------------------            +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    }else{
        badFormat("stats");
    }
}

void Console::badFormat(string menu){
    //Pour une commande mal formatée:
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"|                                 Format non conforme                             |"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    //-> menu précédent
    
    if(strcmp(menu.c_str(),"stats")==0){
        statistics();
    }else if(strcmp(menu.c_str(),"airCleaner1")==0){
        impactAirCleaner();
    }
}



Console::~Console()
{
}


