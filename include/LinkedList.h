#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Reservation.h"
#include <vector>
using namespace std;
class LinkedList 
{   
    private:
        struct Node 
        {
            Reservation data;
            Node* next;
            
        };

        Node* head;

    public:
        LinkedList();
        ~LinkedList();
        void insert_at_end(Reservation value);
        void insert_at_beginning(Reservation value);
        void insert_after(std::string target, Reservation value);
        bool remove(std::string reservation_id);
        void print_list() const;
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        //void free_list();

        
        std::vector<Reservation> find_by_student_id(string reservation_id) const;
};



#endif // LINKEDLIST_H