/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

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
        size_t fieldWidth{1};

        static char delimiter;

    public:
        void getFieldWidth(size_t width);

        size_t getFieldWidth() const;

        static std::string trim(const std::string& str);

        std::string extractToken(const std::string& str, size_t& next_pos, bool& success);

        static void setDelimiter(char newDelim);
        static char getCurrentDelimiter();
    };
}

#endif // !SENECA_UTILITIES_H
