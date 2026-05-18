#pragma once

#include "User.hpp"

class Administrator : public User {
public:
    Administrator();

    Administrator(int userId,
                  const std::string& username,
                  const std::string& passwordHash,
                  const std::string& fullName,
                  const std::string& email,
                  const std::string& phoneNumber);

    void showMenu() override;

    void createUser();
    void updateUser();
    void deleteUser();
    void viewAllUsers() const;

    void addFlight();
    void updateFlight();
    void removeFlight();
    void viewAllFlights() const;

    void addAircraft();
    void updateAircraft();
    void removeAircraft();
    void viewAllAircraft() const;

    void assignCrewToFlight();

    void generateOperationalReport() const;
    void generateFinancialReport() const;
    void generateUserActivityReport() const;
};