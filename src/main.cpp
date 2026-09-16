//The main cpp file


#include <iostream>
#include <string>
#include "Reservation.h"
#include "Students.h"
#include "WaitingList.h"
#include "ReservationManager.h"



using namespace std;

int main() 
{
    cout << "Welcome to the Campus Resource Reservation System!" << endl;

    string student_name;
    cout << "Enter student name: ";
    
    getline(cin, student_name);

    string student_id;
    cout << "Enter student ID: ";
    
    getline(cin, student_id);

    students student{student_id, student_name};

    WaitingList waiting_list;
    waiting_list.add_student(student);
    waiting_list.display_list();

    //Reservation testing ------
    cout << endl;
    cout << "Testing Reservation system..." << endl;

    Reservation reservation1(
        "R001",
        student,
        "Room101",
        "09/20/2026"
    );
    ReservationManager manager;

    manager.create_reservation(reservation1);

    //test #2 duplicate 
    Reservation reservation2(
        "R002",
        student,
        "Room101",
        "09/20/2026"
    );

    manager.create_reservation(reservation2);
    
    //test #3 valid different data
    Reservation reservation3(
        "R003",
        student,
        "Room101",
        "09/21/2026"

    );

    manager.create_reservation(reservation3);

    cout << endl;
    manager.display_reservations();

    cout << endl;
    manager.cancel_reservation(reservation1);

    cout << endl;
    manager.display_reservations();



    // end of reservation testing ------- 
      
}