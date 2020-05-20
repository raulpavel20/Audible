#pragma once
#include "UI.h"
#include "Controller.h"

#include <iostream>
#include <vector>

UserType LoginScreen() {
    int opt;
    std::cout << "What type of user are you?\n";
    std::cout << "\t1. Administrator\n";
    std::cout << "\t2. Client\n";
    std::cin.clear();
    std::cin >> opt;
    while (opt <= 0 || opt >= 3 || std::cin.fail()) {
        std::cout << "Not a valid option!\n";
        std::cout << "What type of user are you?\n";
        std::cout << "\t1. Administrator\n";
        std::cout << "\t2. Client\n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> opt;
    }
    switch (opt) {
        case 1 :
            return ADMINISTRATOR;
        case 2 :
            return CLIENT;
        default :
            return UNKNOWN;
    }
}

bool deleteBook(Controller *ctrl) {
    std::string title;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cout << "Give the title of the book: \n";
    getline(std::cin, title);
    while (!ctrl->getAll().checkByTitle(title)) {
        std::cout<< "No such book in the database!\n";
        std::cout << "Give the title of the book: \n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        getline(std::cin, title);
    }
    return ctrl->deleteBook(title);
}

bool addBook(Controller *ctrl) {
    std::string title, author, description, genre, cover;
    int year;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cout << "Give the title of the book: \n";
    getline(std::cin, title);
    std::cout << "Give the author of the book: \n";
    getline(std::cin, author);
    std::cout << "Give the description of the book of the book: \n";
    getline(std::cin, description);
    std::cout << "Give the genre of the book: \n";
    getline(std::cin, genre);
    std::cout << "Give the link to the cover of the book: \n";
    getline(std::cin, cover);
    std::cout << "Give the year of publication: \n";
    std::cin >> year;
    while(year < 0 || std::cin.fail()) {
        std::cout << "wrong input!\n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Give the year of publication: \n";
        std::cin >> year;
    }
    if(ctrl->getAll().checkDuplicate(Book(title, author, genre, description, year, cover))) {
        std::cout << "That book is already in the database!\n";
        return false;
    }
    return ctrl->addBook(Book(title, author, genre, description, year, cover));
}

bool updateBook(Controller *databaseCtrl) {
    int okUpdate = 0, year;
    std::string str;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cout << "Give the title of the book: \n";
    getline(std::cin, str);
    while (!databaseCtrl->getAll().checkByTitle(str)) {
        std::cout<< "No such book in the database!\n";
        std::cout << "Give the title of the book: \n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        getline(std::cin, str);
    }
    Book book = *databaseCtrl->findByTitle(str);
    databaseCtrl->deleteBook(str);
    std::cout << "Dou you want to update the title? (1 for yes, 0 for no)\n";
    std::cin >> okUpdate;
    while (okUpdate != 1 && okUpdate != 0) {
        std::cout << "Wrong option!\n";
        std::cout << "Dou you want to update the title? (1 for yes, 0 for no)\n";
        std::cin >> okUpdate;
    }
    if(okUpdate == 1) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Give the new title:\n";
        getline(std::cin, str);
        book.setTitle(str);
        okUpdate = 0;
    }
    std::cout << "Dou you want to update the author? (1 for yes, 0 for no)\n";
    std::cin >> okUpdate;
    while (okUpdate != 1 && okUpdate != 0) {
        std::cout << "Wrong option!\n";
        std::cout << "Dou you want to update the author? (1 for yes, 0 for no)\n";
        std::cin >> okUpdate;
    }
    if(okUpdate == 1) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Give the new author:\n";
        getline(std::cin, str);
        book.setAuthor(str);
        okUpdate = 0;
    }
    std::cout << "Dou you want to update the description? (1 for yes, 0 for no)\n";
    std::cin >> okUpdate;
    while (okUpdate != 1 && okUpdate != 0) {
        std::cout << "Wrong option!\n";
        std::cout << "Dou you want to update the description? (1 for yes, 0 for no)\n";
        std::cin >> okUpdate;
    }
    if(okUpdate == 1) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Give the new description:\n";
        getline(std::cin, str);
        book.setDescription(str);
        okUpdate = 0;
    }
    std::cout << "Dou you want to update the genre? (1 for yes, 0 for no)\n";
    std::cin >> okUpdate;
    while (okUpdate != 1 && okUpdate != 0) {
        std::cout << "Wrong option!\n";
        std::cout << "Dou you want to update the genre? (1 for yes, 0 for no)\n";
        std::cin >> okUpdate;
    }
    if(okUpdate == 1) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Give the new genre:\n";
        getline(std::cin, str);
        book.setGenre(str);
        okUpdate = 0;
    }
    std::cout << "Dou you want to update the cover? (1 for yes, 0 for no)\n";
    std::cin >> okUpdate;
    while (okUpdate != 1 && okUpdate != 0) {
        std::cout << "Wrong option!\n";
        std::cout << "Dou you want to update the cover? (1 for yes, 0 for no)\n";
        std::cin >> okUpdate;
    }
    if(okUpdate == 1) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Give the new cover:\n";
        getline(std::cin, str);
        book.setCover(str);
        okUpdate = 0;
    }
    std::cout << "Dou you want to update the year? (1 for yes, 0 for no)\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> okUpdate;
    while (okUpdate != 1 && okUpdate != 0) {
        std::cout << "Wrong option!\n";
        std::cout << "Dou you want to update the year? (1 for yes, 0 for no)\n";
        std::cin >> okUpdate;
    }
    if(okUpdate == 1) {
        std::cout << "Give the new year:\n";
        std::cin >> year;
        while (year < 0 || std::cin.fail()) {
            std::cout << "Wrong input!";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> year;
        }
        book.setYear(year);
        okUpdate = 0;
    }
    return databaseCtrl->addBook(book);
}


void browseDatabase(Controller *clientCtrl, Controller *databaseCtrl) {
    bool next = true;
    int pos = 0, opt;
    std:: string genre;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cout << "Which genre are you interested in?\n\t(leave empty if you want all the books)\n";
    getline(std::cin, genre);
    if(databaseCtrl->getAll().getBooksByGenre(genre).empty()) {
        std::cout << "We have no book in that genre, sorry!";
        return;
    }
    while (next) {
        auto currentBook = databaseCtrl->getBooksByGenre(genre)[pos];
        std::cout << currentBook.toString();
        std::cout << "Options:\n\t1. Add to your list and go to the next one\n\t2. Got o the next one\n\t3. Finish browsing\n";
        std::cin.clear();
        std::cin >> opt;
        while (opt <= 0 || opt >= 4 || std::cin.fail()) {
            std::cout << "Wrong option!\n";
            std::cout << "Options:\n\t1. Add to your list and go to the next one\n\t2. Got o the next one\n\t3. Finish browsing\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> opt;
        }
        switch (opt) {
            case 3 :
                next = false;
                break;
            case 1 :
                if(clientCtrl->getAll().checkDuplicate(currentBook)) {
                    std::cout << "This book is already in your list!\n";
                    break;
                }
                if(clientCtrl->addBook(currentBook))
                    std::cout << "Book added!\n";
                break;
            default :
                break;
        }
        if(pos == databaseCtrl->getBooksByGenre(genre).size() - 1)
            pos = 0;
        else
            pos++;
    }
}

void adminOptions() {
    std::cout << "Choose an operation\n";
    std::cout << "\t1. Show book list\n";
    std::cout << "\t2. Delete a book\n";
    std::cout << "\t3. Add a new book\n";
    std::cout << "\t4. Update a book\n";
    std::cout << "\t0. Exit\n";
}

void AdminScreen(Controller *ctrl) {
    int opt = -1;
    while (opt != 0 ) {
        adminOptions();
        std::cin.clear();
        std::cin >> opt;
        while (opt < 0 || opt >= 5 || std::cin.fail()) {
            std::cout << "Not a valid option!\n";
            adminOptions();
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> opt;
        }
        switch (opt) {
            case 0 :
                std::cout << "Bye bye!!";
                return;
            case 1 :
                std::cout << ctrl->toString() << "\n";
                break;
            case 2 :
                if(deleteBook(ctrl)) {
                    std::cout << "Book deleted!\n\n";
                    break;
                }
                std::cout << "No book was deleted!\n\n";
                break;
            case 3 :
                if(addBook(ctrl)) {
                    std::cout << "Book added!\n\n";
                    break;
                }
                std::cout << "The book was not added!\n\n";
                break;
            case 4 :
                if(updateBook(ctrl)) {
                    std::cout << "Book updated!\n\n";
                    break;
                }
                std::cout<< "Book was not updated!\n\n";
                break;
            default :
                break;
        }
    }
}

void clientOptions() {
    std::cout << "Choose an operation\n";
    std::cout << "\t1. Show your book list\n";
    std::cout << "\t2. Delete a book\n";
    std::cout << "\t3. Browse for new books\n";
    std::cout << "\t0. Exit\n";
}

void ClientScreen(Controller *clientCtrl, Controller *databaseCtrl) {
    int opt = -1;
    while (opt != 0 ) {
        clientOptions();
        std::cin.clear();
        std::cin >> opt;
        while (opt < 0 || opt >= 4 || std::cin.fail()) {
            std::cout << "Not a valid option!\n";
            clientOptions();
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> opt;
        }
        switch (opt) {
            case 0 :
                std::cout << "Bye bye!!";
                return;
            case 1 :
                std::cout << clientCtrl->toString() << "\n";
                break;
            case 2 :
                if(deleteBook(clientCtrl)){
                    std::cout << "Book deleted!\n\n";
                    break;
                }
                std::cout << "No book was deleted!\n\n";
                break;
            case 3 :
                browseDatabase(clientCtrl, databaseCtrl);
                break;
            default :
                break;
        }
    }
}