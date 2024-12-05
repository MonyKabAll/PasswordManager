#pragma once
#include <iostream>
#include "User.cpp"

class AdminUser : public User {
public:
    AdminUser(string username, string password) : User(username, password) {}

    bool getIsAdmin() const override {
        return true;
    }
};
