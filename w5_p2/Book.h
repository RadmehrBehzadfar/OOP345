/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca
{
    class Book
    {
        std::string b_author{ "" };
        std::string b_title{ "" };
        std::string b_country{ "" };
        size_t b_year{ 0 };
        double b_price{ 0.0 };
        std::string b_description{ "" };

    public:
        Book() {}
        Book(const std::string& strBook);
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();

        template <typename T>
        void fixSpelling(T& spellChecker) 
        {
            spellChecker(b_description);
        }

        friend std::ostream& operator<<(std::ostream& os, const Book& src);
    };
}

#endif //! SENECA_BOOK_H