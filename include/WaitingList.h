#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include "LinkedList.h"
#include "Students.h"

using namespace std;

class WaitingList
{
    private:
        LinkedList<students> list;

    public:
        WaitingList();
        void enqueue(students student);
        bool remove_student(students student);

        bool next_student(students& out);
        void display_list() const;
        bool is_empty() const;


};

#endif // WAITINGLIST_H