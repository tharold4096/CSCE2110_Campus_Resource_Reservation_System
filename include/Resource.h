#ifndef RESOURCE_H
#define RESOURCE_H

#include<string>
using namespace std;

class Resource
{
    private:
        string resource_id;
        string resource_name;
        string resource_type;
        bool available;

    public:
        Resource();
        Resource(string id, string name, string type, bool availability);

        string get_resource_id() const;
        string get_resource_name() const;
        string get_resource_type() const;
        bool get_availability() const;

        void set_availability(bool availability);
        void print() const;

};
    

#endif // RESOURCE_H