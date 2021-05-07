#include "AirWatcherIO.h"
#include <iostream>
#include <fstream>
#define maxS numeric_limits<streamsize>::max()
Data *AirWatcherIO::loadFiles(unordered_map<string, string> files)
{
    Data *d = new Data();

    loadAttributes(d, files.at("attributes"));
    loadCleaners(d, files.at("cleaners"));

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
    string format = "%Y-%m-%d %h:%M:%S";
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
                strptime(start.c_str(),format.c_str(),&t1);
                strptime(start.c_str(),format.c_str(),&t2);

                c = Cleaner(Coords(stof(lat), stof(lon)), mktime(&t1), mktime(&t2));
                // d->attributes->emplace(id, &c);
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