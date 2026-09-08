#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList 
{   
    private:
        struct Node 
        {
            int data;
            Node* next;
            
        };

        Node* head;

    public:
        LinkedList();
        ~LinkedList();
        void insert_at_end(int value);
        void insert_at_beginning(int value);
        void insert_after(int target, int value);
        void remove(int value);
        void print_list() const;
        //void free_list();
    

};



#endif // LINKEDLIST_H