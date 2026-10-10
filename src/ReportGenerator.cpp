#include "ReportGenerator.h"

using namespace std;

ReportGenerator::ReportGenerator(const ResourceManager& rm, const ReservationManager& resm, const map<string, map<string, WaitingList>>& wl) : resources(rm), reservations(resm), waiting_lists(wl) {}

void ReportGenerator::active_reservations() const
{
    cout << "Active Reservations:" << endl;
    // TODO After Adrian puts sorting in, uncomment this:
    /*
         vector<Reservation> sorted = reservations.get_all_reservations();
         merge_sort(sorted, [](const Reservation& a, const Reservation& b) {
             if (a.get_date() != b.get_date()) return a.get_date() < b.get_date();
             return a.get_reservation_id() < b.get_reservation_id();   // tie-break
         });
    */
         //then print each one: ID | student | resource | date
    reservations.display_reservations();
}

void ReportGenerator::resource_utilization() const
{
    cout << "Resource Utilization:" << endl;    
    map<string, int> counts;
    for (const Reservation& r : reservations.get_all_reservations())
        counts[r.get_resource_id()]++;
    for (const Resource& res : resources.get_all_resources())
    {
        auto it = counts.find(res.get_resource_id());
        int active = (it == counts.end()) ? 0 : it->second;
        cout << "ID: " << res.get_resource_id() << " | Name: " << res.get_resource_name() << " | Active Reservations: " << active << endl;
    }
}

void ReportGenerator::most_requested_resources(int top_n) const
{
    
    
    cout << "Most Requested Resources (Top " << top_n << "):" << endl;
    vector<Resource> sorted = resources.get_all_resources();
    //merge_sort(sorted, [](const Resource& a, const Resource& b) //IMPORTANT: TODO: enable when Sorting.h merges
               //{ return a.get_request_count() > b.get_request_count(); });
    for(int i = 0; i < top_n && i < static_cast<int>(sorted.size()); i++)
    {
        const Resource& resource = sorted[i];
        cout << "ID: " << resource.get_resource_id() << " | Name: " << resource.get_resource_name() << " | Requests: " << resource.get_request_count() << endl;
    }
    
}

void ReportGenerator::waitlist_statistics() const
{
    cout << "Waitlist Statistics:" << endl;
    // TODO correct logic on waitinglist reporting
    for (const auto& resource_pair : waiting_lists)
    {
        const string& resource_id = resource_pair.first;
        const map<string, WaitingList>& wl_map = resource_pair.second;
        for (const auto& wl_pair : wl_map)
        {
            const WaitingList& wl = wl_pair.second;
        
            cout << "Resource ID: " << resource_id << ", Waiting List Size: " << wl.size() << endl;
            students next;
            if (wl.peek(next))
                cout << "Next Student: " << next.student_id << " | " << next.student_name << endl;
        }
    }

    int total_waiting = 0;
    string longest_queue_resource;
    int longest_queue_size = 0;
    for (const auto& resource_pair : waiting_lists)
    {
        const string& resource_id = resource_pair.first;
        const map<string, WaitingList>& wl_map = resource_pair.second;
        for (const auto& wl_pair : wl_map)
        {
            const WaitingList& wl = wl_pair.second;
            total_waiting += wl.size();
            if (wl.size() > longest_queue_size)
            {
                longest_queue_size = wl.size();
                longest_queue_resource = resource_id;
            }
        }
    }
    if (total_waiting > 0)
    {
        cout << "Total Waiting: " << total_waiting << endl;
        cout << "Longest Queue: Resource ID " << longest_queue_resource << " with " << longest_queue_size << " students" << endl;
    }
    else
    {
        cout << "No students are waiting." << endl;
    }
}

void ReportGenerator::all_reports() const
{
    active_reservations();
    resource_utilization();
    most_requested_resources(5); //specify most requested resources here
    waitlist_statistics();
}



