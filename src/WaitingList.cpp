#include "WaitingList.h"

WaitingList::WaitingList() {}

//Add student to the back of the waiting list
void WaitingList::enqueue(students student) {
    list.insert_at_end(student);
}

bool WaitingList::dequeue(students& out)
{
    return list.remove_front(out);
}
//Print the waiting list in order
void WaitingList::display_list() const {
    list.print_list();
}

bool WaitingList::peek(students& out) const
{
    if (list.is_empty())
        return false;
    out = list.get_head();
    return true;
}

bool WaitingList::remove_student(students student)
{
    return list.remove(student);

}

bool WaitingList::is_empty() const {

    return list.is_empty();
    
}
