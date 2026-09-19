#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;



template <typename T>
class LinkedList
{
    private:
        int list_size;
        struct Node
        {
            T data;
            Node* next;
            Node(const T& value, Node* next_node = nullptr) : data(value), next(next_node) {}
        };

        Node* head;

    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;
        void insert_at_beginning(const T& value);
        void insert_at_end(const T& value);
        void insert_after(const T& target, const T& value);
        bool remove(const T& value);
        void print_list() const;
        std::vector<T> get_all() const;
        bool remove_front();
        bool is_empty() const;
        T get_head() const;
        int get_size() const;
};

#include "LinkedList.tpp"

#endif // LINKEDLIST_H
