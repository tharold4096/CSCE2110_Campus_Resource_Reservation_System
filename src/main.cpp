//The main cpp file


#include <iostream>
#include <string>
#include "Reservation.h"
#include "Students.h"
#include "WaitingList.h"
#include "ReservationManager.h"
#include "ResourceManager.h"



using namespace std;

int main() 
{
    cout << "Welcome to the Campus Resource Reservation System!" << endl;
    cout << endl;
    cout << "Testing Resource Management..." << endl;

    ResourceManager resource_manager;

    if(resource_manager.load_resources("data/resources.txt"))
    {
        resource_manager.display_resources();

    }
    cout << endl;

    string student_name;
    cout << "Enter student name: ";
    
    getline(cin, student_name);

    string student_id;
    cout << "Enter student ID: ";
    
    getline(cin, student_id);

    students student{student_id, student_name};

    WaitingList waiting_list;
    waiting_list.enqueue(student);
    waiting_list.display_list();

    //Waiting list testing ------
    cout << endl << "Testing waiting list..." << endl;

    WaitingList queue_test;
    queue_test.enqueue({"A01", "A"});
    queue_test.enqueue({"B02", "B"});
    queue_test.enqueue({"C03", "C"});
    queue_test.display_list();

    students next;
    for (int i = 0; i < 4; i++)
    {
        if (queue_test.dequeue(next))
        {
            next.print();
            cout << endl;
        }
        else
            cout << "false (empty)" << endl;
    }
    queue_test.display_list();
    // end of waiting list testing -------

    //Waiting list edge cases ------
    cout << endl << "Testing waiting list edge cases..." << endl;

    WaitingList waitlist;
    waitlist.enqueue({"A01", "A"});
    waitlist.enqueue({"B02", "B"});
    waitlist.enqueue({"A01", "A"});          //duplicate, should be rejected
    waitlist.display_list();

    students front;
    if (waitlist.peek(front))
    {
        cout << "Front of list: ";
        front.print();
        cout << endl;
    }

    waitlist.remove_student({"B02", "B"});   //remove by id
    waitlist.remove_student({"Z99", "Z"});   //not on the list
    waitlist.display_list();
    // end of waiting list edge cases -------

    //Reservation testing ------
    cout << endl;
    cout << "Testing Reservation system..." << endl;

    ReservationManager manager;

    Reservation reservation1("R001", student, "R101", "09/20/2026");
    Reservation reservation2("R002", student, "R101", "09/20/2026");   //same room and date
    Reservation reservation3("R003", student, "R101", "09/21/2026");
    Reservation reservation4("", student, "", "");                     //missing fields

    manager.create_reservation(reservation1);
    manager.create_reservation(reservation2);
    manager.create_reservation(reservation3);
    manager.create_reservation(reservation4);

    cout << endl;
    manager.display_reservations();
    // end of reservation testing -------

    //Cancellation and undo testing ------
    cout << endl;
    cout << "Testing cancellation and undo..." << endl;

    manager.cancel_reservation(reservation1);
    manager.cancel_reservation(Reservation("R999", student, "R101", "09/22/2026"));   //not found

    cout << endl;
    manager.display_reservations();

    cout << endl;
    cout << "Cancellation history:" << endl;
    manager.display_cancellations();

    cout << endl;
    manager.undo_cancel();          //restores R001
    manager.display_reservations();

    cout << endl;
    if (!manager.undo_cancel())     //stack is empty
        cout << "Nothing left to restore." << endl;

    //undo blocked because the slot was taken again
    cout << endl;
    manager.cancel_reservation(reservation3);
    manager.create_reservation(Reservation("R004", student, "R101", "09/21/2026"));
    manager.undo_cancel();
    // end of cancellation and undo testing -------
      
}