#pragma once
#ifndef AUDIBLE_DATABASE_H
#define AUDIBLE_DATABASE_H

#include "Book.h"
#include <vector>
#include <string>

class Database {
    private :
        std::vector<Book> bookDatabase;
    public :
        ~Database();

        std::string toString();

        std::vector<Book> getAll() { return this->bookDatabase; }

        bool setAll(std::vector<Book> newBookDatabase);

        bool checkByTitle(const std::string& title);
        bool checkDuplicate(const Book& book);
        std::vector<Book> getBooksByGenre(const std::string &genre);

        bool addBook(const Book& book);
};


#endif //AUDIBLE_DATABASE_H
