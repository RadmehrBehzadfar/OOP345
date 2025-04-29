/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace seneca
{
    const int STR_SIZE = 6;
    class Spell_Checker
    {
        std::string m_badWords[STR_SIZE]{};
        std::string m_goodWords[STR_SIZE]{};
        size_t m_replaceCount[STR_SIZE]{};

    public:
        Spell_Checker() {}
        Spell_Checker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}
#endif //! SENECA_SPELLCHECKER_H