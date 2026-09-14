#include "LinkedList.h"

#include <iostream>

//Default constructor
LinkedList::LinkedList() : head(nullptr) {}

//Destructor
LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

//Function to insert new node at beginning
void LinkedList::insert_at_beginning(int value)
{
    Node* node = new Node;
    node->data = value;
    node->next = head;
    head = node;
}

//Insert function to add a new node to the end of the list
void LinkedList::insert_at_end(int value)
{
    Node* node = new Node;
    node->data = value;
    node->next = nullptr;

    if (head == nullptr)
    {
        head = node;
        return;
    }

    Node* current = head;
    while (current->next != nullptr)
        current = current->next;

    current->next = node;
}

//Function to insert node after specific node
void LinkedList::insert_after(int target, int value)
{
    Node* current = head;
    while (current != nullptr && current->data != target)
        current = current->next;

    if (current == nullptr)
        return;

    Node* node = new Node;
    node->data = value;
    node->next = current->next;
    current->next = node;
}

void LinkedList::remove(int value)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    //Don't remove nonexistent nodes
    if (current == nullptr)
        return;

    //Find the new head
    if (previous == nullptr)
        head = current->next;
    else
        previous->next = current->next;

    delete current;
}

void LinkedList::print_list() const
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data;
        if (current->next != nullptr)
            std::cout << " -> ";
        current = current->next;
    }
    std::cout << '\n';
}