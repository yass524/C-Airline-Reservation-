#include "include/DataManager.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace {
class StoredUser : public User {
public:
    StoredUser(int userId,
               const std::string& name,
               const std::string& email,
               const std::string& password,
               const std::string& phoneNumber,
               const std::string& role)
        : User(userId, name, email, password, phoneNumber, role) {}

    void showMenu() override {}
};

std::vector<std::string> splitCsvLine(const std::string& line) {
    std::vector<std::string> tokens;
    std::istringstream stream(line);
    std::string token;

    while (std::getline(stream, token, ',')) {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<std::string> splitList(const std::string& value) {
    std::vector<std::string> items;
    std::istringstream stream(value);
    std::string item;

    while (std::getline(stream, item, '|')) {
        if (!item.empty()) {
            items.push_back(item);
        }
    }

    return items;
}

std::string joinStrings(const std::vector<std::string>& values) {
    std::ostringstream stream;

    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            stream << '|';
        }
        stream << values[i];
    }

    return stream.str();
}

std::string joinInts(const std::vector<int>& values) {
    std::ostringstream stream;

    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            stream << '|';
        }
        stream << values[i];
    }

    return stream.str();
}

bool isBlankLine(const std::string& line) {
    return line.find_first_not_of(" \t\r\n") == std::string::npos;
}

bool isHeaderRow(const std::vector<std::string>& tokens) {
    if (tokens.empty()) {
        return true;
    }

    try {
        std::stoi(tokens[0]);
        return false;
    } catch (...) {
        return true;
    }
}
}

DataManager::DataManager() {
    usersFilePath = "Data/users.csv";
    flightsFilePath = "Data/flights.csv";
    aircraftFilePath = "Data/aircraft.csv";
    reservationsFilePath = "Data/reservations.csv";
    paymentsFilePath = "Data/payments.csv";
    maintenanceFilePath = "Data/maintenance.csv";
}

DataManager::DataManager(const std::string& usersFilePath,const std::string& flightsFilePath,const std::string& aircraftFilePath,const std::string& reservationsFilePath,const std::string& paymentsFilePath, const std::string& maintenanceFilePath)
    : usersFilePath(usersFilePath),
      flightsFilePath(flightsFilePath),
      aircraftFilePath(aircraftFilePath),
      reservationsFilePath(reservationsFilePath),
      paymentsFilePath(paymentsFilePath),
      maintenanceFilePath(maintenanceFilePath) {}

void DataManager::setUsersFilePath(const std::string& path) {
    usersFilePath = path;
}

void DataManager::setFlightsFilePath(const std::string& path) {
    flightsFilePath = path;
}

void DataManager::setAircraftFilePath(const std::string& path) {
    aircraftFilePath = path;
}

void DataManager::setReservationsFilePath(const std::string& path) {
    reservationsFilePath = path;
}

void DataManager::setPaymentsFilePath(const std::string& path) {
    paymentsFilePath = path;
}

void DataManager::setMaintenanceFilePath(const std::string& path) {
    maintenanceFilePath = path;
}

std::vector<std::shared_ptr<User>> DataManager::loadUsers() {
    std::vector<std::shared_ptr<User>> users;
    std::ifstream file(usersFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << usersFilePath << std::endl;
        return users;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isBlankLine(line)) {
            continue;
        }

        std::vector<std::string> tokens = splitCsvLine(line);
        if (isHeaderRow(tokens) || tokens.size() < 6) {
            continue;
        }

        try {
            users.push_back(std::make_shared<StoredUser>(
                std::stoi(tokens[0]),
                tokens[1],
                tokens[2],
                tokens[3],
                tokens[4],
                tokens[5]));
        } catch (const std::exception& error) {
            std::cerr << "Skipping invalid user row: " << error.what() << std::endl;
        }
    }

    return users;
}

std::vector<Flight> DataManager::loadFlights() {
    std::vector<Flight> flights;
    std::ifstream file(flightsFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << flightsFilePath << std::endl;
        return flights;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isBlankLine(line)) {
            continue;
        }

        std::vector<std::string> tokens = splitCsvLine(line);
        if (isHeaderRow(tokens) || tokens.size() < 9) {
            continue;
        }

        try {
            Flight flight(std::stoi(tokens[0]),
                          tokens[1],
                          tokens[2],
                          tokens[3],
                          tokens[4],
                          tokens[5],
                          std::stoi(tokens[6]),
                          std::stod(tokens[8]));

            flight.setStatus(tokens[7]);

            if (tokens.size() > 9) {
                for (const std::string& crewId : splitList(tokens[9])) {
                    flight.assignCrewMember(std::stoi(crewId));
                }
            }

            flights.push_back(flight);
        } catch (const std::exception& error) {
            std::cerr << "Skipping invalid flight row: " << error.what() << std::endl;
        }
    }

    return flights;
}

std::vector<Aircraft> DataManager::loadAircraft() {
    std::vector<Aircraft> aircraftList;
    std::ifstream file(aircraftFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << aircraftFilePath << std::endl;
        return aircraftList;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isBlankLine(line)) {
            continue;
        }

        std::vector<std::string> tokens = splitCsvLine(line);
        if (isHeaderRow(tokens) || tokens.size() < 9) {
            continue;
        }

        try {
            Aircraft aircraft(std::stoi(tokens[0]),
                              tokens[1],
                              tokens[2],
                              std::stoi(tokens[3]),
                              std::stoi(tokens[4]),
                              std::stoi(tokens[5]),
                              std::stoi(tokens[6]),
                              std::stod(tokens[7]));

            aircraft.setStatus(tokens[8]);

            if (tokens.size() > 9) {
                for (const std::string& maintenanceId : splitList(tokens[9])) {
                    aircraft.addMaintenanceId(std::stoi(maintenanceId));
                }
            }

            aircraftList.push_back(aircraft);
        } catch (const std::exception& error) {
            std::cerr << "Skipping invalid aircraft row: " << error.what() << std::endl;
        }
    }

    return aircraftList;
}

std::vector<Reservation> DataManager::loadReservations() {
    std::vector<Reservation> reservations;
    std::ifstream file(reservationsFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << reservationsFilePath << std::endl;
        return reservations;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isBlankLine(line)) {
            continue;
        }

        std::vector<std::string> tokens = splitCsvLine(line);
        if (isHeaderRow(tokens) || tokens.size() < 8) {
            continue;
        }

        try {
            Reservation reservation(std::stoi(tokens[0]),
                                    std::stoi(tokens[1]),
                                    std::stoi(tokens[2]),
                                    tokens[3],
                                    tokens[4],
                                    std::stoi(tokens[6]),
                                    tokens[7]);

            reservation.setStatus(tokens[5]);
            reservations.push_back(reservation);
        } catch (const std::exception& error) {
            std::cerr << "Skipping invalid reservation row: " << error.what() << std::endl;
        }
    }

    return reservations;
}

std::vector<Payment> DataManager::loadPayments() {
    std::vector<Payment> payments;
    std::ifstream file(paymentsFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << paymentsFilePath << std::endl;
        return payments;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isBlankLine(line)) {
            continue;
        }

        std::vector<std::string> tokens = splitCsvLine(line);
        if (isHeaderRow(tokens) || tokens.size() < 6) {
            continue;
        }

        try {
            Payment payment(std::stoi(tokens[0]), std::stoi(tokens[1]),std::stod(tokens[2]),tokens[3],tokens[5]);

            payment.setStatus(tokens[4]);
            payments.push_back(payment);
        } catch (const std::exception& error) {
            std::cerr << "Skipping invalid payment row: " << error.what() << std::endl;
        }
    }

    return payments;
}

std::vector<Maintenance> DataManager::loadMaintenanceRecords() {
    std::vector<Maintenance> maintenanceRecords;
    std::ifstream file(maintenanceFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << maintenanceFilePath << std::endl;
        return maintenanceRecords;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (isBlankLine(line)) {
            continue;
        }

        std::vector<std::string> tokens = splitCsvLine(line);
        if (isHeaderRow(tokens) || tokens.size() < 6) {
            continue;
        }

        try {
            Maintenance maintenance(std::stoi(tokens[0]), std::stoi(tokens[1]),tokens[2],tokens[4]);

            maintenance.setCompletedDate(tokens[3]);
            maintenance.setStatus(tokens[5]);

            if (tokens.size() > 6) {
                for (const std::string& part : splitList(tokens[6])) {
                    maintenance.addPartReplaced(part);
                }
            }

            if (tokens.size() > 7) {
                for (const std::string& issue : splitList(tokens[7])) {
                    maintenance.addIssueFound(issue);
                }
            }

            maintenanceRecords.push_back(maintenance);
        } catch (const std::exception& error) {
            std::cerr << "Skipping invalid maintenance row: " << error.what() << std::endl;
        }
    }

    return maintenanceRecords;
}

void DataManager::saveUsers(const std::vector<std::shared_ptr<User>>& users) {
    std::ofstream file(usersFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << usersFilePath << std::endl;
        return;
    }

    file << "userId,name,email,password,phoneNumber,role\n";
    for (const std::shared_ptr<User>& user : users) {
        file << user->getUserId() << ','
             << user->getName() << ','
             << user->getEmail() << ','
             << user->getPassword() << ','
             << user->getPhoneNumber() << ','
             << user->getRole() << '\n';
    }
}

void DataManager::saveFlights(const std::vector<Flight>& flights) {
    std::ofstream file(flightsFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << flightsFilePath << std::endl;
        return;
    }

    file << "flightId,flightNumber,origin,destination,departureTime,arrivalTime,aircraftId,status,price,crewIds\n";
    for (const Flight& flight : flights) {
        file << flight.getFlightId() << ','
             << flight.getFlightNumber() << ','
             << flight.getOrigin() << ','
             << flight.getDestination() << ','
             << flight.getDepartureTime() << ','
             << flight.getArrivalTime() << ','
             << flight.getAircraftId() << ','
             << flight.getStatus() << ','
             << flight.getPrice() << ','
             << joinInts(flight.getCrewIds()) << '\n';
    }
}

void DataManager::saveAircraft(const std::vector<Aircraft>& aircraftList) {
    std::ofstream file(aircraftFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << aircraftFilePath << std::endl;
        return;
    }

    file << "aircraftId,model,manufacturer,capacity,economySeats,businessSeats,firstClassSeats,maxRangeKm,status,maintenanceIds\n";
    for (const Aircraft& aircraft : aircraftList) {
        file << aircraft.getAircraftId() << ','
             << aircraft.getModel() << ','
             << aircraft.getManufacturer() << ','
             << aircraft.getCapacity() << ','
             << aircraft.getEconomySeats() << ','
             << aircraft.getBusinessSeats() << ','
             << aircraft.getFirstClassSeats() << ','
             << aircraft.getMaxRangeKm() << ','
             << aircraft.getStatus() << ','
             << joinInts(aircraft.getMaintenanceIds()) << '\n';
    }
}

void DataManager::saveReservations(const std::vector<Reservation>& reservations) {
    std::ofstream file(reservationsFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << reservationsFilePath << std::endl;
        return;
    }

    file << "reservationId,passengerId,flightId,seatNumber,seatClass,status,paymentId,bookingDate\n";
    for (const Reservation& reservation : reservations) {
        file << reservation.getReservationId() << ','
             << reservation.getPassengerId() << ','
             << reservation.getFlightId() << ','
             << reservation.getSeatNumber() << ','
             << reservation.getSeatClass() << ','
             << reservation.getStatus() << ','
             << reservation.getPaymentId() << ','
             << reservation.getBookingDate() << '\n';
    }
}

void DataManager::savePayments(const std::vector<Payment>& payments) {
    std::ofstream file(paymentsFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << paymentsFilePath << std::endl;
        return;
    }

    file << "paymentId,reservationId,amount,paymentMethod,status,transactionDate\n";
    for (const Payment& payment : payments) {
        file << payment.getPaymentId() << ','
             << payment.getReservationId() << ','
             << payment.getAmount() << ','
             << payment.getPaymentMethod() << ','
             << payment.getStatus() << ','
             << payment.getTransactionDate() << '\n';
    }
}

void DataManager::saveMaintenanceRecords(const std::vector<Maintenance>& maintenanceRecords) {
    std::ofstream file(maintenanceFilePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << maintenanceFilePath << std::endl;
        return;
    }

    file << "maintenanceId,aircraftId,scheduledDate,completedDate,description,status,partsReplaced,issuesFound\n";
    for (const Maintenance& maintenance : maintenanceRecords) {
        file << maintenance.getMaintenanceId() << ','
             << maintenance.getAircraftId() << ','
             << maintenance.getScheduledDate() << ','
             << maintenance.getCompletedDate() << ','
             << maintenance.getDescription() << ','
             << maintenance.getStatus() << ','
             << joinStrings(maintenance.getPartsReplaced()) << ','
             << joinStrings(maintenance.getIssuesFound()) << '\n';
    }
}

bool DataManager::fileExists(const std::string& filePath) const {
    std::ifstream file(filePath);
    return file.good();
}

void DataManager::createFileIfNotExists(const std::string& filePath) const {
    if (fileExists(filePath)) {
        return;
    }

    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error creating file: " << filePath << std::endl;
    }
}

void DataManager::createBackup(const std::string& filePath) const {
    std::ifstream source(filePath);

    if (!source.is_open()) {
        std::cerr << "Error opening file for backup: " << filePath << std::endl;
        return;
    }

    std::ofstream backup(filePath + ".bak");
    if (!backup.is_open()) {
        std::cerr << "Error creating backup file: " << filePath << ".bak" << std::endl;
        return;
    }

    backup << source.rdbuf();
}
