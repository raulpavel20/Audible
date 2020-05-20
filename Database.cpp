#pragma once
#include "Database.h"
#include <sstream>
#include <utility>

Database::~Database() = default;

std::string Database::toString() {
    std::stringstream bookList;
    if(this->bookDatabase.empty()) {
        bookList << "No books in the database!\n";
        return bookList.str();
    }
    bookList << "Book list: \n\n";
    for(auto & i : this->bookDatabase) {
        bookList << i.toString() << "\n";
    }
    return bookList.str();
}

bool Database::addBook(const Book& book) {
    this->bookDatabase.insert(this->bookDatabase.end(), book);
    return true;
}

bool Database::setAll(std::vector<Book> newBookDatabase) {
    this->bookDatabase = std::move(newBookDatabase);
    return true;
}

bool Database::checkByTitle(const std::string &title) {
    for(auto & i : this->bookDatabase) {
        if(i.getTitle() == title)
            return true;
    }
    return false;
}

bool Database::checkDuplicate(const Book& book) {
    for(auto & i : this->bookDatabase) {
        if(i.compare(book))
            return true;
    }
    return false;
}

std::vector<Book> Database::getBooksByGenre(const std::string &genre) {
    if(genre.empty())
        return this->bookDatabase;
    std::vector<Book> list;
    for(auto & i : this->bookDatabase) {
        if(i.getGenre() == genre)
            list.push_back(i);
    }
    return list;
}
