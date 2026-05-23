#pragma once

#include <string>
#include <vector>

class Maintenance {
private:
    int maintenanceId;
    int aircraftId;
    std::string scheduledDate;
    std::string completedDate;
    std::string description;
    std::vector<std::string> partsReplaced;
    std::vector<std::string> issuesFound;
    std::string status;

public:
    Maintenance();

    Maintenance(int maintenanceId,
                int aircraftId,
                const std::string& scheduledDate,
                const std::string& description);

    int getMaintenanceId() const;
    int getAircraftId() const;
    std::string getScheduledDate() const;
    std::string getCompletedDate() const;
    std::string getDescription() const;
    std::vector<std::string> getPartsReplaced() const;
    std::vector<std::string> getIssuesFound() const;
    std::string getStatus() const;

    void setScheduledDate(const std::string& scheduledDate);
    void setCompletedDate(const std::string& completedDate);
    void setDescription(const std::string& description);
    void setStatus(const std::string& status);

    void addPartReplaced(const std::string& part);
    void addIssueFound(const std::string& issue);

    void completeMaintenance(const std::string& completedDate);
    void cancelMaintenance();

    bool isCompleted() const;
    bool isScheduled() const;

    void displayInfo() const;
};