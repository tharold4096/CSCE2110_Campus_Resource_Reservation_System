//The main cpp file


#include <iostream>
#include <string>
#include<limits>
#include <cstdlib>
#include "Reservation.h"
#include "Students.h"
#include "WaitingList.h"
#include "ReservationManager.h"
#include "ResourceManager.h"
#include "ReportGenerator.h"


using namespace std;

int read_int(const string& prompt, int min, int max);

int main() 
{
 int choice = -1;

 ResourceManager resource_manager;
 resource_manager.load_resources("data/resources.txt");
 ReservationManager manager;
 map<string, map<string,WaitingList>> waiting_lists;

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
    cout << "9. Withdrawal from waiting list" << endl;
    cout << "10. Reports" << endl;
    

    choice = read_int("Enter choice: ", 0, 10);


    switch(choice)
        {
            case 1: 
                resource_manager.display_resources();
                break;
            case 2: 
                {
                    string search_id;

                    cout << "Enter resource ID to search: ";
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
            case 3: 
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
            case 4: 
                {
                    string cancel_id;
                    cout << "Enter reservation ID to cancel: ";
                    cin >> cancel_id;

                    students temp_student{"", ""};

                    Reservation temp_reservation(cancel_id, temp_student, "", "");
                    manager.cancel_reservation(temp_reservation);

                
                break;
                }
            case 5: 
                manager.undo_cancel();
                break;
            case 6: 
                manager.display_reservations();
                break;
            case 7: 
                manager.display_cancellations();
                break;
            case 8: 
                for (const auto& pair : waiting_lists)
                {
                    const string& resource_id = pair.first;
                    const WaitingList& wl = pair.second;
                    cout << "Resource ID: " << resource_id << endl;
                    wl.display_list();
                }
                break;
            case 9: 
                     
            {
                students removed_student;
                string resource_id;
                string date;
                cout << "Enter resource ID: ";
                cin >> resource_id;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter Student ID: ";
                cin >> removed_student.student_id;
                cout << "Enter Student Name: ";
                cin >> removed_student.student_name;
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
            
            case 10:
            {
                cout << "======Reports Menu======" << endl;
                cout << "1. Active Reservations" << endl;
                cout << "2. Resource Utilization" << endl;
                cout << "3. Most Requested Resources" << endl;
                cout << "4. Waitlist Statistics" << endl;
                cout << "5. All Reports" << endl;
                cout << "0. Back" << endl;
                int report_choice = read_int("Enter choice: ", 0, 5);
                switch(report_choice)
                {
                    case 1:
                        report_generator.active_reservations();
                        break;
                    case 2:
                        report_generator.resource_utilization();
                        break;
                    case 3:
                    {
                        int top_n = read_int("Enter the number of top requested resources: ", 1, 100);
                        report_generator.most_requested_resources(top_n);
                        break;
                    }
                    case 4:
                        report_generator.waitlist_statistics();
                        break;
                    case 5:
                        report_generator.all_reports();
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
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

int read_int(const string& prompt, int min, int max) {
    int value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.eof())
        {
            cout << endl << "Exiting program." << endl;
            exit(0);
        }

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (value < min || value > max)
        {
            cout << "Please enter a number between " << min << " and " << max << "." << endl;
            continue;
        }

        return value;
    }
}
