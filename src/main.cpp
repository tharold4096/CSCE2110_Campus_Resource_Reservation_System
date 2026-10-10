//The main cpp file


#include <iostream>
#include <string>
#include<limits>
#include "Reservation.h"
#include "Students.h"
#include "WaitingList.h"
#include "ReservationManager.h"
#include "ResourceManager.h"
#include "ReportGenerator.h"


using namespace std;

int main() 
{
 int choice = 0;

 ResourceManager resource_manager;
 resource_manager.load_resources("data/resources.txt");
 ReservationManager manager;
 map<string, WaitingList> waiting_lists;

 ReportGenerator report_generator(resource_manager, manager, waiting_lists);

 while (choice != 0)
 {
    cout << "=====Campus Resource Reservation System=====" << endl;
    cout << "0. Exit" << endl;
    cout << "1. View Resources" << endl;
    cout << "2. Search Resource by ID" << endl;
    cout << "3. Create Reservation" << endl;
    cout << "4. Cancel Reservation" << endl;
    cout << "5. Undo Cancellation" << endl;
    cout << "6. View Active Reservations" << endl;
    cout << "7. View Cancellation History" << endl;
    cout << "8. View Waiting List" << endl;
    cout << "6. Add Student to Waiting List" << endl;
    cout << "10. Remove Student from Waiting List" << endl;
    cout << "11. Reports" << endl;
    

    cout << "Enter choice: ";
    cin >> choice;

    if (cin.eof())
    {
        cout << "Exiting program." << endl;
        break;
    }

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

                

                Resource* res = resource_manager.find_resource_mutable(resource_id);
                if (res == nullptr)
                {
                    cout << "Resource not found." << endl;
                    break;
                }
                if (!res->get_availability())
                {
                    cout << "Resource is unavailable." << endl;
                    break;
                }
                res->increment_request_count();

                Reservation reservation(reservation_id, student, resource_id, date);
                if (!manager.create_reservation(reservation)
                    && manager.is_resource_taken(resource_id, date))
                {
                    if (waiting_lists[resource_id].enqueue(student))
                        cout << "Student added to the waiting list for " << resource_id << "." << endl;
                }

        
                
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
                for (const auto& pair : waiting_lists)
                {
                    const string& resource_id = pair.first;
                    const WaitingList& wl = pair.second;
                    cout << "Resource ID: " << resource_id << endl;
                    wl.display_list();
                }
                break;
            case 6:
            {
                string wait_student_id;
                string resource_id;

                cout << "Enter student ID: ";
                cin >> wait_student_id;
                
                cout << "Enter resource ID: ";
                cin >> resource_id;
            
                string wait_student_name;

                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, wait_student_name);

                students wait_student{wait_student_id, wait_student_name};
                
                if (resource_manager.find_resource(resource_id) == nullptr)
                {
                    cout << "Resource not found." << endl;
                    break;
                }
                if (waiting_lists[resource_id].enqueue(wait_student))
                    cout << "Student added to the waiting list for " << resource_id << "." << endl;

                break;
            }
            case 7:
                manager.undo_cancel();
                break;
            case 8:
                manager.display_cancellations();
                break;
            case 9:
                {
                    string search_id;

                    cout << "Enter resource ID to search; ";
                    cin >> search_id;

                    const Resource* found = resource_manager.find_resource(search_id);

                    if(found != nullptr)
                    {
                        cout << "Resource found:" << endl;
                        found->print();

                    }
                    else
                    {
                        cout << "Resource not found." << endl;
                    }
                    break;
                }
            case 10:
            {
                students removed_student;
                string resource_id;

                cout << "Enter resource ID: ";
                cin >> resource_id;

                auto it = waiting_lists.find(resource_id);
                if (it == waiting_lists.end())
                {
                    cout << "No waiting list for " << resource_id << "." << endl;
                    break;
                }
                if(it->second.dequeue(removed_student))
                {
                    cout << "Student removed from waiting list." << endl;
                    cout << "Student ID: " << removed_student.student_id << endl;
                    cout << "Student Name: " << removed_student.student_name << endl;

                }
                else
                {
                    cout << "Waiting list is empty." << endl;

                }
                break;
            }
            
            case 0: 
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
                
        }

    }
}