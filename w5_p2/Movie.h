/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <iostream>
#include <string>

namespace seneca
{
    class Movie
    {
        std::string m_title{ "" };
        size_t m_year{ 0u };
        std::string m_description{ "" };

    public:
        Movie() {}
        const std::string& title() const;
        Movie(const std::string& strMovie);

        template <typename T>
        void fixSpelling(T& spellChecker) 
        {
            spellChecker(m_title);
            spellChecker(m_description);
        }

        friend std::ostream& operator<<(std::ostream& os, const Movie& src);
    };
}
#endif //! SENECA_MOVIE_H