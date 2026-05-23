#include <string>
#include <vector>
#include "include/Maintenance.hpp"
#include <iostream>


Maintenance::Maintenance()
    : maintenanceId(0),
      aircraftId(0),
      status("Scheduled") {}

Maintenance::Maintenance(int maintenanceId,
                         int aircraftId,
                         const std::string& scheduledDate,
                         const std::string& description)
    : maintenanceId(maintenanceId),
      aircraftId(aircraftId),
      scheduledDate(scheduledDate),
      description(description),
      status("Scheduled") {}

int Maintenance::getMaintenanceId() const {
    return maintenanceId;
}
int Maintenance::getAircraftId() const {
    return aircraftId;
}
std::string Maintenance::getScheduledDate() const { 
    return scheduledDate;
}
std::string Maintenance::getCompletedDate() const {
    return completedDate;
}
std::string Maintenance::getDescription() const {
    return description;
}
std::vector<std::string> Maintenance::getPartsReplaced() const {
    return partsReplaced;   
}
std::vector<std::string> Maintenance::getIssuesFound() const {
    return issuesFound;
}
std::string Maintenance::getStatus() const {
    return status;
}

void Maintenance::setScheduledDate(const std::string& scheduledDate) {
    this->scheduledDate = scheduledDate;
}
void Maintenance::setCompletedDate(const std::string& completedDate) {
    this->completedDate = completedDate;
}
void Maintenance::setDescription(const std::string& description) {
    this->description = description;
}
void Maintenance::setStatus(const std::string& status) {
    this->status = status;
}

void Maintenance::addPartReplaced(const std::string& part) {
    partsReplaced.push_back(part);
}
void Maintenance::addIssueFound(const std::string& issue) {
    issuesFound.push_back(issue);
}
void Maintenance::completeMaintenance(const std::string& completedDate) {
    setCompletedDate(completedDate);
    setStatus("Completed");
}
void Maintenance::cancelMaintenance() {
    setStatus("Cancelled");
}
bool Maintenance::isCompleted() const {
    return status == "Completed";
}
bool Maintenance::isScheduled() const {
    return status == "Scheduled";
}   

void Maintenance::displayInfo() const {
    std::cout << "Maintenance ID: " << maintenanceId << std::endl;
    std::cout << "Aircraft ID: " << aircraftId << std::endl;
    std::cout << "Scheduled Date: " << scheduledDate << std::endl;
    std::cout << "Completed Date: " << completedDate << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Parts Replaced: ";
    for (const auto& part : partsReplaced) {
        std::cout << part << ", ";
    }
    std::cout << std::endl;
    std::cout << "Issues Found: ";
    for (const auto& issue : issuesFound) {
        std::cout << issue << ", ";
    }
    std::cout << std::endl;
    std::cout << "Status: " << status << std::endl;
}