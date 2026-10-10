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

// sorting resources by name with merge sort
void ResourceManager::sort_resources_by_name() {
    if (resources.size() > 1) {
        merge_sort(0, static_cast<int>(resources.size()) - 1);
    }
}

// recursively split the resource list into smaller sections
void ResourceManager::merge_sort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(left, middle);
        merge_sort(middle + 1, right);
        merge(left, middle, right);
    }
}

//merge two sorted sections in alphabetic order
void ResourceManager::merge(int left, int middle, int right) {
    vector<Resource> temp;

    int i = left;
    int j = middle + 1;

    while (i <= middle && j <= right) {

        if (resources[i].get_resource_name() <= resources[j].get_resource_name()) {
            temp.push_back(resources[i]);
            i++;
        }
        else {
            temp.push_back(resources[j]);
            j++
        }
    }
    while (i <= middle) {
        temp.push_back(resources[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(resources[j]);
        j++;
    }

    for (int k = 0; k < static_cast<int>(temp.size()); k++) {
        resources[left + k] = temp[k];
    }
}
