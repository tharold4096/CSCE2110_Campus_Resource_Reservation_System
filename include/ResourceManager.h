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
        // TODO(sorting): DELETE these two private helpers (and their bodies in ResourceManager.cpp).
        //   A member named `merge_sort` hides the generic `merge_sort` template from Sorting.h inside
        //   every ResourceManager method, so `merge_sort(resources, ...)` will not compile while it exists.
        void merge_sort(int left, int right);
        void merge(int left, int middle, int right);

    public:
        bool load_resources(const string& filename);
        void display_resources() const;
        //const Resource& find_resource(const string& id) const;
        void sort_resources_by_name();
        // TODO: COMPILE ERROR. The next two lines duplicate the declarations above (from the merge). Delete these two lines,
        //   and delete the commented-out find_resource line above as well.
        bool load_resources(const string& filename);
        void display_resources() const;
        const Resource* find_resource(const string& id) const;
        const vector<Resource>& get_all_resources() const;
        Resource* find_resource_mutable(const string& id);
        int find_index(const string& id) const;

        
};      

#endif // RESOURCEMANAGER_H
