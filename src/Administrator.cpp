#include "include/Administrator.hpp"

#include <iostream>
#include <string>

Administrator::Administrator()
    : User(0, "", "", "", "", "Administrator") {}

Administrator::Administrator(int userId,
                             const std::string& username,
                             const std::string& passwordHash,
                             const std::string& fullName,
                             const std::string& email,
                             const std::string& phoneNumber)
    : User(userId, fullName.empty() ? username : fullName, email, passwordHash, phoneNumber, "Administrator") {}

void Administrator::showMenu() {
    std::cout << "Administrator Menu:" << std::endl;
    std::cout << "1. User Management" << std::endl;
    std::cout << "2. Flight Management" << std::endl;
    std::cout << "3. Aircraft Management" << std::endl;
    std::cout << "4. Crew Assignment" << std::endl;
    std::cout << "5. Generate Reports" << std::endl;
    std::cout << "6. Logout" << std::endl;
}

void Administrator::createUser() {
    int newUserId;
    std::string newName;
    std::string newEmail;
    std::string newPassword;
    std::string newPhoneNumber;
    std::string newRole;

    std::cout << "Creating a new user..." << std::endl;
    std::cout << "Enter user details (ID Name Email Password Phone Role): ";
    std::cin >> newUserId >> newName >> newEmail >> newPassword >> newPhoneNumber >> newRole;

    std::cout << "User data captured. BookingSystem should store it in the users list.\n";
}

void Administrator::updateUser() {
    int targetUserId;
    std::string newName;
    std::string newEmail;
    std::string newPhoneNumber;

    std::cout << "Enter user ID to update: ";
    std::cin >> targetUserId;
    std::cout << "Enter new name, email, and phone number: ";
    std::cin >> newName >> newEmail >> newPhoneNumber;

    std::cout << "Update request captured for user ID " << targetUserId << ".\n";
}

void Administrator::deleteUser() {
    int userIdToDelete;
    std::cout << "Enter the ID of the user to delete: ";
    std::cin >> userIdToDelete;
    std::cout << "Delete request captured for user ID " << userIdToDelete << ".\n";
}

void Administrator::viewAllUsers() const {
    std::cout << "Viewing all users should be handled by BookingSystem because it owns the users list.\n";
}

void Administrator::addFlight() {
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    int aircraftId;
    double price;

    std::cout << "Enter flight number, origin, destination, departure, arrival, aircraft ID, price: ";
    std::cin >> flightNumber >> origin >> destination >> departureTime >> arrivalTime >> aircraftId >> price;
    std::cout << "Flight data captured. BookingSystem should store it in the flights list.\n";
}

void Administrator::updateFlight() {
    int flightId;
    std::string status;
    double price;

    std::cout << "Enter flight ID, new status, new price: ";
    std::cin >> flightId >> status >> price;
    std::cout << "Update request captured for flight ID " << flightId << ".\n";
}

void Administrator::removeFlight() {
    int flightId;
    std::cout << "Enter flight ID to remove: ";
    std::cin >> flightId;
    std::cout << "Remove request captured for flight ID " << flightId << ".\n";
}

void Administrator::viewAllFlights() const {
    std::cout << "Viewing all flights should be handled by BookingSystem because it owns the flights list.\n";
}

void Administrator::addAircraft() {
    std::string model;
    std::string manufacturer;
    int capacity;

    std::cout << "Enter aircraft model, manufacturer, capacity: ";
    std::cin >> model >> manufacturer >> capacity;
    std::cout << "Aircraft data captured. BookingSystem should store it in the aircraft list.\n";
}

void Administrator::updateAircraft() {
    int aircraftId;
    std::string status;

    std::cout << "Enter aircraft ID and new status: ";
    std::cin >> aircraftId >> status;
    std::cout << "Update request captured for aircraft ID " << aircraftId << ".\n";
}

void Administrator::removeAircraft() {
    int aircraftId;
    std::cout << "Enter aircraft ID to remove: ";
    std::cin >> aircraftId;
    std::cout << "Remove request captured for aircraft ID " << aircraftId << ".\n";
}

void Administrator::viewAllAircraft() const {
    std::cout << "Viewing all aircraft should be handled by BookingSystem because it owns the aircraft list.\n";
}

void Administrator::assignCrewToFlight() {
    int flightId;
    int crewId;

    std::cout << "Enter flight ID and crew member ID: ";
    std::cin >> flightId >> crewId;
    std::cout << "Crew assignment request captured.\n";
}

void Administrator::generateOperationalReport() const {
    std::cout << "Operational report requested. BookingSystem should calculate report data.\n";
}

void Administrator::generateFinancialReport() const {
    std::cout << "Financial report requested. BookingSystem should calculate payment totals.\n";
}

void Administrator::generateUserActivityReport() const {
    std::cout << "User activity report requested. BookingSystem should calculate user activity.\n";
}
