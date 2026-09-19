#include "WaitingList.h"

WaitingList::WaitingList() {}

//Add student to the back of the waiting list
bool WaitingList::enqueue(students student) {
    vector<students> students_all = list.get_all();
    for(const students& current : students_all)
    {
        if(current.student_id == student.student_id)
        {
            cout << "Student is already in the waiting list" << endl;
            return false;
        }
    }
    list.insert_at_end(student);
    return true;
}

bool WaitingList::dequeue(students& out)
{
    return list.remove_front(out);
}
//Print the waiting list in order
void WaitingList::display_list() const {
    list.print_list();
}

//Looks at the person at the front of the list
bool WaitingList::peek(students& out) const
{
    if (list.is_empty())
        return false;
    out = list.get_head();
    return true;
}

//removes the specified student from the queue
bool WaitingList::remove_student(students student)
{
    return list.remove(student);

}

//checks if the queue is empty
bool WaitingList::is_empty() const {

    return list.is_empty();
    
}
