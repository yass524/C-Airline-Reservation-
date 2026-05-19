#include <string>
#include <iostream>
#include "include/User.hpp"


int User::getUserId() const {
    return userId;
}
std::string User::getName() const {
    return name;
}
std::string User::getEmail() const {
    return email;
}
std::string User::getPassword() const {
    return password;
}
std::string User::getPhoneNumber() const {
    return phoneNumber;
}
std::string User::getRole() const {
    return role;
}

void User::setUserId(int userId) {
    this->userId = userId;
}
void User::setName(const std::string& name) {
    this->name = name;
}
void User::setEmail(const std::string& email) {
    this->email = email;
}
void User::setPassword(const std::string& password) {
    this->password = password;
}
void User::setPhoneNumber(const int& phoneNumber) {
    this->phoneNumber = phoneNumber;
}
/*void User::setRole(const std::string& role) {
    this->role = role;
}*/

bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}
void User::displayInfo() const{
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Role: " << role << std::endl;
}

void User::showMenu() {}