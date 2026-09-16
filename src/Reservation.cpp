#include "Reservation.h"
#include <iostream>


Reservation::Reservation(string reservation_id, students s, string resource_id, string date)
    : reservation_id(reservation_id), student(s), resource_id(resource_id), date(date) {}

string Reservation::get_reservation_id() const {
    return reservation_id;
}

string Reservation::get_student_id() const {
    return student.student_id;
}

string Reservation::get_student_name() const {
    return student.student_name;
}

string Reservation::get_date() const {
    return date;
}   

string Reservation::get_resource_id() const {
    return resource_id;
}


void Reservation::print() const {
    cout << "Reservation ID: " << reservation_id << endl;
    cout << "Student ID: " << student.student_id << endl;
    cout << "Student Name: " << student.student_name << endl;
    cout << "Resource ID: " << resource_id << endl;
    cout << "Date: " << date << endl;
}

bool Reservation::operator==(const Reservation& other) const {
    return reservation_id == other.reservation_id;
}
