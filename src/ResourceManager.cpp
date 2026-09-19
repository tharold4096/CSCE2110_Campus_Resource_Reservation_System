#include "ResourceManager.h"

#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

bool ResourceManager:: load_resources(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Error: Could not open file." << endl;
        return false;

    }
    string line;
    while (getline(file, line))
    {
        string id;
        string name;
        string type;
        string status;

        stringstream ss(line);

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, status, '|');

        bool available;
        if(status == "Available")
            available = true;
        else
            available = false;

        Resource resource(id, name, type, available);
        resources.push_back(resource);
    }
    file.close();
    return true;
}
void ResourceManager:: display_resources() const
{
    for(const Resource& resource : resources)
    {
        resource.print();
        cout << endl;

    }
}


    