#pragma once

#ifndef AUDIBLE_PERSISTENCEENGINE_H
#define AUDIBLE_PERSISTENCEENGINE_H

#include "Book.h"
#include <vector>


class PersistenceEngine {
    public:
        ~PersistenceEngine();

    static std::vector<Book> getData(const std::string& rootKey, const std::string& fileName);
    static void saveData(const std::vector<Book>& database, const std::string& rootKey, const std::string& fileName);
};


#endif //AUDIBLE_PERSISTENCEENGINE_H
