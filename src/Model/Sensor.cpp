#include "Sensor.h"

int Sensor::atmosIndex(Measure m)
{

    int athmo = 1;
    if(m.NO2>=0 && m.NO2 <=29){
        if(athmo<1){
            athmo =1;
        }
    }else if(m.NO2>29 && m.NO2 <=54){
        if(athmo<2){
            athmo =2;
        }
    }else if(m.NO2>54 && m.NO2 <=84){
        if(athmo<3){
            athmo =3;
        }
    }else if(m.NO2>84 && m.NO2 <=109){
        if(athmo<4){
            athmo =4;
        }
    }else if(m.NO2>109 && m.NO2 <=134){
        if(athmo<5){
            athmo =5;
        }
    }else if(m.NO2>134 && m.NO2 <=164){
        if(athmo<6){
            athmo =6;
        }
    }else if(m.NO2>164 && m.NO2 <=199){
        if(athmo<7){
            athmo =7;
        }
    }else if(m.NO2>199 && m.NO2 <=274){
        if(athmo<8){
            athmo =8;
        }
    }else if(m.NO2>274 && m.NO2 <=399){
        if(athmo<9){
            athmo =9;
        }
    }else if(m.NO2>=400){
        if(athmo<10){
            athmo =10;
        }
    }

    if(m.SO2>=0 && m.SO2 <=39){
        if(athmo<1){
            athmo =1;
        }
    }else if(m.SO2>39 && m.SO2 <=79){
        if(athmo<2){
            athmo =2;
        }
    }else if(m.SO2>79 && m.SO2 <=119){
        if(athmo<3){
            athmo =3;
        }
    }else if(m.SO2>119 && m.SO2 <=159){
        if(athmo<4){
            athmo =4;
        }
    }else if(m.SO2>159 && m.SO2 <=199){
        if(athmo<5){
            athmo =5;
        }
    }else if(m.SO2>199 && m.SO2 <=249){
        if(athmo<6){
            athmo =6;
        }
    }else if(m.SO2>249 && m.SO2 <=299){
        if(athmo<7){
            athmo =7;
        }
    }else if(m.SO2>299 && m.SO2 <=399){
        if(athmo<8){
            athmo =8;
        }
    }else if(m.SO2>399 && m.SO2 <=499){
        if(athmo<9){
            athmo =9;
        }
    }else if(m.SO2>=500){
        if(athmo<10){
            athmo =10;
        }
    }

    if(m.O3>=0 && m.O3 <=29){
        if(athmo<1){
            athmo =1;
        }
    }else if(m.O3>29 && m.O3 <=54){
        if(athmo<2){
            athmo =2;
        }
    }else if(m.O3>54 && m.O3 <=79){
        if(athmo<3){
            athmo =3;
        }
    }else if(m.O3>79 && m.O3 <=104){
        if(athmo<4){
            athmo =4;
        }
    }else if(m.O3>104 && m.O3 <=129){
        if(athmo<5){
            athmo =5;
        }
    }else if(m.O3>129 && m.O3 <=149){
        if(athmo<6){
            athmo =6;
        }
    }else if(m.O3>149 && m.O3 <=179){
        if(athmo<7){
            athmo =7;
        }
    }else if(m.O3>179 && m.O3 <=209){
        if(athmo<8){
            athmo =8;
        }
    }else if(m.O3>209 && m.O3 <=239){
        if(athmo<9){
            athmo =9;
        }
    }else if(m.O3>=240){
        if(athmo<10){
            athmo =10;
        }
    }
    
    if(m.PM10>=0 && m.PM10 <=6){
        if(athmo<1){
            athmo =1;
        }
    }else if(m.PM10>6 && m.PM10 <=13){
        if(athmo<2){
            athmo =2;
        }
    }else if(m.PM10>13 && m.PM10 <=20){
        if(athmo<3){
            athmo =3;
        }
    }else if(m.PM10>20 && m.PM10 <=27){
        if(athmo<4){
            athmo =4;
        }
    }else if(m.PM10>27 && m.PM10 <=34){
        if(athmo<5){
            athmo =5;
        }
    }else if(m.PM10>34 && m.PM10 <=41){
        if(athmo<6){
            athmo =6;
        }
    }else if(m.PM10>41 && m.PM10 <=49){
        if(athmo<7){
            athmo =7;
        }
    }else if(m.PM10>49 && m.PM10 <=64){
        if(athmo<8){
            athmo =8;
        }
    }else if(m.PM10>64 && m.PM10 <=79){
        if(athmo<9){
            athmo =9;
        }
    }else if(m.PM10>=80){
        if(athmo<10){
            athmo =10;
        }
    }

    return athmo; 

} 

bool Sensor::addMeasure(time_t t, Measure m)
{
    return this->Measures.emplace(t, m).second;
}

map<time_t, Measure> *Sensor::getMeasure()
{
    return &Measures;
}

Sensor::Sensor(Coords coords)
{
    this->coords = coords;
    this->Measures = map<time_t, Measure>();
}

Sensor::~Sensor()
{
}
