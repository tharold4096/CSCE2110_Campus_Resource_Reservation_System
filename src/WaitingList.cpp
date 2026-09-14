#include "WaitingList.h"

WaitingList::WaitingList() {}

//Add student to the back of the waiting list
void WaitingList::add_student(students student) {
    list.insert_at_end(student);
}

//Remove student from the waiting list by name
void WaitingList::remove_student(students student) {
    if (!list.remove(student))
        cout << "Student not found on waiting list." << endl;
}

//Print the waiting list in order
void WaitingList::display_list() const {
    list.print_list();
}
