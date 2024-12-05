#pragma once
#include <iostream>
#include "Account.cpp"

class PersonalAccount : public Account {
public:
    PersonalAccount(string accountName, string username, string password)
        : Account(accountName, username, password) {}

    void displayAccount() const override {
        cout << "Personal Account - " << accountName
             << "\nUsername: " << username
             << "\nPassword: " << password << endl;
    }

    void updateAccount(string newUsername, string newPassword) override {
        username = newUsername;
        password = newPassword;
    }
};
