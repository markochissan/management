#ifndef LIBRARY_H
#define LIBRARY_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Book.h"
#include "Users.h" 

class Library {
public:
    static const std::string ADMIN_USERNAME;
    static const std::string ADMIN_PASSWORD;

    bool login(); 
    void adminMenu(); 
    void addMember(); 
    void viewMembers(); 
    void addItem(); 
    void deleteItem(); 
    void search();
    void displayAll();


    

private:
    std::unordered_map<std::string, std::string> userDatabase; 
    std::vector<Member> members; 
    std::vector<LibraryItem*> libraryItems;
};

#endif
