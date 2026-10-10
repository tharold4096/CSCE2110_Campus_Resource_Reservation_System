#include "ResourceManager.h"

#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;


int ResourceManager::find_index(const string& id) const
{
    int left = 0;
    int right = static_cast<int>(resources.size()) -1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (resources[mid].get_resource_id() == id)
        {
            return mid;
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
    return -1;
}

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
    // TODO(sorting): once Sorting.h merges, sort by ID here so find_index()'s binary search
    // is valid whatever order the file is in (it only works now because resources.txt is
    // already in order):
    //     merge_sort(resources, [](const Resource& a, const Resource& b)
    //         { return a.get_resource_id() < b.get_resource_id(); });
    // Agree with your sorting partner on who adds this line.
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
    int i = find_index(id);
    return (i == -1) ? nullptr : &resources[i];

}

Resource* ResourceManager::find_resource_mutable(const string& id)
{
    int i = find_index(id);
    return (i == -1) ? nullptr : &resources[i];
}



vector<Resource>& ResourceManager::get_all_resources() const
{
    return resources;
}
    