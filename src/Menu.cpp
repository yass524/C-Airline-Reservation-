#include "include/Menu.hpp"

#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits
#include <string>

void Menu::printWelcomeScreen() {
    std::cout << "Welcome to the Airline Reservation System!" << std::endl;
    std::cout << "Please select an option from the menu below:" << std::endl;
}

int Menu::showMainMenu() {
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Sign Up" << std::endl;
    std::cout << "3. Exit" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showLoginMenu() {
    std::cout << "Login Menu:" << std::endl;
    std::cout << "1. Administrator" << std::endl;
    std::cout << "2. Booking Agent" << std::endl;
    std::cout << "3. Passenger" << std::endl;
    std::cout << "4. Back to Main Menu" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}

int Menu::showAdministratorMenu() {
    std::cout << "Administrator Menu:" << std::endl;
    std::cout << "1. User Management" << std::endl;
    std::cout << "2. Flight Management" << std::endl;
    std::cout << "3. Aircraft Management" << std::endl;
    std::cout << "4. Reservation Management" << std::endl;
    std::cout << "5. Maintenance Management" << std::endl;
    std::cout << "6. Reports" << std::endl;
    std::cout << "7. Logout" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showBookingAgentMenu() {
    std::cout << "Booking Agent Menu:" << std::endl;
    std::cout << "1. Search Flights" << std::endl;
    std::cout << "2. Create Reservation" << std::endl;
    std::cout << "3. Update Reservation" << std::endl;
    std::cout << "4. Cancel Reservation" << std::endl;
    std::cout << "5. Process Payment" << std::endl;
    std::cout << "6. Check In Passenger" << std::endl;
    std::cout << "7. Generate Boarding Pass" << std::endl;
    std::cout << "8. Logout" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showPassengerMenu() {
    std::cout << "Passenger Menu:" << std::endl;
    std::cout << "1. Search Flights" << std::endl;
    std::cout << "2. Make Reservation" << std::endl;
    std::cout << "3. View My Reservations" << std::endl;
    std::cout << "4. Cancel Reservation" << std::endl;
    std::cout << "5. Check In Online" << std::endl;
    std::cout << "6. View Boarding Pass" << std::endl;
    std::cout << "7. Logout" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}

int Menu::showFlightManagementMenu() {
    std::cout << "Flight Management Menu:" << std::endl;
    std::cout << "1. Add Flight" << std::endl;
    std::cout << "2. Update Flight" << std::endl;
    std::cout << "3. Remove Flight" << std::endl;
    std::cout << "4. View All Flights" << std::endl;
    std::cout << "5. Back to Administrator Menu" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showAircraftManagementMenu() {
    std::cout << "Aircraft Management Menu:" << std::endl;
    std::cout << "1. Add Aircraft" << std::endl;
    std::cout << "2. Update Aircraft" << std::endl;
    std::cout << "3. Remove Aircraft" << std::endl;
    std::cout << "4. View All Aircraft" << std::endl;
    std::cout << "5. Back to Administrator Menu" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showReservationManagementMenu() {
    std::cout << "Reservation Management Menu:" << std::endl;
    std::cout << "1. Create Reservation" << std::endl;
    std::cout << "2. Update Reservation" << std::endl;
    std::cout << "3. Cancel Reservation" << std::endl;
    std::cout << "4. Back to Administrator Menu" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showMaintenanceManagementMenu() {
    std::cout << "Maintenance Management Menu:" << std::endl;
    std::cout << "1. Schedule Maintenance" << std::endl;
    std::cout << "2. Complete Maintenance" << std::endl;
    std::cout << "3. View All Maintenance Records" << std::endl;
    std::cout << "4. Back to Administrator Menu" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}
int Menu::showReportsMenu() {
    std::cout << "Reports Menu:" << std::endl;
    std::cout << "1. Flight Report" << std::endl;
    std::cout << "2. Reservation Report" << std::endl;
    std::cout << "3. Financial Report" << std::endl;
    std::cout << "4. Maintenance Report" << std::endl;
    std::cout << "5. Back to Administrator Menu" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return choice;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 0;
    }
}

void Menu::printDivider() {
    std::cout << "----------------------------------------" << std::endl;
}
void Menu::printHeader(const std::string& title) {
    printDivider();
    std::cout << title << std::endl;
    printDivider();
}
 int Menu::getIntegerInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        if (std::cin.eof()) {
            return 0;
        }
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}
double Menu::getDoubleInput(const std::string& prompt) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        if (std::cin.eof()) {
            return 0.0;
        }
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}
std::string Menu::getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin >> std::ws, value);
    return value;
}

std::string Menu::inputUserRole() {
    std::cout << "Select User Role:" << std::endl;
    std::cout << "1. Administrator" << std::endl;
    std::cout << "2. Booking Agent" << std::endl;
    std::cout << "3. Passenger" << std::endl;
    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1: return "Administrator";
        case 2: return "Booking Agent";
        case 3: return "Passenger";
        default: return "Unknown";
    }
}
std::string Menu::inputSeatClass() {
    std::cout << "Select Seat Class:" << std::endl;
    std::cout << "1. Economy" << std::endl;
    std::cout << "2. Business" << std::endl;
    std::cout << "3. First Class" << std::endl;

    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1: return "Economy";
        case 2: return "Business";
        case 3: return "First Class";
        default: return "Unknown";
    }
}
std::string Menu::inputFlightStatus() {
    std::cout << "Select Flight Status:" << std::endl;
    std::cout << "1. Scheduled" << std::endl;
    std::cout << "2. Delayed" << std::endl;
    std::cout << "3. Cancelled" << std::endl;
    std::cout << "4. Completed" << std::endl;
    int choice = getIntegerInput("Enter your choice: ");
    switch (choice) {
        case 1: return "Scheduled";
        case 2: return "Delayed";
        case 3: return "Cancelled";
        case 4: return "Completed";
        default: return "Unknown";
    }
}

void Menu::pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Menu::clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
