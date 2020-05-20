#pragma once
#ifndef AUDIBLE_CONTROLLER_H
#define AUDIBLE_CONTROLLER_H

#include "Database.h"
#include "Book.h"
#include <string>

class Controller {
    private :
        Database bookDatabase;
    public :
        ~Controller();

        Database getAll() { return this->bookDatabase; }

        std::string toString();

        void loadData(std::string rootKey, const std::string& fileName);

        void saveData(const std::string& rootKey, const std::string& fileName);

        std::vector<Book>::iterator findByTitle(const std::string& title);

        bool deleteBook(const std::string& title);
        std::vector<Book> getBooksByGenre(const std::string &genre) { return this->bookDatabase.getBooksByGenre(genre); }
        bool addBook(const Book& book);
};


#endif //AUDIBLE_CONTROLLER_H
