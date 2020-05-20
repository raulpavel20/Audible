#pragma once
#ifndef AUDIBLE_BOOK_H
#define AUDIBLE_BOOK_H

#include <string>

/**
 * Main class, creates instance BOOK
 * Takes as input all the attributes of the object
 */
class Book {
    private :
        std::string title;
        std::string author;
        std::string genre;
        std::string description;
        int year;
        std::string cover;
    public :
        explicit Book(std::string title = "", std::string author = "", std::string genre = "", std::string description = "",
                int year = 1900, std::string cover = "");

        Book(const Book &book);

        ~Book();

        void setTitle(std::string titleNew);
        void setAuthor(std::string authorNew);
        void setGenre(std::string genreNew);
        void setDescription(std::string descriptionNew);
        void setYear(int yearNew);
        void setCover(std::string coverNew);

        std::string getTitle() { return this->title; }
        std::string getAuthor() { return this->author; }
        std::string getGenre() { return this->genre; }
        std::string getDescription() { return this->description; }
        int getYear() { return this->year; }
        std::string getCover() { return this->cover; }

        std::string toString();

        bool compare(const Book& other);
};

#endif //AUDIBLE_BOOK_H
