#include <time.h>
#include <vector>
#include <iostream>
#include <ctime>

#include "../Model/Sensor.h"
#include "../Model/Coords.h"
#include "../Model/Cleaner.h"
#include "AirWatcherIO.h"

using namespace std; 


int calculIndiceAthmo(float NO2, float SO2, float PM10, float O3)
{
    int athmo = 1;
    if(NO2>=0 && NO2 <=29){
        if(athmo<1){
            athmo =1;
        }
    }else if(NO2>29 && NO2 <=54){
        if(athmo<2){
            athmo =2;
        }
    }else if(NO2>54 && NO2 <=84){
        if(athmo<3){
            athmo =3;
        }
    }else if(NO2>84 && NO2 <=109){
        if(athmo<4){
            athmo =4;
        }
    }else if(NO2>109 && NO2 <=134){
        if(athmo<5){
            athmo =5;
        }
    }else if(NO2>134 && NO2 <=164){
        if(athmo<6){
            athmo =6;
        }
    }else if(NO2>164 && NO2 <=199){
        if(athmo<7){
            athmo =7;
        }
    }else if(NO2>199 && NO2 <=274){
        if(athmo<8){
            athmo =8;
        }
    }else if(NO2>274 && NO2 <=399){
        if(athmo<9){
            athmo =9;
        }
    }else if(NO2>=400){
        if(athmo<10){
            athmo =10;
        }
    }

    if(SO2>=0 && SO2 <=39){
        if(athmo<1){
            athmo =1;
        }
    }else if(SO2>39 && SO2 <=79){
        if(athmo<2){
            athmo =2;
        }
    }else if(SO2>79 && SO2 <=119){
        if(athmo<3){
            athmo =3;
        }
    }else if(SO2>119 && SO2 <=159){
        if(athmo<4){
            athmo =4;
        }
    }else if(SO2>159 && SO2 <=199){
        if(athmo<5){
            athmo =5;
        }
    }else if(SO2>199 && SO2 <=249){
        if(athmo<6){
            athmo =6;
        }
    }else if(SO2>249 && SO2 <=299){
        if(athmo<7){
            athmo =7;
        }
    }else if(SO2>299 && SO2 <=399){
        if(athmo<8){
            athmo =8;
        }
    }else if(SO2>399 && SO2 <=499){
        if(athmo<9){
            athmo =9;
        }
    }else if(SO2>=500){
        if(athmo<10){
            athmo =10;
        }
    }

    if(O3>=0 && O3 <=29){
        if(athmo<1){
            athmo =1;
        }
    }else if(O3>29 && O3 <=54){
        if(athmo<2){
            athmo =2;
        }
    }else if(O3>54 && O3 <=79){
        if(athmo<3){
            athmo =3;
        }
    }else if(O3>79 && O3 <=104){
        if(athmo<4){
            athmo =4;
        }
    }else if(O3>104 && O3 <=129){
        if(athmo<5){
            athmo =5;
        }
    }else if(O3>129 && O3 <=149){
        if(athmo<6){
            athmo =6;
        }
    }else if(O3>149 && O3 <=179){
        if(athmo<7){
            athmo =7;
        }
    }else if(O3>179 && O3 <=209){
        if(athmo<8){
            athmo =8;
        }
    }else if(O3>209 && O3 <=239){
        if(athmo<9){
            athmo =9;
        }
    }else if(O3>=240){
        if(athmo<10){
            athmo =10;
        }
    }
    
    if(PM10>=0 && PM10 <=6){
        if(athmo<1){
            athmo =1;
        }
    }else if(PM10>6 && PM10 <=13){
        if(athmo<2){
            athmo =2;
        }
    }else if(PM10>13 && PM10 <=20){
        if(athmo<3){
            athmo =3;
        }
    }else if(PM10>20 && PM10 <=27){
        if(athmo<4){
            athmo =4;
        }
    }else if(PM10>27 && PM10 <=34){
        if(athmo<5){
            athmo =5;
        }
    }else if(PM10>34 && PM10 <=41){
        if(athmo<6){
            athmo =6;
        }
    }else if(PM10>41 && PM10 <=49){
        if(athmo<7){
            athmo =7;
        }
    }else if(PM10>49 && PM10 <=64){
        if(athmo<8){
            athmo =8;
        }
    }else if(PM10>64 && PM10 <=79){
        if(athmo<9){
            athmo =9;
        }
    }else if(PM10>=80){
        if(athmo<10){
            athmo =10;
        }
    }

    return athmo; 

} 

vector<Sensor> chercherCapteurZone(Coords coordonnees, int rayon, AirWatcherIO mesIO ){
    unordered_map<string, Sensor>* mesSensors = mesIO.getSensors();
    vector<Sensor> capteurDansLaZone ; 

    for(unordered_map<string, Sensor>::iterator it = (*mesSensors).begin(); it != (*mesSensors).end() ; it++){
        Sensor tmp =  it->second; 
        Coords lesCoords = tmp.getCoords();
        if(coordonnees.dist(&lesCoords) < rayon){
            capteurDansLaZone.push_back(it->second); 
        }
    }

    return capteurDansLaZone ; 

}

int calculerQualiteeDeLair(Coords coordonnees, int rayon, time_t datDebut, time_t datFin, AirWatcherIO mesIO )
{
    float PM10 = 0;
	float NO2 =0;
    float O3=0;
    float SO2 = 0;
	int nbLMesurePriseEnCompte = 0	;
	vector<Sensor> capteursDeLaZone;
    capteursDeLaZone = chercherCapteurZone(coordonnees, rayon, mesIO);

    for (vector<Sensor>::iterator i = capteursDeLaZone.begin() ; i != capteursDeLaZone.end(); i++)
    {

        map<time_t, Measure> mesuresCapteur; 
        mesuresCapteur = *(i->getMeasure());

         for(map<time_t, Measure>::iterator j = mesuresCapteur.begin() ; j !=  mesuresCapteur.end() ; j++)
            {
                if( difftime(j->first ,datDebut) < 0 &&  difftime(datFin,j->first) > 0 )
                {
                    nbLMesurePriseEnCompte++;
                    NO2 += j->second.NO2;
                    SO2 += j->second.SO2;
                    PM10 += j->second.PM10;
                    O3 += j->second.O3;
                }
            }   
    }
    NO2 = NO2/nbLMesurePriseEnCompte;
    SO2 = SO2/nbLMesurePriseEnCompte ;
    PM10 = PM10/nbLMesurePriseEnCompte;
    O3 = O3/nbLMesurePriseEnCompte ;

		
	return calculIndiceAthmo(NO2, SO2 , PM10 , O3);
}


vector<int> determinerImpacte(Cleaner monCleaner, int rayon, AirWatcherIO mesIO)
{
	time_t debutCleaner = monCleaner.getBeginTime();
	int tabAvant [25];	
	int tabApres [25];
	vector<int> tabEcart;	
	for(int i=0 ; i<25 ; i++)
	{
		tabAvant[i] = calculerQualiteeDeLair(monCleaner.getCoords(), (int)(i*rayon/25), time(0) , debutCleaner, mesIO );
	}
	for(int i=0 ; i<25 ; i++)
	{
		tabApres[i] = calculerQualiteeDeLair(monCleaner.getCoords(), (int)(i*rayon/25), debutCleaner, time(0) , mesIO );
	}
	for(int i=0 ; i<25 ; i++)
	{
		tabEcart.push_back(tabAvant[i]-tabApres[i]);
	}
	
	return tabEcart;
}


int main(int argc, char **argv)
{
    time_t datDebut = time(0) ; 
    time_t datFin = 0;
    
    double diff = difftime(datDebut, datFin);


    cout << ctime(&datFin) <<  endl ; 
    cout << ctime(&datDebut) << endl ; 
    cout << diff << endl ; 

    return 0;
}