#pragma once
#include "Book.h"
#include <utility>
#include <sstream>

Book::Book(std::string title, std::string author, std::string genre, std::string description, int year, std::string cover) {
    this->title = std::move(title);
    this->author = std::move(author);
    this->description = std::move(description);
    this->year = year;
    this->genre = std::move(genre);
    this->cover = std::move(cover);
}

Book::Book(const Book &book) {
    this->title = book.title;
    this->author = book.author;
    this->description = book.description;
    this->year = book.year;
    this->genre = book.genre;
    this->cover = book.cover;
}

Book::~Book() = default;

void Book::setTitle(std::string titleNew) {
    this->title = std::move(titleNew);
}

void Book::setAuthor(std::string authorNew) {
    this->author = std::move(authorNew);
}

void Book::setGenre(std::string genreNew) {
    this->genre = std::move(genreNew);
}

void Book::setDescription(std::string descriptionNew) {
    this->description = std::move(descriptionNew);
}

void Book::setYear(int yearNew) {
    this->year = yearNew;
}

void Book::setCover(std::string coverNew) {
    this->cover = std::move(coverNew);
}

std::string Book::toString() {
    std::stringstream bookString;
    bookString << this->title << " by " << this->author << "\n" << this->description << "\n" << this->genre
        <<" book published in " << this->year << "\nCover: " << this->cover << "\n";
    return bookString.str();
}

bool Book::compare(const Book& other) {
    return this->title == other.title && this->author == other.author;
}
