#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Magazine.h"

int main() {
    Library library;

    //login
    if (!library.login()) {
        std::cout << "Login failed. Exiting program.\n";
        return 0;
    }
    library.adminMenu();

    return 0;
}
