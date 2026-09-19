#include "WaitingList.h"

WaitingList::WaitingList() {}

//Add student to the back of the waiting list
void WaitingList::enqueue(students student) {
    list.insert_at_end(student);
}

bool WaitingList::next_student(students& out)
{
    return list.remove_front(out);
}
//Print the waiting list in order
void WaitingList::display_list() const {
    list.print_list();
}
