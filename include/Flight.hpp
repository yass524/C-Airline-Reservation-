#pragma once

#include "Aircraft.hpp"
#include <string>
#include <vector>


class Aircraft {
private:
    int aircraftId;
    std::string model;
    std::string manufacturer;
    int capacity;
    int economySeats;
    int businessSeats;
    int firstClassSeats;
    double maxRangeKm;
    std::string status;
    std::vector<int> maintenanceIds;

public:
    Aircraft aircraft();

    Aircraft(int aircraftId,
             const std::string& model,
             const std::string& manufacturer,
             int capacity,
             int economySeats,
             int businessSeats,
             int firstClassSeats,
             double maxRangeKm);

    int getAircraftId() const;
    std::string getModel() const;
    std::string getManufacturer() const;
    int getCapacity() const;
    int getEconomySeats() const;
    int getBusinessSeats() const;
    int getFirstClassSeats() const;
    double getMaxRangeKm() const;
    std::string getStatus() const;
    std::vector<int> getMaintenanceIds() const;

    void setModel(const std::string& model);
    void setManufacturer(const std::string& manufacturer);
    void setCapacity(int capacity);
    void setEconomySeats(int seats);
    void setBusinessSeats(int seats);
    void setFirstClassSeats(int seats);
    void setMaxRangeKm(double range);
    void setStatus(const std::string& status);

    bool isAvailable() const;
    void markAvailable();
    void markInFlight();
    void markUnderMaintenance();

    void addMaintenanceId(int maintenanceId);

    void displayInfo() const;
};