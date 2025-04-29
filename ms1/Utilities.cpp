/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <algorithm>
#include "Utilities.h"

using namespace std;

namespace seneca
{
    char Utilities::delimiter = ' ';

    void Utilities::getFieldWidth(size_t width)
    {
        this->fieldWidth = width;
    }

    size_t Utilities::getFieldWidth() const
    {
        return this->fieldWidth;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& success) {
    string token;
    size_t startPos = next_pos;
    
    next_pos = str.find(delimiter, startPos);
    
    if (startPos == next_pos)
    {
        success = false;
        throw runtime_error("ERROR: Empty token found.");
    }
    else if (next_pos == string::npos)
    {
        token = str.substr(startPos);
        token = trim(token);
        this->fieldWidth = std::max(token.length(), this->fieldWidth);
        success = false;
    }
    else
    {
        token = str.substr(startPos, next_pos - startPos);
        token = trim(token);
        this->fieldWidth = std::max(token.length(), this->fieldWidth);
        success = true;
    }
    
    next_pos++;
    
    if (token.empty()) {
        success = false;
        throw runtime_error("ERROR: Empty token found after trimming.");
    }

    return token;
}

    std::string seneca::Utilities::trim(const std::string& str) {
    size_t startPos = str.find_first_not_of(" \t");
    size_t endPos = str.find_last_not_of(" \t");
    if (startPos != std::string::npos && endPos != std::string::npos) {
        return str.substr(startPos, endPos - startPos + 1);
    }
    else {
        return ""; 
    }
}

    void Utilities::setDelimiter(char newDelim)
    {
        delimiter = newDelim;
    }

    char Utilities::getCurrentDelimiter()
    {
        return delimiter;
    }
}
