#include "include/Aircraft.hpp"
#include <iostream>
#include <string>
#include <vector>

int Aircraft::getAircraftId() const {
    return aircraftId;
}
std::string Aircraft::getModel() const {
    return model;
}
std::string Aircraft::getManufacturer() const {
    return manufacturer;
}
int Aircraft::getCapacity() const {
    return capacity;
}
int Aircraft::getEconomySeats() const {
    return economySeats;
}
int Aircraft::getBusinessSeats() const {
    return businessSeats;
}
int Aircraft::getFirstClassSeats() const {
    return firstClassSeats;
}
double Aircraft::getMaxRangeKm() const {
    return maxRangeKm;
}
std::string Aircraft::getStatus() const {
    return status;
}
std::vector<int> Aircraft::getMaintenanceIds() const {
    return maintenanceIds;
}

void Aircraft::setModel(const std::string& model) {
    this->model = model;
}
void Aircraft::setManufacturer(const std::string& manufacturer) {
    this->manufacturer = manufacturer;
}
void Aircraft::setCapacity(int capacity) {
    this->capacity = capacity;
}
void Aircraft::setEconomySeats(int seats) {
    this->economySeats = seats;
}
void Aircraft::setBusinessSeats(int seats) {
    this->businessSeats = seats;
}
void Aircraft::setFirstClassSeats(int seats) {
    this->firstClassSeats = seats;
}
void Aircraft::setMaxRangeKm(double range) {
    this->maxRangeKm = range;
}
void Aircraft::setStatus(const std::string& status) {
    this->status = status;
}

bool Aircraft::isAvailable() const {
    return status == "Available";
}
void Aircraft::markAvailable() {
    status = "Available";
}
void Aircraft::markInFlight() {
    status = "In Flight";
}
void Aircraft::markUnderMaintenance() {
    status = "Under Maintenance";
}

void Aircraft::addMaintenanceId(int maintenanceId) {
    maintenanceIds.push_back(maintenanceId);
}

void Aircraft::displayInfo() const {
    std::cout << "Aircraft ID: " << aircraftId << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Economy Seats: " << economySeats << std::endl;
    std::cout << "Business Seats: " << businessSeats << std::endl;
    std::cout << "First Class Seats: " << firstClassSeats << std::endl;
    std::cout << "Max Range (km): " << maxRangeKm << std::endl;
    std::cout << "Status: " << status << std::endl;
    if (!maintenanceIds.empty()) {
        std::cout << "Maintenance IDs: ";
        for (int id : maintenanceIds) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }
}