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
bool valid_date(const string& date);
string generate_reservation_id();

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

                reservation_id =generate_reservation_id();

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
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                if (!valid_date(date)) {
                    cout << "Invalid date format. Please enter in YYYY-MM-DD format." << endl;
                    break;
                }
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
                    
                    if (waiting_lists[resource_id][date].enqueue(student))
                        cout << "Student added to the waiting list for " << resource_id << " on " << date << endl;
                }

        
                
                break;
            }    
            case 4: 
                {
                    string cancel_id;
                    cout << "Enter reservation ID to cancel: ";
                    cin >> cancel_id;

                    
                    Reservation cancelled("", students{"", ""}, "", "");
                    if (!manager.cancel_reservation(cancel_id, cancelled))
                        break;
                    cout << "Reservation cancelled successfully." << endl;

                    //Create variables based on the most recent canceled reservation, passed from the updated method
                    const string resource_id = cancelled.get_resource_id();           
                    const string date = cancelled.get_date();

                    // Search the waiting list outer map for the matching resource id, breaking if end is reached.
                    auto res_it = waiting_lists.find(resource_id);               
                    if(res_it == waiting_lists.end())
                        break;
                    
                    // Search the inner map for the matching data, breaking if the end is reached.
                    auto slot_it = res_it->second.find(date);
                    if(slot_it == res_it->second.end())
                        break;

                    //Dequeue the next student from the waiting list so that they can reserve the slot. 
                    students next;
                    if (!slot_it->second.dequeue(next))
                        break;

                    //Create the promoted reservation based on that student
                    Reservation promoted(cancelled.get_reservation_id(), next, resource_id, date);
                    if (manager.create_reservation(promoted))
                        cout << "Promoted " << next.student_name << " (" << next.student_id
                             << ") from the waiting list for " << resource_id << " on " << date << "." << endl;
                
                break;
                }
            case 5: 
                //Undoing fails if the queue already moved forward.
                if(manager.undo_cancel())
                    cout << "Reservation restored." << endl;
                else
                    cout << "Nothing to undo, or the slot was given to the next waiting student." << endl;
                break;
            case 6: 
                manager.display_reservations();
                break;
            case 7: 
                manager.display_cancellations();
                break;
            case 8: 
            {
                for (const auto& pair : waiting_lists)
                {
                    bool any_waiting = false;
                    const string& resource_id = pair.first;
                    const auto& inner_map = pair.second;
                    for (const auto& inner_pair : inner_map)
                    {
                        const string& date = inner_pair.first;
                        const WaitingList& wl = inner_pair.second;
                        if (wl.is_empty()) continue;
                        any_waiting = true;
                        cout << "Resource ID: " << resource_id << " | Date: " << date << endl;
                        wl.display_list();
                    }
                    if (!any_waiting) cout << "No students are waiting." << endl;
                }
                break;
            }
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
                

                if(!valid_date(date)) {
                    cout << "Invalid date format." << endl;
                    break;
                }

                auto it = waiting_lists.find(resource_id);
                if (it == waiting_lists.end())
                {
                    cout << "No waiting list for " << resource_id << "." << endl;
                    break;
                }
                auto slot = it->second.find(date);
                if (slot == it->second.end())
                {
                    cout << "No waiting list for " << resource_id << " on " << date << "." << endl;
                    break;
                }
                if(slot->second.remove_student(removed_student))
                {
                    /*
                    cout << "Student removed from waiting list." << endl;
                    cout << "Student ID: " << removed_student.student_id << endl;
                    cout << "Student Name: " << removed_student.student_name << endl;
                    */

                    cout << "Student " << removed_student.student_id << " withdrawn from the waiting list for "
                         << resource_id << " on " << date << "." << endl;

                }
                else
                {
                    cout << "Student " << removed_student.student_id << " is not on the waiting list for "
                         << resource_id << " on " << date << "." << endl;

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

bool valid_date(const string& date) {
    // Check for YYYY-MM-DD format
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    return true;
}


string generate_reservation_id() {
    static int counter = 1;
    return "RES" + to_string(counter++);
}
