#include "Console.h"
#include <time.h>

/*int main(int argc, char **argv)
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

    return 0;
}*/


// Constructeur
Console::Console(unordered_map<string,string> files):airWatch(files)
{
    accueil(); //Affiche le menu d'accueil
}

// Menu d'accueil
void Console::accueil(){
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
    // Selon le choix de l'utilisateur, affichage du menu correspondant
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            menuAgency();
        }else if(strcmp(choice,"2")==0){
            menuPrivateUser();
        }else if(strcmp(choice,"3")==0){
            menuProvider();
        }
        fscanf(stdin,"%99s",choice);        
    }
    exit(0);
}

// Menu de l'agence
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
    // Selon le choix de l'utilisateur, affichage de la fonctionnalité correspondante
    while (strcmp(choice,"4")!=0){
        if(strcmp(choice,"1")==0){
            statistics();
        }else if(strcmp(choice,"2")==0){
            cout<<"Cette fonctionnalité n'a pas été implémentée"<<endl;
            menuAgency();
        }else if(strcmp(choice,"3")==0){
            impactAirCleaner();
        }
        fscanf(stdin,"%99s",choice);
    }
    //Retour au menu d'accueil
    accueil();
}

// Menu d'un utilisateur privé
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
    // Selon le choix de l'utilisateur, affichage de la fonctionnalité correspondante
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            statistics();
        }else if(strcmp(choice,"2")==0){
            points();
        }
    }
    //Retour au menu d'accueil
    accueil();
}

// Menu d'une entreprise
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
    // Selon le choix de l'utilisateur, affichage de la fonctionnalité correspondante
    while (strcmp(choice,"4")!=0)
    {
        if(strcmp(choice,"1")==0){
            statistics();
        }else if(strcmp(choice,"2")==0){
            impactAirCleaner();
        }
    }
    //Retour au menu d'accueil
    accueil();
}

// Impact d'un airCleaner sur un rayon donné
void Console::impactAirCleaner(){
    //========================================Pour consulter l'impact d'un AirCleaner========================================
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+  Entrez l'id du AirCleaner voulu et le rayon autour de ce dernier au format     +"<<endl;
    cout<<"+                             \"n°duCleaner;rayon(km)\"                             +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(formatIR(choice)){    //Si le choix de l'utilisateur est entré dans le bon format
        //On récupère les éléments en paramètre
        vector<string> elementDuChoice ;
        char delimiteur = ';';
        split(choice, delimiteur , elementDuChoice);
        vector<string>::iterator it=elementDuChoice.begin();
        string id="Cleaner"+*it;
        it++;
        string rayon=*it;
        
        try{
            //Calcul du temps
            float temps;
            clock_t start, end; 
            start = clock();
            // Récupération du cleaner
            Cleaner monCleaner=airWatch.data.cleaners.at(id);
            end = clock();
            temps = (float)(end - start);
            // Calcul de son impact
            vector<pair<int,int>> impactAirCleaner=airWatch.getImpact(monCleaner, stoi(rayon));
            //Affichage du résultat
            cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
            cout<<"+                                     AirWatcher                                  +"<<endl;
            cout<<"+                                                                                 +"<<endl;
            cout<<"+                         Sur ce rayon le AirCleaner "<<id<<"                     +"<<endl;
            cout<<"+                                                                                 +"<<endl;

            for(vector<pair<int,int>>::iterator it = impactAirCleaner.begin();it!=impactAirCleaner.end();it++){
                int dist=(*it).first;
                // Esthétique d'affichage
                if(dist/10==0){
                    cout<<"+             Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<"                +"<<endl;
                }else if(dist/100==0){
                    cout<<"+             Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<"               +"<<endl;
                }else if(dist/1000==0){
                    cout<<"+             Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<"              +"<<endl;
                }else if(dist/10000==0){
                    cout<<"+             Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<"             +"<<endl;
                }else {
                    cout<<"+             Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<"            +"<<endl;
                }    
            }
            cout<<"+                                                                                 +"<<endl;
            cout<<"+                      Temps de calcul : " << temps/CLOCKS_PER_SEC <<"s                                   +"<<endl;
            cout<<"+                                                                                 +"<<endl;
            cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        }catch(exception &e){
            cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
            cout<<"|                           Aucun Cleaner trouvé avec cet ID :                    |"<<endl;
            cout<<"|                                       "<<id<<"                                  |"<<endl;
            cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        }
        //Retour au menu d'accueil
        accueil();
    }else{//Si le format n'est pas bon, retour au menu impactCleaner
        badFormat("airCleaner1");
    }
}

// Affichage des points d'un utilisateur
void Console::points(){
    //===========================================Pour consulter le solde de points==========================================
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                  Cette fonctionnalité n'a pas encore été développée             +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+                               Vous avez actuellement                            +"<<endl;
    cout<<"+                                     1500 point(s)                               +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    //Retour au menu d'accueil
    accueil();
}

// Menu des statistiques
void Console::statistics(){
    //=============================================Pour accéder aux statistiques=============================================
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+      - Pour sélectionner une zone tapez                         1               +"<<endl;
    cout<<"+      - Pour sélectionner une période de temps tapez             2               +"<<endl;
    cout<<"+      - Pour combiner les 2 fonctionnalitées précédentes tapez   3               +"<<endl;
    cout<<"+      - Pour revenir à l'accueil tapez                           4               +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    // Selon le choix de l'utilisateur, affichage de la fonctionnalité correspondante 
    if(strcmp(choice,"1")==0){
        selectZone();
    }else if(strcmp(choice,"2")==0){
        selectTime();
    }else if(strcmp(choice,"3")==0){
        selectZoneAndTime();
    }else{
        accueil();
    }       
}

//Statistiques avec une latitude, une longitude et un rayon
void Console::selectZone(){
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+         Entrez les coordonnées et le rayon autour du point au format            +"<<endl;
    cout<<"+                            \"latitude;longitude;rayon(km)\"                     +"<<endl;
    cout<<"+  Vous pouvez sélectionner un rayon nul si vous voulez accéder aux valeurs de la +"<<endl;
    cout<<"+                        qualité de l'air pour un point précis                    +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(formatLLR(choice)){      //Si le choix de l'utilisateur est entré dans le bon format
        //On récupère les éléments en paramètre
        vector<string> elementDuChoice ;
        char delimiteur = ';';
        split(choice, delimiteur , elementDuChoice);
        vector<string>::iterator it=elementDuChoice.begin();
        float latitude=stof(*it);
        it++;
        float longitude=stof(*it);
        it++;
        int rayon=stoi(*it);

        time_t start=parseDate("01/01/2019");      
        time_t end=time(0);  

        //Calcul de la qualité de l'air de la première mesure jusqu'à aujourd'hui
        Measure airQuality=airWatch.getAirQuality(Coords(latitude, longitude),rayon,start, end);
        int indice=airQuality.atmosIndex();
        
        cout<<setprecision(4);
        //Affichage du résultat
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                            L'indice ATMO de l'air est de :                      +"<<endl;
        cout<<"+                                        "<<indice<<"                                        +"<<endl;
        cout<<"+           ------------------------------------------------------                +"<<endl;
        cout<<"+           |     O3    |     SO2     |     NO2     |    PM10    |                +"<<endl;
        cout<<"+           |----------------------------------------------------|                +"<<endl;
        cout<<"+           |   "<<airQuality.O3<<"   |    "<<airQuality.SO2<<"    |   "<<airQuality.NO2<<"     |   "<<airQuality.PM10<<"    |                +"<<endl;
        cout<<"+           ------------------------------------------------------                +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        //Retour au menu d'accueil
        accueil();
    }else{//Si le format n'est pas bon, retour au menu statistics
        badFormat("stats");
    }
}

//Statistiques avec une période définie
void Console::selectTime(){
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
    if(formatDD(choice)){  //Si le choix de l'utilisateur est entré dans le bon format
        //On récupère les éléments en paramètre
        vector<string> elementDuChoice ;
        char delimiteur = ';';
        split(choice, delimiteur , elementDuChoice);
        vector<string>::iterator it=elementDuChoice.begin();
        time_t start=parseDate(*it);
        it++;
        time_t end=parseDate(*it);      
        
        //Calcul de la qualité de l'air sur toute la Terre
        Measure airQuality=airWatch.getAirQuality(Coords(0, 0),Coords(0,0).dist(Coords(90,180)),start, end);
        int indice=airQuality.atmosIndex();
        
        cout<<setprecision(4);
        //Affichage du résultat
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                            L'indice ATMO de l'air est de :                      +"<<endl;
        cout<<"+                                        "<<indice<<"                                        +"<<endl;
        cout<<"+           ------------------------------------------------------                +"<<endl;
        cout<<"+           |     O3    |     SO2     |     NO2     |    PM10    |                +"<<endl;
        cout<<"+           |----------------------------------------------------|                +"<<endl;
        cout<<"+           |   "<<airQuality.O3<<"   |    "<<airQuality.SO2<<"    |   "<<airQuality.NO2<<"     |   "<<airQuality.PM10<<"    |                +"<<endl;
        cout<<"+           ------------------------------------------------------                +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        //Retour au menu d'accueil
        accueil();
    }else{//Si le format n'est pas bon, retour au menu statistics
        badFormat("stats");
    }
}

//Statistiques avec une latitude, une longitude, un rayon et une période définie
void Console::selectZoneAndTime(){
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"+                                     AirWatcher                                  +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+Entrez les coordonnées et le rayon autour du point ainsi que la période au format+"<<endl;
    cout<<"+              \"latitude;longitude;rayon(km);JJ/MM/AAAA;JJ/MM/AAAA\"             +"<<endl;
    cout<<"+                                                                                 +"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    char choice[100];
    fscanf(stdin,"%99s",choice);
    if(formatLLRDD(choice)){    //Si le choix de l'utilisateur est entré dans le bon format
        //On récupère les éléments en paramètre                           
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
        time_t start=parseDate(*it);
        it++;
        time_t end=parseDate(*it);

        //Calcul du temps
        float duree;
        clock_t debut, fin; 
        debut = clock();
        //Calcul de la qualité de l'air
        Measure airQuality=airWatch.getAirQuality(Coords(latitude, longitude),rayon,start, end);
        int indice=airQuality.atmosIndex();

        fin = clock();
        duree = (float)(fin - debut);
        cout << "Temps de calcul : " << duree/CLOCKS_PER_SEC <<"s" <<endl;

        
        cout<<setprecision(4);
        //Affichage du résultat
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"+                                     AirWatcher                                  +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                            L'indice ATMO de l'air est de :                      +"<<endl;
        cout<<"+                                        "<<indice<<"                                        +"<<endl;
        cout<<"+           ------------------------------------------------------                +"<<endl;
        cout<<"+           |     O3    |     SO2     |     NO2     |    PM10    |                +"<<endl;
        cout<<"+           |----------------------------------------------------|                +"<<endl;
        cout<<"+           |   "<<airQuality.O3<<"   |    "<<airQuality.SO2<<"    |   "<<airQuality.NO2<<"     |   "<<airQuality.PM10<<"    |                +"<<endl;
        cout<<"+           ------------------------------------------------------                +"<<endl;
        cout<<"+                                                                                 +"<<endl;
        cout<<"+                       Temps de calcul : " << duree/CLOCKS_PER_SEC <<"s                                +"<<endl;
        cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        //Retour au menu d'accueil
        accueil();
    }else{ //Si le format n'est pas bon, retour au menu statistics
        badFormat("stats");
    }
}

//Si le format d'entrée n'est pas conforme, on renvoie le menu précédent
void Console::badFormat(string menu){
    //Pour une commande mal formatée:
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"|                                 Format non conforme                             |"<<endl;
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    
    if(strcmp(menu.c_str(),"stats")==0){
        statistics();
    }else if(strcmp(menu.c_str(),"airCleaner1")==0){
        impactAirCleaner();
    }
}

// Parse maDate ayant le format JJ/MM/AAAA, en date
time_t Console::parseDate(string maDate){
    time_t start;
    int yy, month, dd;
    struct tm date;
    const char *zStart = maDate.c_str();

    sscanf(zStart, "%d/%d/%d", &dd, &month, &yy);
    date.tm_year = yy - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = dd;
    date.tm_hour = 12;
    date.tm_min = 0;
    date.tm_sec = 0;
    date.tm_isdst = -1;

    start = mktime(&date);
    return start;
}

// Vérification du format d'une entrée ID;rayon pour un cleaner
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
        }
        if(cpt!=2){
            return false;
        }
    }catch(exception &e){
        return false;
    }
    return true;
}
// Vérification du format d'une entrée latitude;longitude;rayon pour des statistiques
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
    }catch(exception &e){
        return false;
    }
    return true;
}

// Vérification du format d'une entrée JJ/MM/AAAA
bool Console::formatD(string choice){
    vector<string> elementDuChoice ;
    char delimiteur = '/';
    split(choice, delimiteur , elementDuChoice);
    try{
        int cpt=0;
        for(vector<string>::iterator it = elementDuChoice.begin();it!=elementDuChoice.end();it++){
            string test=(*it);
            int number = stoi(test);
            cpt++;
        }
        if(cpt!=3){
            return false;
        }
    }catch(exception &e){
        return false;
    }
    return true;
}

// Vérification du format d'une entrée JJ/MM/AAAA;JJ/MM/AAAA pour des statistiques
bool Console::formatDD(string choice){
    vector<string> elementDuChoice ;
    char delimiteur = ';';
    split(choice, delimiteur , elementDuChoice);
    try{
        int cpt=0;
        for(vector<string>::iterator it = elementDuChoice.begin();it!=elementDuChoice.end();it++){
            string test=(*it);
            if(formatD(test))
            {
                cpt++;
            }            
        }
        if(cpt!=2){
            return false;
        }
    }catch(exception &e){
        return false;
    }
    return true;
}

// Vérification du format d'une entrée latitude;longitude;rayon;JJ/MM/AAAA;JJ/MM/AAAA pour des statistiques
bool Console::formatLLRDD(string choice){
    vector<string> elementDuChoice ;
    char delimiteur = ';';
    split(choice, delimiteur , elementDuChoice);
    try{
        int cpt=0;
        for(vector<string>::iterator it = elementDuChoice.begin();it!=elementDuChoice.end();it++){
            string test=(*it);
            if(cpt < 3 )
            {
                float temp = stof(test);
                cpt++;
                
            }else if(cpt >= 3) {
                if(formatD(test)){
                    cpt++;
                }
            }
        }     
        if(cpt!=5){
            return false;
        }
    }catch(exception &e){
        return false;
    }
    return true;
}

// Sépare une chaîne de caractère en fonction d'un délimiteur
void Console::split(const string &chaine, char delimiteur, vector<string> &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}

//Destructeur de la classe
Console::~Console()
{
}


