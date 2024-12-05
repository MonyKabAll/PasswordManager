#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountName;
    string username;
    string password;
public:
    Account(string accountName, string username, string password)
        : accountName(accountName), username(username), password(password) {}

    virtual void displayAccount() const = 0;
    virtual void updateAccount(string newUsername, string newPassword) = 0;

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getAccountName() const { return accountName; }
    void setPassword(const string& newPassword) { password = newPassword; }
};
