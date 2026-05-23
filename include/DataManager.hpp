#pragma once

#include <vector>
#include <memory>
#include <string>

#include "User.hpp"
#include "Flight.hpp"
#include "Aircraft.hpp"
#include "Reservation.hpp"
#include "Payment.hpp"
#include "Maintenance.hpp"

class DataManager {
private:
    std::string usersFilePath;
    std::string flightsFilePath;
    std::string aircraftFilePath;
    std::string reservationsFilePath;
    std::string paymentsFilePath;
    std::string maintenanceFilePath;

public:
    DataManager();

    DataManager(const std::string& usersFilePath,
                const std::string& flightsFilePath,
                const std::string& aircraftFilePath,
                const std::string& reservationsFilePath,
                const std::string& paymentsFilePath,
                const std::string& maintenanceFilePath);

    void setUsersFilePath(const std::string& path);
    void setFlightsFilePath(const std::string& path);
    void setAircraftFilePath(const std::string& path);
    void setReservationsFilePath(const std::string& path);
    void setPaymentsFilePath(const std::string& path);
    void setMaintenanceFilePath(const std::string& path);

    std::vector<std::shared_ptr<User>> loadUsers();
    std::vector<Flight> loadFlights();
    std::vector<Aircraft> loadAircraft();
    std::vector<Reservation> loadReservations();
    std::vector<Payment> loadPayments();
    std::vector<Maintenance> loadMaintenanceRecords();

    void saveUsers(const std::vector<std::shared_ptr<User>>& users);
    void saveFlights(const std::vector<Flight>& flights);
    void saveAircraft(const std::vector<Aircraft>& aircraft);
    void saveReservations(const std::vector<Reservation>& reservations);
    void savePayments(const std::vector<Payment>& payments);
    void saveMaintenanceRecords(const std::vector<Maintenance>& maintenanceRecords);

    bool fileExists(const std::string& filePath) const;
    void createFileIfNotExists(const std::string& filePath) const;
    void createBackup(const std::string& filePath) const;
};