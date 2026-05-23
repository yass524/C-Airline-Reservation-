#pragma once

#include <string>

class Menu {
public: //hakhali kolo static 3ashan yefdalo fel scope beta3 el class we ne access fel scope bas 
    static void printWelcomeScreen();

    static int showMainMenu();
    static int showLoginMenu();

    static int showAdministratorMenu();
    static int showBookingAgentMenu();
    static int showPassengerMenu();

    static int showFlightManagementMenu();
    static int showAircraftManagementMenu();
    static int showReservationManagementMenu();
    static int showMaintenanceManagementMenu();
    static int showReportsMenu();

    static void printDivider();
    static void printHeader(const std::string& title);

    static int getIntegerInput(const std::string& prompt);
    static double getDoubleInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);

    static std::string inputUserRole();
    static std::string inputSeatClass();
    static std::string inputFlightStatus();

    static void pause();
    static void clearScreen();
};