#include "AirWatcherIO.h"
#include <iostream>
#include <fstream>

#define maxS numeric_limits<streamsize>::max()

Data *AirWatcherIO::loadFiles(unordered_map<string, string> files)
{
    Data *d = new Data();

    loadAttributes(d, files.at("attributes"));
    loadCleaners(d, files.at("cleaners"));
    loadProviders(d, files.at("providers"));
    loadSensors(d, files.at("sensors"));
    loadMeasurements(d, files.at("measurements"));
    loadUsers(d, files.at("users"));
    loadUntrusted(d, files.at("usersUntrusted"));

    return d;
}

void AirWatcherIO::loadAttributes(Data *d, string path)
{
    ifstream file;
    d->attributes = new unordered_map<string, pair<string, string>>();
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
                d->attributes->emplace(id, make_pair(unit, desc));
            file.ignore(maxS, '\n');
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void AirWatcherIO::loadCleaners(Data *d, string path)
{
    ifstream file;
    d->cleaners = new unordered_map<string, Cleaner>();
    string id, lat, lon, start, end;
    Cleaner c;
    tm t1, t2;
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

                c = Cleaner(Coords(stof(lat), stof(lon)), mktime(&t1), mktime(&t2));
                d->cleaners->emplace(id, c);
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

void AirWatcherIO::loadProviders(Data *d, string path)
{
    ifstream file;
    d->providers = new unordered_map<string, Provider>();
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
                auto res = d->providers->emplace(id, p);
                if (!res.second)
                {
                    d->providers->at(id).addCleaner(cleanerId);
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

void AirWatcherIO::loadSensors(Data *d, string path)
{
    ifstream file;
    d->sensors = new unordered_map<string, Sensor>();
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

                s = Sensor(Coords(stof(lat), stof(lon)));
                d->sensors->emplace(id, s);
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

void AirWatcherIO::loadMeasurements(Data *d, string path)
{

    ifstream file;
    string date, id, type, value[4];
    Measure m;
    tm t1;
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
                d->sensors->at(id).addMeasure(mktime(&t1), m);
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

void AirWatcherIO::loadUsers(Data *d, string path)
{
    ifstream file;
    d->privateUsers = new unordered_map<string, PrivateUser>();
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
                auto res = d->privateUsers->emplace(id, p);
                if (!res.second)
                {
                    d->privateUsers->at(id).addSensor(sensorId);
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

void AirWatcherIO::loadUntrusted(Data *d, string path)
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
                d->privateUsers->at(id).setTrusted(false);
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