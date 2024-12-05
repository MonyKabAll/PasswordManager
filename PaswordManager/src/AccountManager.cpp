#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include "Account.cpp"
#include "AdminUser.cpp"
#include "RegularUser.cpp"

using namespace std;

class AccountManager {
private:
    vector<Account*> accounts;
    vector<User*> users;

public:
    void addAccount(Account* account) {
        accounts.push_back(account);
    }

    void addUser(User* user) {
        users.push_back(user);
    }

    User* login(const string& username, const string& password) {
        for (auto& user : users) {
            if (user->getUsername() == username && user->getPassword() == password) {
                return user;
            }
        }
        return nullptr;
    }

    void viewAccounts(User* loggedInUser) const {
        if (loggedInUser->getIsAdmin()) {
            for (const auto& account : accounts) {
                account->displayAccount();
            }
        } else {
            for (const auto& account : accounts) {
                if (account->getUsername() == loggedInUser->getUsername()) {
                    account->displayAccount();
                    return;
                }
            }
            cout << "No accounts found for this user.\n";
        }
    }

    void updatePassword(const string& username, const string& newPassword) {
        for (auto& account : accounts) {
            if (account->getUsername() == username) {
                account->setPassword(newPassword);
                cout << "Password updated.\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void deletePassword(const string& username) {
        auto it = remove_if(accounts.begin(), accounts.end(), [&username](Account* account) {
            return account->getUsername() == username;
        });
        if (it != accounts.end()) {
            delete *it;
            accounts.erase(it);
            cout << "Account deleted.\n";
        } else {
            cout << "Account not found.\n";
        }
    }

    void searchPassword(const string& username) const {
        for (const auto& account : accounts) {
            if (account->getUsername() == username) {
                account->displayAccount();
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void sortAccounts() {
        sort(accounts.begin(), accounts.end(), [](Account* a, Account* b) {
            return a->getUsername() < b->getUsername();
        });
        cout << "Accounts sorted.\n";
    }

    void saveAccountsToFile(const string &filename) const {
        string filePath = "../data/" + filename;
        ofstream file(filePath, ios::binary);
        if (!file) {
            throw runtime_error("Failed to open file for writing.");
        }

        for (const auto &acc : accounts) {
            file.write(reinterpret_cast<const char*>(&acc), sizeof(Account*));
        }
        file.close();
    }

    void loadAccountsFromFile(const string &filename) {
        string filePath = "../data/" + filename;
        ifstream file(filePath, ios::binary);
        if (!file) {
            throw runtime_error("Failed to open file for reading.");
        }

        while (file) {
            Account* acc;
            file.read(reinterpret_cast<char*>(&acc), sizeof(Account*));
            if (file) {
                accounts.push_back(acc);
            }
        }
        file.close();
    }
};
