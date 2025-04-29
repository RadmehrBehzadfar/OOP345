/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 25

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include "Utilities.h"

namespace seneca {
    Utilities::Utilities() : m_widthField(1) {}

    std::string Utilities::trim(const std::string& str) {
        size_t startPos = str.find_first_not_of(" \t");
        size_t endPos = str.find_last_not_of(" \t");
        if (startPos != std::string::npos && endPos != std::string::npos) {
            return str.substr(startPos, endPos - startPos + 1);
        }
        else {
            return "";  // String consists only of whitespace
        }
    }

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        size_t found = str.find(m_delimiter, next_pos);
        std::string token;
        if (found != std::string::npos && found != 0) {
            token = str.substr(next_pos, found - next_pos);
            next_pos = found + 1;
            more = true;

            // Trim
            token = trim(token);
        }
        else {
            token = str.substr(next_pos);
            more = false;

            if (token == std::string(1, m_delimiter)) {
                more = false; // No more tokens available
                token.clear(); // No token to return
            }

            //Trim
            token = trim(token);
        }

        // Update widthField
        if (!token.empty() && token.length() > m_widthField) {
            m_widthField = token.length();
        }

        if (token.empty()) {
            more = false;
            throw std::invalid_argument("No valid token found in the string.");        
        }

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }

    char Utilities::m_delimiter = ',';
}