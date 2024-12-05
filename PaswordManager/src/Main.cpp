#include <iostream>
#include "AccountManager.cpp"
#include "AdminUser.cpp"
#include "RegularUser.cpp"
#include "PersonalAccount.cpp"
#include "BusinessAccount.cpp"

using namespace std;

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Password\n";
    cout << "2. View Password\n";
    cout << "3. Edit Password\n";
    cout << "4. Delete Password\n";
    cout << "5. Search Password\n";
    cout << "6. Sort Passwords\n";
    cout << "7. Save Accounts to File\n";
    cout << "8. Load Accounts to File\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

void addPassword(AccountManager& manager) {
    string accountType, accountName, username, password;

    cout << "Enter account type (personal/business): ";
    cin >> accountType;
    cout << "Enter account name: ";
    cin.ignore();
    getline(cin, accountName);
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (accountType == "personal") {
        PersonalAccount* newAccount = new PersonalAccount(accountName, username, password);
        manager.addAccount(newAccount);
        cout << "Personal account added.\n";
    } else if (accountType == "business") {
        BusinessAccount* newAccount = new BusinessAccount(accountName, username, password);
        manager.addAccount(newAccount);
        cout << "Business account added.\n";
    } else {
        cout << "Invalid account type.\n";
    }
}

void viewPassword(AccountManager& manager, User* loggedInUser) {
    manager.viewAccounts(loggedInUser);
}

void editPassword(AccountManager& manager) {
    string username, newPassword;
    cout << "Enter username to update password: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> newPassword;
    manager.updatePassword(username, newPassword);
}

void deletePassword(AccountManager& manager) {
    string username;
    cout << "Enter username to delete password: ";
    cin >> username;
    manager.deletePassword(username);
}

void searchPassword(AccountManager& manager) {
    string username;
    cout << "Enter username to search for password: ";
    cin >> username;
    manager.searchPassword(username);
}

void sortPasswords(AccountManager& manager) {
    manager.sortAccounts();
}

void saveAccountsToFile(AccountManager& manager) {
    string filename;
    cout << "Enter filename to save accounts: ";
    cin >> filename;
    manager.saveAccountsToFile(filename);
}

void loadAccountsFromFile(AccountManager& manager) {
    string filename;
    cout << "Enter filename to load accounts: ";
    cin >> filename;
    manager.loadAccountsFromFile(filename);
}

int main() {
    AccountManager manager;

    AdminUser* admin = new AdminUser("admin", "admin123");
    RegularUser* regular = new RegularUser("user", "user123");

    manager.addUser(admin);
    manager.addUser(regular);

    string username, password;
    cout << "\nAdmin username: admin\n" << "Password: admin123\n\n";
    cout << "Regular username: user\n" << "Password: user123\n\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    User* loggedInUser = manager.login(username, password);

    if (!loggedInUser) {
        cout << "Invalid credentials. Exiting program.\n";
        return 0;
    }

    cout << "\nWelcome " << (loggedInUser->getIsAdmin() ? "Admin" : "Regular User") << endl;

    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addPassword(manager); break;
            case 2: viewPassword(manager, loggedInUser); break;
            case 3: editPassword(manager); break;
            case 4: deletePassword(manager); break;
            case 5: searchPassword(manager); break;
            case 6: sortPasswords(manager); break;
            case 7: saveAccountsToFile(manager); break;
            case 8: loadAccountsFromFile(manager); break;
            case 9: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
