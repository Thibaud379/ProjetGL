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
        
        vector<int> v = c.getImpact(c.data.cleaners.at("Cleaner0"), 50);
        //cout<<"size: "<<v.size()<<endl;    
        cout << "before : "<< v[0] << endl << "after : "<< v[1] << endl<< "difference: "<< v[2] << endl;

    }else if (testNumber == 3)
    {
        int airQuality = c.getAirQuality(c.data.sensors.at("Sensor0").getCoords(), 2, parseTime("2019-01-01 12:00:00"), parseTime("2019-01-03 12:00:00"));
        
        cout << airQuality << endl;

    }else if (testNumber == 4)
    { 
        int airQuality = c.getAirQuality(c.data.sensors.at("Sensor18").getCoords(), 70, parseTime("2019-01-01 12:00:00"), parseTime("2019-01-01 12:00:00"));
        
        cout << airQuality << endl;

    }
    

    return 0;
}

