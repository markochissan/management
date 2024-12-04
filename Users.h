#pragma once
#include <string>
#include <vector>
#include <iostream>

class Member {
private:
    int memberId;
    std::string name;
    std::string email;
    std::vector<int> borrowedItems;   // List of IDs 

public:
    // Const
    Member(int id, const std::string& name, const std::string& email)
        : memberId(id), name(name), email(email) {
    }

    // Get
    int getMemberId() const { return memberId; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }

    void borrowItem(int itemId) {
        borrowedItems.push_back(itemId);
        std::cout << "Item ID " << itemId << " borrowed successfully by " << name << ".\n";
    }

    void returnItem(int itemId) {
        auto it = std::find(borrowedItems.begin(), borrowedItems.end(), itemId);
        if (it != borrowedItems.end()) {
            borrowedItems.erase(it);
            std::cout << "Item ID " << itemId << " returned successfully by " << name << ".\n";
        }
        else {
            std::cout << "Item ID " << itemId << " not found in borrowed list for " << name << ".\n";
        }
    }
    void viewBorrowedItems() const {
        std::cout << "Borrowed Items for " << name << ":\n";
        if (borrowedItems.empty()) {
            std::cout << "No items currently borrowed.\n";
        }
        else {
            for (int id : borrowedItems) {
                std::cout << "- Item ID: " << id << "\n";
            }
        }
    }

    // Display Member Details
    void displayDetails() const {
        std::cout << "Member ID: " << memberId
            << "\nName: " << name
            << "\nEmail: " << email
            << "\nNumber of Borrowed Items: " << borrowedItems.size() << "\n";
    }
};
