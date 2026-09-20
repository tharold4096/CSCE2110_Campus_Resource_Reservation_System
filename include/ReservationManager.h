#ifndef RESERVATIONMANAGER_H  //  header gaurds 
#define RESERVATIONMANAGER_H

#include "Cancellations.h" 
#include "LinkedList.h" 
#include "Reservation.h"   

class ReservationManager {


private:
	LinkedList<Reservation> reservations;  // res are stored in linked list
	Cancellations cancellation;

public:
	  bool create_reservation(const Reservation& reservation);
	  void cancel_reservation(const Reservation& reservation);
	  void display_reservations() const;
	  bool validate_reservation(const Reservation& reservation) const;
	  bool is_resource_taken(const string& resource_id, const string& date) const;
	  bool undo_cancel();
	  void display_cancellations();
};
#endif

