#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include "LinkedList.h"
#include <iostream>
#include "Students.h"

using namespace std;

class WaitingList
{
    private:
        LinkedList<students> list;

    public:
        WaitingList();
        void add_student(students student);
        void remove_student(students student);
        void display_list() const;


};

#endif // WAITINGLIST_H