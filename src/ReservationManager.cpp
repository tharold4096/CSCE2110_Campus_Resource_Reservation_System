#include "ReservationManager.h"
#include <iostream>
#include <vector>

using namespace std;



void ReservationManager::create_reservation(const Reservation& reservation) {

	// checking if res should be allowed & adding to linked list
	if (validate_reservation(reservation)) {
		reservations.insert_at_end(reservation);
		cout << "Reservation created successfully." << endl;
	}

	else {

		cout << "Reservation could not be created." << endl;
	}
}



// reject if any required fields are missing / another res already has 
bool ReservationManager::validate_reservation(const Reservation& reservation) const {
	
	if (reservation.get_reservation_id().empty()) {
		return false;
	}
	if (reservation.get_student_id().empty()) {
		return false;
	}
	if (reservation.get_resource_id().empty()) {
		return false;

	}
	if (reservation.get_date().empty()) {
		return false;
	}

	vector<Reservation> all_reservations = reservations.get_all();

	for (const Reservation& existing : all_reservations) {
		if (existing.get_reservation_id() == reservation.get_reservation_id()) {
			return false;
		}
	}
	return true;
}



// displays all active res if not empty 
void ReservationManager::display_reservations() const {
	vector<Reservation> all_reservations = reservations.get_all();

	if (all_reservations.empty()) {
		cout << "No active reservation." << endl;
		return;
	}

	cout << "Active Reservations: " << endl;

	for (const Reservation& reservation : all_reservations) {
		reservation.print();
		cout << endl;
	}
}


void ReservationManager::cancel_reservation(const Reservation& reservation) {
	if (reservations.remove(reservation)) {
		cout << "Reservation cancelled successfully. " << endl;
	}
	else {
		cout << "Reservation not found. " << endl;
	}
}

