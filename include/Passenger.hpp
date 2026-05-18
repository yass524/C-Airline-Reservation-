#pragma once
#include "User.hpp"
#include <vector>
#include <string>

class Passenger : public User {
private:
    std::string passportNumber;
    std::string nationality;
    int loyaltyPoints;
    std::vector<int> reservationIds; // List of reservation IDs associated with the passenger
    std::vector<std::string> travelHistory;
    std::string mealPreference;

    public:
    Passenger();

    Passenger(int userId,
              const std::string& username,
              const std::string& passwordHash,
              const std::string& fullName,
              const std::string& email,
              const std::string& phoneNumber,
              const std::string& passportNumber,
              const std::string& nationality);

    void showMenu() override;
    std::string getPassportNumber() const;
    std::string getNationality() const;
    int getLoyaltyPoints() const;
    std::vector<int> getReservationIds() const;
    std::vector<std::string> getTravelHistory() const;
    std::string getSeatPreference() const;
    std::string getMealPreference() const;

    void setPassportNumber(const std::string& passportNumber);
    void setNationality(const std::string& nationality);
    void setSeatPreference(const std::string& seatPreference);
    void setMealPreference(const std::string& mealPreference);
    void addReservationId(int reservationId);
    void removeReservationId(int reservationId);
    void addTravelHistory(const std::string& flightInfo);
    void addLoyaltyPoints(int points);
    bool redeemLoyaltyPoints(int points);
    void searchFlights() const;
    void makeBooking();
    void cancelBooking();
    void checkInOnline();
    void viewBookings() const;
    void viewProfile() const;
    void updateProfile();
    void displayInfo() const override;

};


