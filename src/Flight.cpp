#include "include/Flight.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>

int Flight::getFlightId() const {
    return flightId;
}
std::string Flight::getFlightNumber() const {
    return flightNumber;
}
std::string Flight::getOrigin() const {
    return origin;
}
std::string Flight::getDestination() const {
    return destination;
}
std::string Flight::getDepartureTime() const {
    return departureTime;
}
std::string Flight::getArrivalTime() const {
    return arrivalTime;
}
int Flight::getAircraftId() const {
    return aircraftId;
}
std::string Flight::getStatus() const {
    return status;
}
double Flight::getPrice() const {
    return price;
}
std::vector<int> Flight::getCrewIds() const {
    return crewIds;
}

void Flight::setFlightNumber(const std::string& flightNumber) {
    this->flightNumber = flightNumber;
}
void Flight::setOrigin(const std::string& origin) {
    this->origin = origin;
}
void Flight::setDestination(const std::string& destination) {
    this->destination = destination;
}
void Flight::setDepartureTime(const std::string& departureTime) {
    this->departureTime = departureTime;
}
void Flight::setArrivalTime(const std::string& arrivalTime) {
    this->arrivalTime = arrivalTime;
}
void Flight::setAircraftId(int aircraftId) {
    this->aircraftId = aircraftId;
}
void Flight::setStatus(const std::string& status) {
    this->status = status;
}
void Flight::setPrice(double price) {
    this->price = price;
}

void Flight::assignCrewMember(int crewId) {
    crewIds.push_back(crewId);
}
void Flight::removeCrewMember(int crewId) {
    crewIds.erase(std::remove(crewIds.begin(), crewIds.end(), crewId), crewIds.end());
}


void Flight::initializeSeatMap(int economySeats, int businessSeats, int firstClassSeats) {
    for (int i = 1; i <= economySeats; ++i) {
        seatAvailability["E" + std::to_string(i)] = true;  //std::to_string is used to converts el i to string ma3 el E
    }
    for (int i = 1; i <= businessSeats; ++i) {
        seatAvailability["B" + std::to_string(i)] = true; 
    }
    for (int i = 1; i <= firstClassSeats; ++i) {
        seatAvailability["F" + std::to_string(i)] = true; 
    }
}
bool Flight::isSeatAvailable(const std::string& seatNumber) const {
    auto it = seatAvailability.find(seatNumber);
    if (it != seatAvailability.end()) {
        return it->second;
    }
    return false; 
}
bool Flight::reserveSeat(const std::string& seatNumber) {
    auto it = seatAvailability.find(seatNumber);
    if (it != seatAvailability.end() && it->second) {  
        it->second = false; //han reserve el seat fa false
        return true;
    }
    return false; 
}
bool Flight::releaseSeat(const std::string& seatNumber) {
    auto it = seatAvailability.find(seatNumber);
    if (it != seatAvailability.end() && !it->second) {
        it->second = true; 
        return true;
    }
    return false; 
}

std::vector<std::string> Flight::getAvailableSeats() const {
    std::vector<std::string> availableSeats;
    for (const auto& seat : seatAvailability) {
        if (seat.second) { 
            availableSeats.push_back(seat.first);
        }
    }
    return availableSeats;
}

void Flight::displaySeatMap() const{
    std::cout << "Seat Map for Flight " << flightNumber << ":" << std::endl;
    for (const auto& seat : seatAvailability) {
        std::cout << "Seat " << seat.first << ": " << (seat.second ? "Available" : "Reserved") << std::endl;
    }
}

bool Flight::matchesSearch(const std::string& origin, const std::string& destination, const std::string& date) const {
    return this->origin == origin && this->destination == destination && this->departureTime.substr(0, 10) == date;  //substr() "YYYY-MM-DD HH:MM:SS"
}

void Flight::displayInfo() const {
    std::cout << "Flight ID: " << flightId << std::endl;
    std::cout << "Flight Number: " << flightNumber << std::endl;
    std::cout << "Origin: " << origin << std::endl;
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "Departure Time: " << departureTime << std::endl;
    std::cout << "Arrival Time: " << arrivalTime << std::endl;
    std::cout << "Aircraft ID: " << aircraftId << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Price: $" << price << std::endl;
}