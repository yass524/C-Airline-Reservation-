#include "include/BookingSystem.hpp"
#include "include/Menu.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace {
class SystemUser : public User {
public:
    SystemUser(int userId,
               const std::string& name,
               const std::string& email,
               const std::string& password,
               const std::string& phoneNumber,
               const std::string& role)
        : User(userId, name, email, password, phoneNumber, role) {}

    void showMenu() override {}
};

int nextIdFromUsers(const std::vector<std::shared_ptr<User>>& users) {
    int nextId = 1;
    for (const auto& user : users) {
        nextId = std::max(nextId, user->getUserId() + 1);
    }
    return nextId;
}

template <typename T, typename Getter>
int nextIdFromObjects(const std::vector<T>& objects, Getter getter) {
    int nextId = 1;
    for (const auto& object : objects) {
        nextId = std::max(nextId, getter(object) + 1);
    }
    return nextId;
}
}

BookingSystem::BookingSystem()
    : nextUserId(1),
      nextFlightId(1),
      nextAircraftId(1),
      nextReservationId(1),
      nextPaymentId(1),
      nextMaintenanceId(1) {}

void BookingSystem::run() {
    loadData();
    showMainMenu();
    saveData();
}

void BookingSystem::loadData() {
    users = dataManager.loadUsers();
    flights = dataManager.loadFlights();
    aircraftList = dataManager.loadAircraft();
    reservations = dataManager.loadReservations();
    payments = dataManager.loadPayments();
    maintenanceRecords = dataManager.loadMaintenanceRecords();

    for (const auto& user : users) {
        authService.addUser(user);
    }

    nextUserId = nextIdFromUsers(users);
    nextFlightId = nextIdFromObjects(flights, [](const Flight& flight) { return flight.getFlightId(); });
    nextAircraftId = nextIdFromObjects(aircraftList, [](const Aircraft& aircraft) { return aircraft.getAircraftId(); });
    nextReservationId = nextIdFromObjects(reservations, [](const Reservation& reservation) { return reservation.getReservationId(); });
    nextPaymentId = nextIdFromObjects(payments, [](const Payment& payment) { return payment.getPaymentId(); });
    nextMaintenanceId = nextIdFromObjects(maintenanceRecords, [](const Maintenance& maintenance) { return maintenance.getMaintenanceId(); });
}

void BookingSystem::saveData() {
    users = authService.getAllUsers();
    dataManager.saveUsers(users);
    dataManager.saveFlights(flights);
    dataManager.saveAircraft(aircraftList);
    dataManager.saveReservations(reservations);
    dataManager.savePayments(payments);
    dataManager.saveMaintenanceRecords(maintenanceRecords);
}

void BookingSystem::showMainMenu() {
    Menu::printWelcomeScreen();

    bool running = true;
    while (running) {
        int choice = Menu::showMainMenu();
        switch (choice) {
            case 1:
                showLoginMenu();
                break;
            case 2: {
                std::string name = Menu::getStringInput("Name: ");
                std::string email = Menu::getStringInput("Email: ");
                std::string password = Menu::getStringInput("Password: ");
                std::string phoneNumber = Menu::getStringInput("Phone number: ");
                std::string role = Menu::inputUserRole();

                if (name.empty()) {
                    std::cout << "Name is required. User was not registered.\n";
                    break;
                }
                if (email.empty()) {
                    std::cout << "Email is required. User was not registered.\n";
                    break;
                }
                if (password.empty()) {
                    std::cout << "Password is required. User was not registered.\n";
                    break;
                }
                if (phoneNumber.empty()) {
                    std::cout << "Phone number is required. User was not registered.\n";
                    break;
                }
                if (role == "Unknown") {
                    std::cout << "Choose role 1, 2, or 3. User was not registered.\n";
                    break;
                }

                auto user = std::make_shared<SystemUser>(generateUserId(), name, email, password, phoneNumber, role);
                if (authService.registerUser(user)) {
                    users = authService.getAllUsers();
                    saveData();
                    std::cout << "User registered successfully.\n";
                } else {
                    std::cout << "A user with this email already exists.\n";
                }
                break;
            }
            case 3:
                running = false;
                break;
            default:
                break;
        }
    }
}

void BookingSystem::showLoginMenu() {
    std::string email = Menu::getStringInput("Email: ");
    std::string password = Menu::getStringInput("Password: ");

    std::shared_ptr<User> user = authService.login(email, password);
    if (!user) {
        std::cout << "Invalid email or password.\n";
        return;
    }

    std::cout << "Login successful.\n";
    if (user->getRole() == "Administrator") {
        handleAdministratorMenu();
    } else if (user->getRole() == "Booking Agent") {
        handleBookingAgentMenu();
    } else {
        handlePassengerMenu();
    }
}

void BookingSystem::handleAdministratorMenu() {
    bool loggedIn = true;
    while (loggedIn) {
        int choice = Menu::showAdministratorMenu();
        switch (choice) {
            case 1:
                listUsers();
                break;
            case 2: {
                bool back = false;
                while (!back) {
                    int flightChoice = Menu::showFlightManagementMenu();
                    switch (flightChoice) {
                        case 1: {
                            std::string number = Menu::getStringInput("Flight number: ");
                            std::string origin = Menu::getStringInput("Origin: ");
                            std::string destination = Menu::getStringInput("Destination: ");
                            std::string departure = Menu::getStringInput("Departure time: ");
                            std::string arrival = Menu::getStringInput("Arrival time: ");
                            int aircraftId = Menu::getIntegerInput("Aircraft ID: ");
                            double price = Menu::getDoubleInput("Price: ");
                            addFlight(Flight(generateFlightId(), number, origin, destination, departure, arrival, aircraftId, price));
                            std::cout << "Flight added.\n";
                            break;
                        }
                        case 2:
                            updateFlight(Menu::getIntegerInput("Flight ID to update: "));
                            break;
                        case 3:
                            removeFlight(Menu::getIntegerInput("Flight ID to remove: "));
                            break;
                        case 4:
                            listFlights();
                            break;
                        case 5:
                            back = true;
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
            case 3: {
                bool back = false;
                while (!back) {
                    int aircraftChoice = Menu::showAircraftManagementMenu();
                    switch (aircraftChoice) {
                        case 1: {
                            std::string model = Menu::getStringInput("Model: ");
                            std::string manufacturer = Menu::getStringInput("Manufacturer: ");
                            int capacity = Menu::getIntegerInput("Capacity: ");
                            int economy = Menu::getIntegerInput("Economy seats: ");
                            int business = Menu::getIntegerInput("Business seats: ");
                            int firstClass = Menu::getIntegerInput("First class seats: ");
                            double range = Menu::getDoubleInput("Max range km: ");
                            addAircraft(Aircraft(generateAircraftId(), model, manufacturer, capacity, economy, business, firstClass, range));
                            std::cout << "Aircraft added.\n";
                            break;
                        }
                        case 2:
                            updateAircraft(Menu::getIntegerInput("Aircraft ID to update: "));
                            break;
                        case 3:
                            removeAircraft(Menu::getIntegerInput("Aircraft ID to remove: "));
                            break;
                        case 4:
                            listAircraft();
                            break;
                        case 5:
                            back = true;
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
            case 4:
                generateReservationReport();
                break;
            case 5:
                listMaintenanceRecords();
                break;
            case 6: {
                int reportChoice = Menu::showReportsMenu();
                switch (reportChoice) {
                    case 1: generateFlightReport(); break;
                    case 2: generateReservationReport(); break;
                    case 3: generateFinancialReport(); break;
                    case 4: generateMaintenanceReport(); break;
                    default: break;
                }
                break;
            }
            case 7:
                authService.logout();
                loggedIn = false;
                break;
            default:
                break;
        }
    }
}

void BookingSystem::handleBookingAgentMenu() {
    bool loggedIn = true;
    while (loggedIn) {
        int choice = Menu::showBookingAgentMenu();
        switch (choice) {
            case 1:
                listFlights();
                break;
            case 2: {
                int passengerId = Menu::getIntegerInput("Passenger ID: ");
                int flightId = Menu::getIntegerInput("Flight ID: ");
                std::string seatNumber = Menu::getStringInput("Seat number: ");
                std::string seatClass = Menu::inputSeatClass();
                createReservation(passengerId, flightId, seatNumber, seatClass);
                break;
            }
            case 3:
                modifyReservation(Menu::getIntegerInput("Reservation ID: "), Menu::getStringInput("New seat number: "));
                break;
            case 4:
                cancelReservation(Menu::getIntegerInput("Reservation ID: "));
                break;
            case 5:
                createPayment(Menu::getIntegerInput("Reservation ID: "), Menu::getDoubleInput("Amount: "), Menu::getStringInput("Payment method: "));
                break;
            case 6:
                checkInPassenger(Menu::getIntegerInput("Reservation ID: "));
                break;
            case 7:
                generateBoardingPass(Menu::getIntegerInput("Reservation ID: "));
                break;
            case 8:
                authService.logout();
                loggedIn = false;
                break;
            default:
                break;
        }
    }
}

void BookingSystem::handlePassengerMenu() {
    bool loggedIn = true;
    while (loggedIn) {
        int choice = Menu::showPassengerMenu();
        std::shared_ptr<User> currentUser = authService.getCurrentUser();
        int passengerId = currentUser ? currentUser->getUserId() : 0;

        switch (choice) {
            case 1:
                listFlights();
                break;
            case 2:
                createReservation(passengerId,
                                  Menu::getIntegerInput("Flight ID: "),
                                  Menu::getStringInput("Seat number: "),
                                  Menu::inputSeatClass());
                break;
            case 3: {
                std::vector<Reservation> myReservations = getReservationsByPassenger(passengerId);
                for (const Reservation& reservation : myReservations) {
                    reservation.displayInfo();
                }
                break;
            }
            case 4:
                cancelReservation(Menu::getIntegerInput("Reservation ID: "));
                break;
            case 5:
                checkInPassenger(Menu::getIntegerInput("Reservation ID: "));
                break;
            case 6:
                generateBoardingPass(Menu::getIntegerInput("Reservation ID: "));
                break;
            case 7:
                authService.logout();
                loggedIn = false;
                break;
            default:
                break;
        }
    }
}

void BookingSystem::addUser(std::shared_ptr<User> user) {
    authService.addUser(user);
    users = authService.getAllUsers();
}

bool BookingSystem::deleteUser(int userId) {
    bool removed = authService.removeUser(userId);
    users = authService.getAllUsers();
    return removed;
}

std::shared_ptr<User> BookingSystem::findUserById(int userId) const {
    return authService.findUserById(userId);
}

void BookingSystem::listUsers() const {
    for (const auto& user : users) {
        user->displayInfo();
        std::cout << "--------------------\n";
    }
}

void BookingSystem::addFlight(const Flight& flight) {
    flights.push_back(flight);
    saveData();
}

bool BookingSystem::updateFlight(int flightId) {
    Flight* flight = findFlightById(flightId);
    if (!flight) {
        std::cout << "Flight not found.\n";
        return false;
    }

    flight->setStatus(Menu::inputFlightStatus());
    flight->setPrice(Menu::getDoubleInput("New price: "));
    saveData();
    return true;
}

bool BookingSystem::removeFlight(int flightId) {
    auto it = std::remove_if(flights.begin(), flights.end(), [flightId](const Flight& flight) {
        return flight.getFlightId() == flightId;
    });

    if (it == flights.end()) {
        std::cout << "Flight not found.\n";
        return false;
    }

    flights.erase(it, flights.end());
    saveData();
    return true;
}

Flight* BookingSystem::findFlightById(int flightId) {
    for (Flight& flight : flights) {
        if (flight.getFlightId() == flightId) {
            return &flight;
        }
    }
    return nullptr;
}

std::vector<Flight> BookingSystem::searchFlights(const std::string& origin,
                                                 const std::string& destination,
                                                 const std::string& date) const {
    std::vector<Flight> results;
    for (const Flight& flight : flights) {
        if (flight.matchesSearch(origin, destination, date)) {
            results.push_back(flight);
        }
    }
    return results;
}

void BookingSystem::listFlights() const {
    for (const Flight& flight : flights) {
        flight.displayInfo();
        std::cout << "--------------------\n";
    }
}

void BookingSystem::addAircraft(const Aircraft& aircraft) {
    aircraftList.push_back(aircraft);
    saveData();
}

bool BookingSystem::updateAircraft(int aircraftId) {
    Aircraft* aircraft = findAircraftById(aircraftId);
    if (!aircraft) {
        std::cout << "Aircraft not found.\n";
        return false;
    }

    aircraft->setStatus(Menu::getStringInput("New status: "));
    saveData();
    return true;
}

bool BookingSystem::removeAircraft(int aircraftId) {
    auto it = std::remove_if(aircraftList.begin(), aircraftList.end(), [aircraftId](const Aircraft& aircraft) {
        return aircraft.getAircraftId() == aircraftId;
    });

    if (it == aircraftList.end()) {
        std::cout << "Aircraft not found.\n";
        return false;
    }

    aircraftList.erase(it, aircraftList.end());
    saveData();
    return true;
}

Aircraft* BookingSystem::findAircraftById(int aircraftId) {
    for (Aircraft& aircraft : aircraftList) {
        if (aircraft.getAircraftId() == aircraftId) {
            return &aircraft;
        }
    }
    return nullptr;
}

void BookingSystem::listAircraft() const {
    for (const Aircraft& aircraft : aircraftList) {
        aircraft.displayInfo();
        std::cout << "--------------------\n";
    }
}

bool BookingSystem::createReservation(int passengerId,
                                      int flightId,
                                      const std::string& seatNumber,
                                      const std::string& seatClass) {
    Flight* flight = findFlightById(flightId);
    if (!flight) {
        std::cout << "Flight not found.\n";
        return false;
    }

    if (!flight->reserveSeat(seatNumber)) {
        std::cout << "Seat is not available or seat map was not initialized. Reservation will still be created.\n";
    }

    Reservation reservation(generateReservationId(), passengerId, flightId, seatNumber, seatClass, 0, "Today");
    reservation.confirm();
    reservations.push_back(reservation);
    saveData();
    std::cout << "Reservation created.\n";
    return true;
}

bool BookingSystem::cancelReservation(int reservationId) {
    Reservation* reservation = findReservationById(reservationId);
    if (!reservation) {
        std::cout << "Reservation not found.\n";
        return false;
    }

    reservation->cancel();
    Flight* flight = findFlightById(reservation->getFlightId());
    if (flight) {
        flight->releaseSeat(reservation->getSeatNumber());
    }
    saveData();
    return true;
}

bool BookingSystem::modifyReservation(int reservationId, const std::string& newSeatNumber) {
    Reservation* reservation = findReservationById(reservationId);
    if (!reservation) {
        std::cout << "Reservation not found.\n";
        return false;
    }

    Flight* flight = findFlightById(reservation->getFlightId());
    if (flight) {
        flight->releaseSeat(reservation->getSeatNumber());
        flight->reserveSeat(newSeatNumber);
    }

    reservation->setSeatNumber(newSeatNumber);
    saveData();
    return true;
}

Reservation* BookingSystem::findReservationById(int reservationId) {
    for (Reservation& reservation : reservations) {
        if (reservation.getReservationId() == reservationId) {
            return &reservation;
        }
    }
    return nullptr;
}

std::vector<Reservation> BookingSystem::getReservationsByPassenger(int passengerId) const {
    std::vector<Reservation> result;
    for (const Reservation& reservation : reservations) {
        if (reservation.getPassengerId() == passengerId) {
            result.push_back(reservation);
        }
    }
    return result;
}

bool BookingSystem::createPayment(int reservationId, double amount, const std::string& paymentMethod) {
    if (!findReservationById(reservationId)) {
        std::cout << "Reservation not found.\n";
        return false;
    }

    Payment payment(generatePaymentId(), reservationId, amount, paymentMethod, "Today");
    payment.processPayment();
    payments.push_back(payment);
    saveData();
    std::cout << "Payment created.\n";
    return true;
}

bool BookingSystem::refundPayment(int paymentId) {
    Payment* payment = findPaymentById(paymentId);
    if (!payment) {
        std::cout << "Payment not found.\n";
        return false;
    }

    bool refunded = payment->processRefund();
    saveData();
    return refunded;
}

Payment* BookingSystem::findPaymentById(int paymentId) {
    for (Payment& payment : payments) {
        if (payment.getPaymentId() == paymentId) {
            return &payment;
        }
    }
    return nullptr;
}

bool BookingSystem::checkInPassenger(int reservationId) {
    Reservation* reservation = findReservationById(reservationId);
    if (!reservation) {
        std::cout << "Reservation not found.\n";
        return false;
    }

    reservation->markCheckedIn();
    saveData();
    return true;
}

void BookingSystem::generateBoardingPass(int reservationId) const {
    for (const Reservation& reservation : reservations) {
        if (reservation.getReservationId() == reservationId) {
            std::cout << "Boarding Pass\n";
            std::cout << "Reservation ID: " << reservation.getReservationId() << '\n';
            std::cout << "Passenger ID: " << reservation.getPassengerId() << '\n';
            std::cout << "Flight ID: " << reservation.getFlightId() << '\n';
            std::cout << "Seat: " << reservation.getSeatNumber() << '\n';
            return;
        }
    }
    std::cout << "Reservation not found.\n";
}

void BookingSystem::scheduleMaintenance(const Maintenance& maintenance) {
    maintenanceRecords.push_back(maintenance);
    saveData();
}

bool BookingSystem::completeMaintenance(int maintenanceId, const std::string& completedDate) {
    Maintenance* maintenance = findMaintenanceById(maintenanceId);
    if (!maintenance) {
        std::cout << "Maintenance record not found.\n";
        return false;
    }

    maintenance->completeMaintenance(completedDate);
    saveData();
    return true;
}

Maintenance* BookingSystem::findMaintenanceById(int maintenanceId) {
    for (Maintenance& maintenance : maintenanceRecords) {
        if (maintenance.getMaintenanceId() == maintenanceId) {
            return &maintenance;
        }
    }
    return nullptr;
}

void BookingSystem::listMaintenanceRecords() const {
    for (const Maintenance& maintenance : maintenanceRecords) {
        maintenance.displayInfo();
        std::cout << "--------------------\n";
    }
}

void BookingSystem::generateFlightReport() const {
    std::cout << "Total flights: " << flights.size() << '\n';
    listFlights();
}

void BookingSystem::generateReservationReport() const {
    std::cout << "Total reservations: " << reservations.size() << '\n';
    for (const Reservation& reservation : reservations) {
        reservation.displayInfo();
        std::cout << "--------------------\n";
    }
}

void BookingSystem::generateFinancialReport() const {
    double total = 0.0;
    for (const Payment& payment : payments) {
        if (payment.isCompleted()) {
            total += payment.getAmount();
        }
    }
    std::cout << "Completed payment total: " << total << '\n';
}

void BookingSystem::generateMaintenanceReport() const {
    std::cout << "Total maintenance records: " << maintenanceRecords.size() << '\n';
    listMaintenanceRecords();
}

int BookingSystem::generateUserId() {
    return nextUserId++;
}

int BookingSystem::generateFlightId() {
    return nextFlightId++;
}

int BookingSystem::generateAircraftId() {
    return nextAircraftId++;
}

int BookingSystem::generateReservationId() {
    return nextReservationId++;
}

int BookingSystem::generatePaymentId() {
    return nextPaymentId++;
}

int BookingSystem::generateMaintenanceId() {
    return nextMaintenanceId++;
}
