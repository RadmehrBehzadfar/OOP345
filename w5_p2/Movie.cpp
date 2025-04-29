/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#include <iostream>
#include <iomanip>
#include "Movie.h"

using namespace std;

namespace seneca
{
    const std::string& Movie::title() const
    {
        return m_title;
    }

    Movie::Movie(const std::string& strMovie) 
    {
        if (!strMovie.empty()) 
        {
            string _tempStr = strMovie;
            int _tempIdx = 0u;

            auto removingspace = [=](string& src) 
            {
                if (src[0] == ' ')
                    src.erase(0, src.find_first_not_of(' '));
                else
                    src.erase(src.find_last_not_of(' ') + 1);
                };

            removingspace(_tempStr);
            _tempIdx = _tempStr.find(',');
            m_title = _tempStr.substr(0, _tempIdx);
            removingspace(m_title);
            _tempStr.erase(0, _tempIdx + 1);

            removingspace(_tempStr);
            _tempIdx = _tempStr.find(',');
            m_year = std::stoi(_tempStr.substr(0, _tempIdx));
            _tempStr.erase(0, _tempIdx + 1);

            removingspace(_tempStr);
            removingspace(_tempStr);
            m_description = _tempStr;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Movie& src)
    {
        os << setw(40) << std::right << src.m_title << " | ";
        os << std::left << setw(4) << src.m_year << " | " << src.m_description << endl;

        return os;
    }
}