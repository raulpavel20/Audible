#pragma once

#ifndef AUDIBLE_JSONPARSER_H
#define AUDIBLE_JSONPARSER_H

#include <fstream>
#include <string>

class JSONparser {
    private :
        std::ifstream inFile;
        std::ofstream outFile;
    public :
        void openFile(const std::string& fileName){ this->inFile.open(fileName); }
        void closeFiles(){ this->inFile.close(); this->outFile.close(); }
        std::string get() {char* s; this->inFile.getline(s, 10); return s;}
};


#endif //AUDIBLE_JSONPARSER_H
