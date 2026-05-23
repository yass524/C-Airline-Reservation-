#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "include/AuthService.hpp"

AuthService::AuthService() = default;

bool AuthService::registerUser(std::shared_ptr<User> user) {
    if (usernameExists(user->getEmail())) {
        return false; // Username already exists
    }
    user->setPassword(hashPassword(user->getPassword()));
    users.push_back(user);
    return true;
}

void AuthService::logout() {
    currentUser.reset(); //release owenrship
}

std::shared_ptr<User> AuthService::login(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user->getEmail() == username && user->checkPassword(hashPassword(password))) {
            currentUser = user; //set current user
            return currentUser;
        }
    }
    return nullptr; // Login failed
}

bool AuthService::isLoggedIn() const {
    return currentUser != nullptr;
}
std::shared_ptr<User> AuthService::getCurrentUser() const {
    return currentUser;
}

bool AuthService::usernameExists(const std::string& username) const {
    for (const auto& user : users) {
        if (user->getEmail() == username) {
            return true;
        }
    }
    return false;
}
std::shared_ptr<User> AuthService::findUserById(int userId) const {
    for (const auto& user : users) {
        if (user->getUserId() == userId) {
            return user;
        }
    }
    return nullptr;
}
std::shared_ptr<User> AuthService::findUserByUsername(const std::string& username) const {
    for (const auto& user : users) {
        if (user->getEmail() == username) {
            return user;
        }
    }
    return nullptr;
}

void AuthService::addUser(std::shared_ptr<User> user) {
    users.push_back(user);
}
bool AuthService::removeUser(int userId) {
    auto it = std::remove_if(users.begin(), users.end(), [userId](const std::shared_ptr<User>& user) {
        return user->getUserId() == userId;
    });

    if (it == users.end()) {
        return false;
    }

    users.erase(it, users.end());
    return true;
}
std::vector<std::shared_ptr<User>> AuthService::getAllUsers() const {
    return users;
}

std::string AuthService::hashPassword(const std::string& password) const {

    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}