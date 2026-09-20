//The main cpp file


#include <iostream>
#include <string>
#include<limits>
#include "Reservation.h"
#include "Students.h"
#include "WaitingList.h"
#include "ReservationManager.h"
#include "ResourceManager.h"



using namespace std;

int main() 
{
 int choice = 0;

 ResourceManager resource_manager;
 resource_manager.load_resources("data/resources.txt");
 ReservationManager manager;
 WaitingList waiting_list;

 while (choice != 9)
 {
    cout << "=====Campus Resource Reservation System=====" << endl;
    cout << "1. View Resources" << endl;
    cout << "2. Create Reservation" << endl;
    cout << "3. Cancel Reservation" << endl;
    cout << "4. View Active Reservations" << endl;
    cout << "5. View Waiting List" << endl;
    cout << "6. Add Student to Waiting List" << endl;
    cout << "7. Undo Cancellation" << endl;
    cout << "8. View Cancellation History" << endl;
    cout << "9. Exit" << endl;

    cout << "Enter choice: ";
    cin >> choice;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice" << endl;
        choice = 0;
        continue;
    }

    switch(choice)
        {
            case 1:
                resource_manager.display_resources();
                break;
            case 2:
            {
                string reservation_id;

                cout << "Enter reservation ID: ";
                cin >> reservation_id;

                string student_id;
                cout << "Enter student ID: ";
                cin >> student_id;

                string student_name;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, student_name);

                string resource_id;
                cout << "Enter resource ID: ";
                cin >> resource_id;

                string date;
                cout << "Enter date: ";
                cin >> date;

                students student{student_id, student_name};
                
                Reservation reservation(reservation_id, student, resource_id, date);
               
                manager.create_reservation(reservation);

        
                
                break;
            }    
            case 3:
                {
                    string cancel_id;
                    cout << "Enter reservation ID to cancel: ";
                    cin >> cancel_id;

                    students temp_student{"", ""};

                    Reservation temp_reservation(cancel_id, temp_student, "", "");
                    manager.cancel_reservation(temp_reservation);

                
                break;
                }
            case 4:
                manager.display_reservations();
                break;
            case 5:
                waiting_list.display_list();
                break;
            case 6:
            {
                string wait_student_id;

                cout << "Enter student ID: ";
                cin >> wait_student_id;
            
                string wait_student_name;

                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, wait_student_name);

                students wait_student{wait_student_id, wait_student_name};
                waiting_list.enqueue(wait_student);

                break;
            }
            case 7:
                manager.undo_cancel();
                break;
            case 8:
                manager.display_cancellations();
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
                
        }

    }

 


    
}