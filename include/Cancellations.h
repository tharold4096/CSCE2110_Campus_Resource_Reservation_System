#ifndef CANCELLATIONS_H
#define CANCELLATIONS_H

#include "LinkedList.h"
#include "Reservation.h"
using namespace std;

class ReservationManager;
class Cancellations
{
    private:
        LinkedList<Reservation> canceled;

    public:
        Cancellations();
        void push(Reservation res);
        bool pop();
        Reservation peep() const;
        bool is_empty() const;
        int size() const;
        bool restore_canceled(ReservationManager& manager);
};






















#endif