#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include "LinkedList.h"
#include <iostream>
#include "Students.h"

using namespace std;

class WaitingList
{
    private:
        LinkedList<string> list;

    public:
        WaitingList();
        void add_student(string student_name);
        void remove_student(string student_name);
        void display_list() const;


}

#endif // WAITINGLIST_H