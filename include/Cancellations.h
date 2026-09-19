#ifndef CANCELLATIONS_H
#define CANCELLATIONS_H

#include "LinkedList.h"
#include "Reservation.h"
using namespace std;

class Cancellations
{
    private:
        LinkedList<Reservation> canceled;

    public:
        void push(Reservation res);
        bool pop();
        Reservation peep() const;
        bool is_empty() const;
        int size() const;
}






















#endif