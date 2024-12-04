#pragma once
#include "library.h"

class Magazine : public LibraryItem {
    std::string title;
    int issueNumber;

public:
    Magazine(int id, const std::string& title, int issueNumber)
        : LibraryItem(id, true), title(title), issueNumber(issueNumber) {
    }
    std::string getTitle() const override {
        return title;
    }

    void borrowItem() override {
        if (available) {
            available = false;
            std::time_t now = std::time(nullptr);
            dueToDate = now + static_cast<long long>(2 * 7 * 24 * 60) * 60; // 2 weeks
            std::cout << "Magazine borrowed successfully! Due date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Magazine is currently unavailable!" << std::endl;
        }
    }

    void displayDetails() const  {
        std::cout << "Magazine Details:\n";
        LibraryItem::displayDetails();
        std::cout << "Title: " << title << "\nIssue Number: " << issueNumber << std::endl;
    }
};
