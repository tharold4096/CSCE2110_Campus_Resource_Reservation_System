#include "LinkedList.h"

#include <iostream>
#include "Reservation.h"

//Default constructor
LinkedList::LinkedList(): head(nullptr) {}

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
void LinkedList::insert_at_beginning(Reservation value)
{
    Node* node = new Node{value, head};
    head = node;
}

//Insert function to add a new node to the end of the list
void LinkedList::insert_at_end(Reservation value)
{
    Node* node = new Node{value, nullptr};

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
void LinkedList::insert_after(std::string target_reservation_id, Reservation value)
{
    Node* current = head;
    while (current != nullptr && current->data.get_reservation_id() != target_reservation_id    )
        current = current->next;

    if (current == nullptr)
        return;

    Node* node = new Node{value, current->next};
    current->next = node;
}

bool LinkedList::remove(std::string reservation_id)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data.get_reservation_id() != reservation_id)
    {
        previous = current;
        current = current->next;
    }

    //Don't remove nonexistent nodes
    if (current == nullptr)
        return false;

    //Find the new head
    if (previous == nullptr)
        head = current->next;
    else
        previous->next = current->next;

    delete current;
    return true;
}

void LinkedList::print_list() const
{
    Node* current = head;
    while (current != nullptr)
    {
        current->data.print();
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    cout << '\n';
}


std::vector<Reservation> LinkedList::find_by_student_id(std::string student_id) const
{
    std::vector<Reservation> results;
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data.get_student_id() == student_id)
        {
            results.push_back(current->data);
        }
        current = current->next;
    }
    if(results.empty())
    {
        cout << "No reservations found for student ID: " << student_id << endl;
    }
    return results;
}