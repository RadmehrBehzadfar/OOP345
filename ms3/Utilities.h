/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>

namespace seneca
{
    class Utilities
    {
        size_t m_widthField = 1; // Private member variable to store the default field width

    public:
        // Static functions to set and get the delimiter used for token extraction
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

        // Member functions to set and get the width of the field used for formatting
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;

        // Function to extract a token from the given string starting from the specified position
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    };
}

#endif // seneca_UTILITIES_H
