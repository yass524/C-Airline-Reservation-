#include "include/BookingAgent.hpp"

#include <iostream>
#include <string>

BookingAgent::BookingAgent()
    : User(0, "", "", "", "", "Booking Agent") {}

BookingAgent::BookingAgent(int userId,
                           const std::string& username,
                           const std::string& passwordHash,
                           const std::string& fullName,
                           const std::string& email,
                           const std::string& phoneNumber)
    : User(userId, fullName.empty() ? username : fullName, email, passwordHash, phoneNumber, "Booking Agent") {}

void BookingAgent::showMenu() {
    std::cout << "Booking Agent Menu:" << std::endl;
    std::cout << "1. Search Flights" << std::endl;
    std::cout << "2. Create Reservation" << std::endl;
    std::cout << "3. Modify Reservation" << std::endl;
    std::cout << "4. Cancel Reservation" << std::endl;
    std::cout << "5. Process Payment" << std::endl;
    std::cout << "6. Airport Check-In" << std::endl;
    std::cout << "7. Generate Boarding Pass" << std::endl;
    std::cout << "8. Logout" << std::endl;
}

void BookingAgent::searchFlights() const {
    std::string origin;
    std::string destination;
    std::string date;

    std::cout << "Enter origin, destination, date: ";
    std::cin >> origin >> destination >> date;
    std::cout << "Search request captured for " << origin << " to " << destination << " on " << date << ".\n";
}

void BookingAgent::createReservation() {
    int passengerId;
    int flightId;
    std::string seatNumber;
    std::string seatClass;

    std::cout << "Enter passenger ID, flight ID, seat number, seat class: ";
    std::cin >> passengerId >> flightId >> seatNumber >> seatClass;
    std::cout << "Reservation creation request captured.\n";
}

void BookingAgent::modifyReservation() {
    int reservationId;
    std::string newSeatNumber;

    std::cout << "Enter reservation ID and new seat number: ";
    std::cin >> reservationId >> newSeatNumber;
    std::cout << "Reservation modification request captured for ID " << reservationId << ".\n";
}

void BookingAgent::cancelReservation() {
    int reservationId;
    std::cout << "Enter reservation ID to cancel: ";
    std::cin >> reservationId;
    std::cout << "Cancellation request captured for reservation ID " << reservationId << ".\n";
}

void BookingAgent::processPayment() {
    int reservationId;
    double amount;
    std::string method;

    std::cout << "Enter reservation ID, amount, payment method: ";
    std::cin >> reservationId >> amount >> method;
    std::cout << "Payment request captured.\n";
}

void BookingAgent::processRefund() {
    int paymentId;
    std::cout << "Enter payment ID to refund: ";
    std::cin >> paymentId;
    std::cout << "Refund request captured for payment ID " << paymentId << ".\n";
}

void BookingAgent::airportCheckIn() {
    int reservationId;
    std::cout << "Enter reservation ID for check-in: ";
    std::cin >> reservationId;
    std::cout << "Check-in request captured for reservation ID " << reservationId << ".\n";
}

void BookingAgent::generateBoardingPass() {
    int reservationId;
    std::cout << "Enter reservation ID for boarding pass: ";
    std::cin >> reservationId;
    std::cout << "Boarding pass request captured for reservation ID " << reservationId << ".\n";
}

void BookingAgent::viewPassengerProfile() const {
    int passengerId;
    std::cout << "Enter passenger ID to view: ";
    std::cin >> passengerId;
    std::cout << "Passenger profile request captured for passenger ID " << passengerId << ".\n";
}

void BookingAgent::updatePassengerProfile() {
    int passengerId;
    std::string newName;
    std::string newPhone;

    std::cout << "Enter passenger ID, new name, new phone: ";
    std::cin >> passengerId >> newName >> newPhone;
    std::cout << "Passenger profile update request captured.\n";
}
