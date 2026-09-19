#include "Cancellations.h"
#include "ReservationManager.h"

Cancellations::Cancellations() {}

void Cancellations::push(Reservation res)
{
    canceled.insert_at_beginning(res);
}

bool Cancellations::pop()
{
    return canceled.remove_front();
}

Reservation Cancellations::peek() const
{
    return canceled.get_head();
}

bool Cancellations::is_empty() const
{
    return canceled.is_empty();
}

int Cancellations::size() const
{
    return canceled.get_size();
}

bool Cancellations::restore_canceled(ReservationManager& manager)
{

    if(is_empty())
    {
        return false;
    }
    Reservation temp = peek();

    bool outcome = manager.create_reservation(temp);

    if(!outcome)
    {
        cout << "Reservation could not be restored" << endl;
        return false;
    }
    else{
        cout << "Reservation restored" << endl;
        return pop();
    }
}

void Cancellations::display_history()
{
    canceled.print_list();
}






  