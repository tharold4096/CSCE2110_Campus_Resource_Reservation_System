#ifndef RESERVATIONMANAGER_H  //  header gaurds 
#define RESERVATIONMANAGER_H


#include "LinkedList.h" 
#include "Reservation.h"   

class ReservationManager {


private:
	LinkedList<Reservation> reservations;  // res are stored in linked list

public:
	  void create_reservation(const Reservation& reservation);
	  void cancel_reservation(cost Reservation& reservation);
	  void display_reservations() const;
	  bool validate_reservation(const Reservation& reservation) const;
};
#endif

