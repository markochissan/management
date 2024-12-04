#include "Library.h"

const std::string Library::ADMIN_USERNAME = "admin";
const std::string Library::ADMIN_PASSWORD = "<Admin2024"; 

bool Library::login() {
    std::string username, password;
    std::cout << "Library Management System Login\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

 
    auto it = userDatabase.find(username);
    if (it != userDatabase.end() && it->second == password) {
        std::cout << "Login successful. Welcome, " << username << "!\n";
        return true;
    }
    std::cout << "Invalid username or password.\n";
    return false;
}

void Library::adminMenu() {
    int choice;
    while (true) {
        std::cout << "\nAdmin Menu:";
        std::cout << "\n1. Add Item (Book/Magazine)";
        std::cout << "\n2. Remove Item";
        std::cout << "\n3. Display All Items";
        std::cout << "\n4. Search Item";
        std::cout << "\n6. Exit Admin Menu";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            deleteItem();
            break;
        case 3:
            addItem();
            break;
        case 4:
            search();
            break;
        case 5:
            displayAll();
        case6:
            std::cout << "Exiting admin menu.\n";
            break;
     
            
            return;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

void Library::addMember() {
    int id;
    std::string name, email, username, password;

    std::cout << "\nADD MEMBER\n";
    std::cout << "Enter Member ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Member Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Member Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter Username for the Member: ";
    std::getline(std::cin, username);
    std::cout << "Enter Password for the Member: ";
    std::getline(std::cin, password);
    members.push_back(Member(id, name, email));
    userDatabase[username] = password;

    std::cout << "\nMember and login details added successfully!\n";
}

void Library::viewMembers() {
    std::cout << "\nVIEW MEMBERS\n";
    if (members.empty()) {
        std::cout << "No members found.\n";
        return;
    }

    for (const auto& member : members) {
        member.displayDetails();
        std::cout << "--------------------------\n";
    }
}

void Library::addItem() {
    
    int choice;
    std::cout << "Add Book or Magazine?\n";
    std::cout << "1. Book\n2. Magazine\n";
    std::cout << "Enter your choice:";
    std::cin >> choice;

    if (choice == 1) {
        int id;
        std::string title, author;
        std::cout << "Enter Book ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Enter Book Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Book Author: ";
        std::getline(std::cin, author);
         
            libraryItems.push_back(new Book(id, title, author));
            std::cout << "Book added successfully!\n";
    }
    else if (choice == 2) {
        int id,year;

        std::string title;
        std::cout << "Enter Magazine ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Enter Magazine Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Magazine Year : ";
        std::cin >> year;
       

        libraryItems.push_back(new Magazine(id, title, year));
        std::cout << "Magazine added successfully!\n";
    }
    }


void Library::deleteItem() {
    int id;
    std::cout << "Enter the ID of the item to delete: ";
    std::cin >> id;

    for (auto it = libraryItems.begin(); it != libraryItems.end(); ++it) {
        if ((*it)->getId() == id) {
            std::cout << "Deleting item with ID: " << id << "\n";
            delete* it;  // Delete the dynamically allocated object
            libraryItems.erase(it);
            std::cout << "Item deleted successfully\n";
            return;
        }
    }
    std::cout << "Item with ID " << id << " not found.\n";
}


void Library::search() {
    std::string title;
    std::cout << "Enter title of the item of search: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    bool found = false;
    
    for (const auto& item : libraryItems) {
        if (item->getTitle() == title) {
            std::cout << "Item found:\n";
            item->displayDetails();
            std::cout << "-----------------------\n";
            found = true;

        }
    }
    if (!found) {
        std::cout << "No item with the title \n" << title << "";
    }
}
