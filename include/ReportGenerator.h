#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <map>
#include <string>
#include "ReservationManager.h"
#include "ResourceManager.h"
#include "WaitingList.h"
using namespace std;

class ReportGenerator
{
    private:
    const ResourceManager& resources;
    const ReservationManager& reservations;
    const map<string, map<string, WaitingList>>& waiting_lists;
    public:
    ReportGenerator(const ResourceManager& rm,
                    const ReservationManager& resm,
                    const std::map<std::string, std::map<std::string, WaitingList>>& wl);
    void active_reservations() const;
    void resource_utilization() const;
    void most_requested_resources(int top_n = 5) const;
    void waitlist_statistics() const;
    void all_reports() const;
};

#endif // REPORTGENERATOR_H