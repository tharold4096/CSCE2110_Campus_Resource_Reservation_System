#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <string>
#include "Resource.h"

using namespace std;
class ResourceManager
{
    private:
        vector<Resource> resources;

    public:
        bool load_resources(const string& filename);
        void display_resources() const;
        void display_resources_by_name() const;
        const Resource* find_resource(const string& id) const;
        const vector<Resource>& get_all_resources() const;
        Resource* find_resource_mutable(const string& id);
        int find_index(const string& id) const;

        
};      

#endif // RESOURCEMANAGER_H
