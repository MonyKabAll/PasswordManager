#pragma once
#include <iostream>
#include "Account.cpp"

class BusinessAccount : public Account {
public:
    BusinessAccount(string accountName, string username, string password)
        : Account(accountName, username, password) {}

    void displayAccount() const override {
        cout << "Business Account - " << accountName
             << "\nUsername: " << username
             << "\nPassword: " << password << endl;
    }

    void updateAccount(string newUsername, string newPassword) override {
        username = newUsername;
        password = newPassword;
    }
};
