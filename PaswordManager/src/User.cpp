#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
public:
    User(string username, string password) : username(username), password(password) {}
    virtual bool getIsAdmin() const = 0;
    virtual string getUsername() const { return username; }
    virtual string getPassword() const { return password; }
};
