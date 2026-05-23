#include "include/Passenger.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

Passenger::Passenger()
    : User(0, "", "", "", "", "Passenger"), loyaltyPoints(0) {}

Passenger::Passenger(int userId,
                     const std::string& username,
                     const std::string& passwordHash,
                     const std::string& fullName,
                     const std::string& email,
                     const std::string& phoneNumber,
                     const std::string& passportNumber,
                     const std::string& nationality)
    : User(userId, fullName.empty() ? username : fullName, email, passwordHash, phoneNumber, "Passenger"),
      passportNumber(passportNumber),
      nationality(nationality),
      loyaltyPoints(0) {}

void Passenger::showMenu() {
    std::cout << "Passenger Menu:" << std::endl;
    std::cout << "1. Search Flights" << std::endl;
    std::cout << "2. Make Booking" << std::endl;
    std::cout << "3. Modify Booking" << std::endl;
    std::cout << "4. Cancel Booking" << std::endl;
    std::cout << "5. View Bookings" << std::endl;
    std::cout << "6. Check In Online" << std::endl;
    std::cout << "7. View Boarding Pass" << std::endl;
    std::cout << "8. View Profile" << std::endl;
}

std::string Passenger::getPassportNumber() const { return passportNumber; }
std::string Passenger::getNationality() const { return nationality; }
int Passenger::getLoyaltyPoints() const { return loyaltyPoints; }
std::vector<int> Passenger::getReservationIds() const { return reservationIds; }
std::vector<std::string> Passenger::getTravelHistory() const { return travelHistory; }
std::string Passenger::getSeatPreference() const { return ""; }
std::string Passenger::getMealPreference() const { return mealPreference; }

void Passenger::setPassportNumber(const std::string& passportNumber) { this->passportNumber = passportNumber; }
void Passenger::setNationality(const std::string& nationality) { this->nationality = nationality; }
void Passenger::setSeatPreference(const std::string& seatPreference) { (void)seatPreference; }
void Passenger::setMealPreference(const std::string& mealPreference) { this->mealPreference = mealPreference; }
void Passenger::addReservationId(int reservationId) { reservationIds.push_back(reservationId); }
void Passenger::removeReservationId(int reservationId) { reservationIds.erase(std::remove(reservationIds.begin(), reservationIds.end(), reservationId), reservationIds.end()); }
void Passenger::addTravelHistory(const std::string& flightInfo) { travelHistory.push_back(flightInfo); }
void Passenger::addLoyaltyPoints(int points) { loyaltyPoints += points; }

bool Passenger::redeemLoyaltyPoints(int points) {
    if (points > loyaltyPoints) {
        return false;
    }
    loyaltyPoints -= points;
    return true;
}

void Passenger::searchFlights() const {
    std::string origin;
    std::string destination;
    std::string date;

    std::cout << "Enter origin, destination, date: ";
    std::cin >> origin >> destination >> date;
    std::cout << "Search request captured for " << origin << " to " << destination << " on " << date << ".\n";
}

void Passenger::makeBooking() {
    int flightId;
    std::string seatNumber;
    std::string seatClass;

    std::cout << "Enter flight ID, seat number, seat class: ";
    std::cin >> flightId >> seatNumber >> seatClass;
    std::cout << "Booking request captured for flight ID " << flightId << ".\n";
}

void Passenger::cancelBooking() {
    int reservationId;
    std::cout << "Enter reservation ID to cancel: ";
    std::cin >> reservationId;
    std::cout << "Cancellation request captured for reservation ID " << reservationId << ".\n";
}

void Passenger::checkInOnline() {
    int reservationId;
    std::cout << "Enter reservation ID for online check-in: ";
    std::cin >> reservationId;
    std::cout << "Online check-in request captured for reservation ID " << reservationId << ".\n";
}

void Passenger::viewBookings() const {
    if (reservationIds.empty()) {
        std::cout << "No reservation IDs stored in this passenger object.\n";
        return;
    }

    std::cout << "Reservation IDs: ";
    for (int reservationId : reservationIds) {
        std::cout << reservationId << " ";
    }
    std::cout << std::endl;
}

void Passenger::viewProfile() const {
    displayInfo();
}

void Passenger::updateProfile() {
    std::cout << "Enter passport number, nationality, meal preference: ";
    std::cin >> passportNumber >> nationality >> mealPreference;
    std::cout << "Passenger profile updated.\n";
}

void Passenger::displayInfo() const {
    User::displayInfo();
    std::cout << "Passport Number: " << passportNumber << std::endl;
    std::cout << "Nationality: " << nationality << std::endl;
    std::cout << "Loyalty Points: " << loyaltyPoints << std::endl;
    std::cout << "Meal Preference: " << mealPreference << std::endl;
}
