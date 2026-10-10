#include "ReportGenerator.h"

using namespace std;

ReportGenerator::ReportGenerator(const ResourceManager& rm, const ReservationManager& resm, const map<string, WaitingList>& wl) : resources(rm), reservations(resm), waiting_lists(wl) {}

void ReportGenerator::active_reservations() const
{
    cout << "Active Reservations:" << endl;
    reservations.display_reservations();
}

void ReportGenerator::resource_utilization() const
{
    cout << "Resource Utilization:" << endl;
    resources.display_resources();
}

void ReportGenerator::most_requested_resources(int top_n) const
{
    cout << "Most Requested Resources (Top " << top_n << "):" << endl;
    resources.display_resources(top_n);
}

void ReportGenerator::waitlist_statistics() const
{
    cout << "Waitlist Statistics:" << endl;
    for (const auto& pair : waiting_lists)
    {
        const string& resource_id = pair.first;
        const WaitingList& wl = pair.second;
        cout << "Resource ID: " << resource_id << ", Waiting List Size: " << wl.size() << endl;
    }
}

void ReportGenerator::all_reports() const
{
    active_reservations();
    resource_utilization();
    most_requested_resources(5); //specify most requested resources here
    waitlist_statistics();
}



