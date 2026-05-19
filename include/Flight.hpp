#pragma once

#include <string>
#include <vector>
#include <map>

class Flight {
private:
    int flightId;
    std::string flightNumber;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    int aircraftId;
    std::string status;
    double price;

    std::vector<int> crewIds;
    std::map<std::string, bool> seatAvailability;

public:
    Flight();

    Flight(int flightId,
           const std::string& flightNumber,
           const std::string& origin,
           const std::string& destination,
           const std::string& departureTime,
           const std::string& arrivalTime,
           int aircraftId,
           double price);

    int getFlightId() const;
    std::string getFlightNumber() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    int getAircraftId() const;
    std::string getStatus() const;
    double getPrice() const;
    std::vector<int> getCrewIds() const;

    void setFlightNumber(const std::string& flightNumber);
    void setOrigin(const std::string& origin);
    void setDestination(const std::string& destination);
    void setDepartureTime(const std::string& departureTime);
    void setArrivalTime(const std::string& arrivalTime);
    void setAircraftId(int aircraftId);
    void setStatus(const std::string& status);
    void setPrice(double price);

    void assignCrewMember(int crewId);
    void removeCrewMember(int crewId);

    void initializeSeatMap(int economySeats, int businessSeats, int firstClassSeats);
    bool isSeatAvailable(const std::string& seatNumber) const;
    bool reserveSeat(const std::string& seatNumber);
    bool releaseSeat(const std::string& seatNumber);

    std::vector<std::string> getAvailableSeats() const;
    void displaySeatMap() const;

    bool matchesSearch(const std::string& origin,
                       const std::string& destination,
                       const std::string& date) const;

    void displayInfo() const;
};