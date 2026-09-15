//The main cpp file


#include <iostream>
#include "Reservation.h"
#include "Students.h"
#include "WaitingList.h"


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

    
}