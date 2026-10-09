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
        const Resource* find_resource(const string& id) const;
};

#endif // RESOURCEMANAGER_H
