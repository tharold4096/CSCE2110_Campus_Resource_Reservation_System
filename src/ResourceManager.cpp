#include "ResourceManager.h"
#include "Sorting.h"

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
    // TODO(sorting): find_index() is a binary search, so it only works if `resources` is sorted by ID. Add this here:
    //     merge_sort(resources, [](const Resource& a, const Resource& b) {
    //         return a.get_resource_id() < b.get_resource_id();
    //     });
    //   This does not compile until the private merge_sort/merge members are deleted (see ResourceManager.h).
    merge_sort(resources, [](const Resource& a, const Resource& b) {
            return a.get_resource_id() < b.get_resource_id();
    });
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

// sorting resources by name with merge sort
// TODO(sorting): DANGER. Sorting `resources` by name in place breaks find_index(), because the binary search needs ID order.
//   Nothing calls this function right now. Choose one:
//   (a) Delete it, plus its declaration in ResourceManager.h. This is the simplest option.
//   (b) If you want a "View Resources by Name" option, rewrite it as a const function that prints a sorted COPY:
//         vector<Resource> sorted = resources;
//         merge_sort(sorted, [](const Resource& a, const Resource& b) { return a.get_resource_name() < b.get_resource_name(); });
//         then print each one with `r.print(); cout << endl;`
void ResourceManager::sort_resources_by_name() {
    if (resources.size() > 1) {
        merge_sort(0, static_cast<int>(resources.size()) - 1);
    }
}

// TODO(sorting): DELETE merge_sort() and merge() below. Sorting.h's generic template replaces them.
//   They also contain a compile error: `j++` is missing its `;` inside merge().
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

const vector<Resource>& ResourceManager::get_all_resources() const
{
    return resources;
}
    
