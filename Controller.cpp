#pragma once

#include "Controller.h"
#include "Book.h"
#include "PersistenceEngine.h"
#include <string>
#include <utility>

Controller::~Controller() = default;

std::string Controller::toString() {
    return this->bookDatabase.toString();
}

void Controller::loadData(std::string rootKey, const std::string& fileName) {
    this->bookDatabase.setAll(PersistenceEngine::getData(std::move(rootKey), fileName));
}

std::vector<Book>::iterator Controller::findByTitle(const std::string& title) {
    std::vector<Book>::iterator itr;
    for(int i = 0; i < this->bookDatabase.getAll().size(); i++) {
        if(this->bookDatabase.getAll()[i].getTitle() == title)
            return this->bookDatabase.getAll().begin() + i;
    }
    return itr;
}

bool Controller::deleteBook(const std::string& title) {
    auto i = this->findByTitle(title);
    auto newBookDatabase = this->bookDatabase.getAll();
    newBookDatabase.erase(i);
    return this->bookDatabase.setAll(newBookDatabase);
}

bool Controller::addBook(const Book& book) {
    this->bookDatabase.addBook(book);
    return true;
}

void Controller::saveData(const std::string& rootKey, const std::string& fileName) {
    PersistenceEngine::saveData(this->bookDatabase.getAll(), rootKey, fileName);
}
