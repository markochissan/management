#pragma once
#include "LibraryItem.h"
#include <iostream>
#include <string>
#include <ctime>

class Book : public LibraryItem {
    std::string title;
    std::string author;

public:
    Book(int id, const std::string& title, const std::string& author)
        : LibraryItem(id, true), title(title), author(author) {
    }
    std::string getTitle() const override {
        return title;
    }

    void borrowItem() override {
        if (available) {
            available = false;
            std::time_t now = std::time(nullptr);
            setDueToDate(now + 4 * 7 * 24 * 60 * 60); // 4 weeks
            std::cout << "Book borrowed successfully! Due date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Book is currently unavailable!" << std::endl;
        }
    }

    void displayDetails() const override {
        std::cout << "Book Details:\n"
            << "ID: " << getId() << "\n"
            << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Available: " << (isAvailable() ? "Yes" : "No") << "\n"
            << "Due Date: " << getDueDate() << "\n";
    }
};
