#pragma once
#include <iostream>
#include "User.cpp"

class RegularUser : public User {
public:
    RegularUser(string username, string password) : User(username, password) {}

    bool getIsAdmin() const override {
        return false;
    }
};
