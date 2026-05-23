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
#include "AuthService.hpp"
#include "DataManager.hpp"

class BookingSystem {
private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<Flight> flights;
    std::vector<Aircraft> aircraftList;
    std::vector<Reservation> reservations;
    std::vector<Payment> payments;
    std::vector<Maintenance> maintenanceRecords;

    AuthService authService;
    DataManager dataManager;

    int nextUserId;
    int nextFlightId;
    int nextAircraftId;
    int nextReservationId;
    int nextPaymentId;
    int nextMaintenanceId;

public:
    BookingSystem();

    void run();

    void loadData();
    void saveData();

    void showMainMenu();
    void showLoginMenu();

    void handleAdministratorMenu();
    void handleBookingAgentMenu();
    void handlePassengerMenu();

    // User operations
    void addUser(std::shared_ptr<User> user);
    bool deleteUser(int userId);
    std::shared_ptr<User> findUserById(int userId) const;
    void listUsers() const;

    // Flight operations
    void addFlight(const Flight& flight);
    bool updateFlight(int flightId);
    bool removeFlight(int flightId);
    Flight* findFlightById(int flightId);
    std::vector<Flight> searchFlights(const std::string& origin,
                                      const std::string& destination,
                                      const std::string& date) const;
    void listFlights() const;

    // Aircraft operations
    void addAircraft(const Aircraft& aircraft);
    bool updateAircraft(int aircraftId);
    bool removeAircraft(int aircraftId);
    Aircraft* findAircraftById(int aircraftId);
    void listAircraft() const;

    // Reservation operations
    bool createReservation(int passengerId,
                           int flightId,
                           const std::string& seatNumber,
                           const std::string& seatClass);

    bool cancelReservation(int reservationId);
    bool modifyReservation(int reservationId,
                           const std::string& newSeatNumber);

    Reservation* findReservationById(int reservationId);
    std::vector<Reservation> getReservationsByPassenger(int passengerId) const;

    // Payment operations
    bool createPayment(int reservationId,
                       double amount,
                       const std::string& paymentMethod);

    bool refundPayment(int paymentId);
    Payment* findPaymentById(int paymentId);

    // Check-in operations
    bool checkInPassenger(int reservationId);
    void generateBoardingPass(int reservationId) const;

    // Maintenance operations
    void scheduleMaintenance(const Maintenance& maintenance);
    bool completeMaintenance(int maintenanceId,
                             const std::string& completedDate);
    Maintenance* findMaintenanceById(int maintenanceId);
    void listMaintenanceRecords() const;

    // Reports
    void generateFlightReport() const;
    void generateReservationReport() const;
    void generateFinancialReport() const;
    void generateMaintenanceReport() const;

    int createFlightId();
    int createAircraftId();
    int createMaintenanceId();

private:
    int generateUserId();
    int generateFlightId();
    int generateAircraftId();
    int generateReservationId();
    int generatePaymentId();
    int generateMaintenanceId();
};