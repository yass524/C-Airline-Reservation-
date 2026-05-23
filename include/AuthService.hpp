#pragma once

#include <string>
#include <vector>
#include <memory>
#include "User.hpp"

class AuthService {
private:
    std::vector<std::shared_ptr<User>> users;
    std::shared_ptr<User> currentUser;
    //inshallah el currentUser hayeb2a refrence counter le users
    //3ashan yakhod nafs el info we nestakhdemo fe functions el ba3d el login
public:
    AuthService();

    bool registerUser(std::shared_ptr<User> user);
    std::shared_ptr<User> login(const std::string& username,
                                const std::string& password);

    void logout();

    bool isLoggedIn() const;
    std::shared_ptr<User> getCurrentUser() const;

    bool usernameExists(const std::string& username) const;
    std::shared_ptr<User> findUserById(int userId) const;
    std::shared_ptr<User> findUserByUsername(const std::string& username) const;

    void addUser(std::shared_ptr<User> user);
    bool removeUser(int userId);

    std::vector<std::shared_ptr<User>> getAllUsers() const;

private:
    std::string hashPassword(const std::string& password) const;
};