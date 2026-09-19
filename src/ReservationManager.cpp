#include "ReservationManager.h"
#include <iostream>
#include <vector>

using namespace std;



bool ReservationManager::create_reservation(const Reservation& reservation) {

	// checking if res should be allowed & adding to linked list
	if (validate_reservation(reservation)) {
		reservations.insert_at_end(reservation);
		cout << "Reservation created successfully." << endl;
		return true;
	}

	else {

		cout << "Reservation could not be created." << endl;
		return false;
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
		if (existing.get_reservation_id() == reservation.get_reservation_id()) { //stops duplicate reservation ID
			return false;
		}
		if (existing.get_resource_id() == reservation.get_resource_id() &&   //stops the same resource to provent double reservation
			existing.get_date() == reservation.get_date()) {    
			
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
	vector<Reservation> all_reservations = reservations.get_all();
	int found = -1;
	for (int i = 0; i < (int)all_reservations.size(); i++) {
		if (all_reservations[i].get_reservation_id() == reservation.get_reservation_id()) {
			found = i;
			break;
		}
	}

	if (found == -1) {
		cout << "Reservation not found. " << endl;
		return;
	}

	Reservation reservation_found = all_reservations[found];
	reservations.remove(reservation_found);
	cancellation.push(reservation_found);
	cout << "Reservation cancelled successfully. " << endl;
}

