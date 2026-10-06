#include "Cancellations.h"
#include "ReservationManager.h"

Cancellations::Cancellations() {}


//Add cancellation to top of stack
void Cancellations::push(Reservation res)
{
    canceled.insert_at_beginning(res);
}

//remove cancellation from top of stack (DOES NOT RESTORE CANCELATION)
bool Cancellations::pop()
{
    return canceled.remove_front();
}

//Returns the top of the stack
Reservation Cancellations::peek() const
{
    return canceled.get_head();
}


//Checks if the stack is empty
bool Cancellations::is_empty() const
{
    return canceled.is_empty();
}

//Returns the size of the stack
int Cancellations::size() const
{
    return canceled.get_size();
}

//Restores top cancelation to the reservation manager list
bool Cancellations::restore_canceled(ReservationManager& manager)
{
    //Checks first
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


//displays the stack
void Cancellations::display_history()
{
    canceled.print_list();
}






  