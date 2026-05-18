#pragma once

#include "User.hpp"

class BookingAgent : public User {
public:
    BookingAgent();

    BookingAgent(int userId,
                 const std::string& username,
                 const std::string& passwordHash,
                 const std::string& fullName,
                 const std::string& email,
                 const std::string& phoneNumber);

    void showMenu() override;

    void searchFlights() const;
    void createReservation();
    void modifyReservation();
    void cancelReservation();

    void processPayment();
    void processRefund();

    void airportCheckIn();
    void generateBoardingPass();

    void viewPassengerProfile() const;
    void updatePassengerProfile();
};