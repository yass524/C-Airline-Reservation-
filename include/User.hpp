#pragma once 
#include <string>

class User {
protected:
    int userId;
    std::string name;
    std::string email;
    std::string password;
    std::string phoneNumber;
    std::string role;
public:
    User(int userId, const std::string& name, const std::string& email, const std::string& password, const std::string& phoneNumber, const std::string& role)
        : userId(userId), name(name), email(email), password(password), phoneNumber(phoneNumber), role(role) {}

        int getUserId() const;
        std::string getName() const;
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getPhoneNumber() const;
        std::string getRole() const;

        void setUserId(int userId);
        void setName(const std::string& name);
        void setEmail(const std::string& email);
        void setPassword(const std::string& password);
        void setPhoneNumber(const std::string& phoneNumber);
        void setRole(const std::string& role);

        bool checkPassword(const std::string& password) const;
        virtual void displayInfo() const;
        virtual void showMenu() = 0; // Abstract 3ashan ne3raf ne override 
};