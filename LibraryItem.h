#pragma once
#include <iostream>
#include <string>
#include <ctime>

class LibraryItem {
protected:
    int id;
    bool available;
    std::time_t dueToDate;

public:
    LibraryItem(int id, bool available)
        : id(id), available(available), dueToDate(0) {
    }

    virtual ~LibraryItem() {}
    virtual std::string getTitle() const = 0;
    void setDueToDate(std::time_t dueDate) {
        dueToDate = dueDate;
    }

    std::string getDueDate() const {
        if (dueToDate == 0) return "N/A";
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &dueToDate);
        return std::string(buffer);
    }

    virtual void borrowItem() = 0;
    virtual void displayDetails() const = 0;

    void returnItem() {
        available = true;
        dueToDate = 0;
        std::cout << "Item returned successfully!\n";
    }

    int getId() const {
        return id;
    }

    bool isAvailable() const {
        return available;
    }
};
