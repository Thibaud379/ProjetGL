#include "Control/Control.h"
#include <unordered_map>
#include <ctime>
#include <iomanip>
time_t parseTime(string time)
{
    struct tm t = tm();
    strptime(time.c_str(), format.c_str(), &t);
    return mktime(&t);
}


int main(int argc, char **argv)
{
    int testNumber = stoi(argv[2]);
    unordered_map<string, string> files = {
        {"attributes", "data/attributes.csv"},
        {"cleaners", "data/cleaners.csv"},
        {"providers", "data/providers.csv"},
        {"measurements", argv[1]},
        {"sensors", "data/sensors.csv"},
        {"users", "data/users.csv"},
        {"usersUntrusted", "data/usersUntrusted.csv"}};
    
    Control c(files);
    
    if (testNumber == 1)
    {
        
        auto l = c.findSimilarSensor(c.data.sensors.at("Sensor0"), 10, parseTime("2019-01-01 12:00:00"));
        
            for (auto e : *l)
            {
                cout << setprecision(4)<<e.first << "  -  " << e.second.getId() << endl;
            }
    }else if (testNumber == 2)
    {
        
        
     

       vector<pair<int,int>> impactAirCleaner=c.getImpact(c.data.cleaners.at("Cleaner1"), 50);
       for(vector<pair<int,int>>::iterator it = impactAirCleaner.begin();it!=impactAirCleaner.end();it++){
                int dist=(*it).first;
                if(dist/10==0){
                    cout<<"Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<endl;
                }else if(dist/100==0){
                    cout<<"Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<endl;
                }else if(dist/1000==0){
                    cout<<"Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<endl;
                }else if(dist/10000==0){
                    cout<<"Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<endl;
                }else {
                    cout<<"Sur un rayon de "<<dist<<"km, l'indice atmo a diminué de : "<<(*it).second<<endl;
                }    
            }
       

    }else if (testNumber == 3)
    {
        Measure airQuality=c.getAirQuality(c.data.sensors.at("Sensor0").getCoords(), 0, parseTime("2019-01-01 12:00:00"), parseTime("2019-01-03 12:00:00"));
        int indice=airQuality.atmosIndex();
        
        
        cout << indice << endl;

    }else if (testNumber == 4)
    { 
        Measure airQuality=c.getAirQuality(c.data.sensors.at("Sensor18").getCoords(), 70, parseTime("2019-01-01 12:00:00"), parseTime("2019-01-01 12:00:00"));
        int indice=airQuality.atmosIndex();
        
        
        cout << indice << endl;
        

    }
    

    return 0;
}

