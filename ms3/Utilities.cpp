/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Utilities.h"
using namespace std;

namespace seneca 
{
    // Static member variable to hold the delimiter
    static char m_delimiter;

    // Utility function to find the index of the first or last non-whitespace character in the string
    static size_t findNonWhiteSpace(std::string str, bool reversed = false) 
    {
        size_t i = (reversed ? str.length() - 1 : 0);
        size_t increment = (reversed ? static_cast<size_t>(-1) : 1);

        while (i < str.length() && i >= 0)
        {
            if (str[i] != ' ')
                return i;
            i += increment;
        }

        return 0;
    }

    // Set the width of the field for formatting
    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    // Get the current width of the field
    size_t Utilities::getFieldWidth() const 
    {
        return m_widthField;
    }

    // Extract a token from the given string starting from the specified position (next_pos)
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        // Find the position of the next delimiter in the string
        size_t pos = str.find(m_delimiter, next_pos);

        // If the delimiter is found at the current position, no token is available
        if (pos == next_pos) 
        {
            more = false;
            throw "pos = next_pos";
        }

        // Extract the token from the string
        string token = str.substr(next_pos, pos - next_pos); // Might include the delimiter, so we will remove it later
        token = token.substr(findNonWhiteSpace(token)); // Remove leading whitespaces
        token = token.substr(0, findNonWhiteSpace(token, true) + 1); // Remove trailing whitespaces

        // Update the widthField to the maximum of the current token length and the existing widthField
        m_widthField = std::max(token.length(), getFieldWidth());

        // Update next_pos and set more to true if there are more tokens left in the string
        if (pos != std::string::npos)
        {
            next_pos = pos + 1;
            more = true;
        } else {
            more = false; // No more tokens left
        }

        return token; // Return the extracted token
    }

    // Set the delimiter to be used for token extraction
    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    // Get the current delimiter
    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}
