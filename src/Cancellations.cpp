#include "Cancellations.h"

Cancellations::Cancellations() {}

void Cancellations::push(Reservation res)
{
    canceled.insert_at_beginning(res);
}

bool Cancellations::pop()
{
    return canceled.remove_front();
}

Reservation Cancellations::peep() const
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




  