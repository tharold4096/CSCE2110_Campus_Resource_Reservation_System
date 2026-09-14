#ifndef LINKEDLIST_H
#define LINKEDLIST_H


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
        void remove(std::string value);
        void print_list() const;
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        //void free_list();
    

};



#endif // LINKEDLIST_H