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
const Resource* ResourceManager::find_resource(const string& id) const
{
    int left = 0;
    int right = static_cast<int>(resources.size()) -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (resources[mid].get_resource_id() == id)
        {
            return &resources[mid];
        }
        else if (id < resources[mid].get_resource_id())
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    

    }
    return nullptr;

}

Resource* ResourceManager::find_resource_mutable(const string& id)
{
    int left = 0;
    int right = static_cast<int>(resources.size()) -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (resources[mid].get_resource_id() == id)
        {
            return &resources[mid];
        }
        else if (id < resources[mid].get_resource_id())
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return nullptr;
}


void ResourceManager::display_resources(int top_n) const
{
    for(int i = 0; i < top_n && i < static_cast<int>(resources.size()); i++)
    {
        resources[i].print();
        cout << endl;
    }
}

    