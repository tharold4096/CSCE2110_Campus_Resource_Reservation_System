#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
using namespace std;
struct students
{
    string student_id;
    string student_name;

    bool operator==(const students& other) const
    {
          return student_id == other.student_id;
    }
    
    void print() const
    {
        cout << student_name << " (" << student_id << ")";
    }
    
};

#endif // STUDENTS_H