#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation 
{
    private:
        int id;
        std::string reservation_id;
        std::string student_id;
        std::string student_name;
        std::string date;

    public:
        Reservation(int id, const std::string& reservation_id, const std::string& student_id, const std::string& student_name, const std::string& date);
        int get_id() const;
        std::string get_reservation_id() const;
        std::string get_student_id() const;
        std::string get_student_name() const;
        std::string get_date() const;
        std::string get_time() const;
        void print() const;
};

#endif // RESERVATION_H