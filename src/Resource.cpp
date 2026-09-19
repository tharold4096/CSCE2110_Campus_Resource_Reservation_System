#include "Resource.h"
#include <iostream>

using namespace std;

Resource::Resource()
{
    resource_id = "";
    resource_name = "";
    resource_type = "";
    available = true;
}

Resource:: Resource(string id, string name, string type, bool availability)
{
    resource_id = id;
    resource_name = name;
    resource_type = type;
    available = availability;
}

string Resource:: get_resource_id() const
{
    return resource_id;
}
string Resource:: get_resource_name() const
{
    return resource_name;
}
string Resource:: get_resource_type() const
{
    return resource_type;
}
bool Resource:: get_availability() const
{
    return available;

}
void Resource:: set_availability(bool availability)
{
    available = availability;
}

void Resource:: print() const
{
    cout << "Resource ID: " << resource_id << endl;
    cout << "Resource Name: " << resource_name << endl;
    cout << "Resource Type: " << resource_type << endl;
    cout << "Availability: " ;

if (available)
    cout << "Available " << endl;
else 
    cout << "Unavailable" << endl;
}

