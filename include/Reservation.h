#ifndef RESERVATION_H
#define RESERVATION_H
using namespace std;
class Reservation 
{
    private:
        int id;
        string reservation_id;
        string student_id;
        string student_name;
        string resource_id;
        string date;

    public:
        Reservation(string reservation_id, string student_id, string student_name, string date);
        //int get_id() const;
        string get_reservation_id() const;
        string get_student_id() const;
        string get_student_name() const;
        string get_date() const;
        string get_resource_id() const;
        void print() const;
};

#endif // RESERVATION_H