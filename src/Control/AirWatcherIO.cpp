#include "AirWatcherIO.h"
#include <iostream>
#include <fstream>

#define maxS numeric_limits<streamsize>::max()

Data::Data(unordered_map<string, string> files)
{

    this->loadAttributes(files.at("attributes"));
    this->loadCleaners(files.at("cleaners"));
    this->loadProviders(files.at("providers"));
    this->loadSensors(files.at("sensors"));
    this->loadMeasurements(files.at("measurements"));
    this->loadUsers(files.at("users"));
    this->loadUntrusted(files.at("usersUntrusted"));
}

void Data::loadAttributes(string path)
{
    ifstream file;
    string id, unit, desc;

    try
    {
        file.open(path);
        file.ignore(maxS, '\n');
        while (!file.eof())
        {
            getline(file, id, ';');
            getline(file, unit, ';');
            getline(file, desc, ';');

            if (!file.eof())
                this->attributes.emplace(id, make_pair(unit, desc));
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Data::loadCleaners(string path)
{
    ifstream file;
    string id, lat, lon, start, end;
    Cleaner c;
    tm t1 = tm(), t2 = tm();
    try
    {
        file.open(path);
        while (!file.eof())
        {
            getline(file, id, ';');
            getline(file, lat, ';');
            getline(file, lon, ';');
            getline(file, start, ';');
            getline(file, end, ';');

            if (!file.eof())
            {
                strptime(start.c_str(), format.c_str(), &t1);
                strptime(end.c_str(), format.c_str(), &t2);

                c = Cleaner(Coords(stof(lat), stof(lon)), mktime(&t1), mktime(&t2), id);
                this->cleaners.emplace(id, c);
            }
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Data::loadProviders(string path)
{
    ifstream file;
    string id, cleanerId;
    Provider p;

    try
    {
        file.open(path);
        while (!file.eof())
        {
            getline(file, id, ';');
            getline(file, cleanerId, ';');

            if (!file.eof())
            {
                p = Provider(id);
                p.addCleaner(cleanerId);
                auto res = this->providers.emplace(id, p);
                if (!res.second)
                {
                    this->providers.at(id).addCleaner(cleanerId);
                }
            }
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Data::loadSensors(string path)
{
    ifstream file;
    string id, lat, lon;
    Sensor s;
    try
    {
        file.open(path);
        while (!file.eof())
        {
            getline(file, id, ';');
            getline(file, lat, ';');
            getline(file, lon, ';');

            if (!file.eof())
            {

                s = Sensor(Coords(stof(lat), stof(lon)), id);
                this->sensors.emplace(id, s);
            }
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Data::loadMeasurements(string path)
{

    ifstream file;
    string date, id, type, value[4];
    Measure m;
    tm t1 = tm();
    try
    {
        file.open(path);
        while (!file.eof())
        {
            for (int i = 0; i < 4; i++)
            {
                /* code */
                getline(file, date, ';');
                getline(file, id, ';');
                getline(file, type, ';');
                getline(file, value[i], ';');
            }
            if (!file.eof())
            {
                strptime(date.c_str(), format.c_str(), &t1);
                m = {stof(value[0]), stof(value[1]), stof(value[2]), stof(value[3])};
                this->sensors.at(id).addMeasure(mktime(&t1), m);
            }
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Data::loadUsers(string path)
{
    ifstream file;
    string id, sensorId;
    PrivateUser p;

    try
    {
        file.open(path);
        while (!file.eof())
        {
            getline(file, id, ';');
            getline(file, sensorId, ';');

            if (!file.eof())
            {
                p = PrivateUser(id);
                p.addSensor(sensorId);
                auto res = this->privateUsers.emplace(id, p);
                if (!res.second)
                {
                    this->privateUsers.at(id).addSensor(sensorId);
                }
            }
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Data::loadUntrusted(string path)
{
    ifstream file;
    string id;

    try
    {
        file.open(path);
        while (!file.eof())
        {
            getline(file, id, ';');

            if (!file.eof())
            {
                this->privateUsers.at(id).setTrusted(false);
            }
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}