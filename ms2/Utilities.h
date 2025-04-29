/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 25

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>
#include <stdexcept> 

namespace seneca {
    class Utilities {
        size_t m_widthField;
        static char m_delimiter;
    public:
        Utilities();
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
        std::string trim(const std::string& str);
    };
}
#endif 