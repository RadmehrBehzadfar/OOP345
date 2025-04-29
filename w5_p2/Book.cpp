/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#include <iomanip>
#include "Book.h"

using namespace std;

namespace seneca
{
    const std::string& Book::title() const 
    {
        return b_title;
    }

    const std::string& Book::country() const
    {
        return b_country;
    }

    const size_t& Book::year() const 
    {
        return b_year;
    }

    double& Book::price() 
    {
        return b_price;
    }

    Book::Book(const std::string& strBook)
    {
        string _tempStr = strBook;
        int _tempIdx = 0u;

        auto removeSpace = [=](string& src) 
        {
            if (src[0] == ' ')
                src.erase(0, src.find_first_not_of(' '));
            else
                src.erase(src.find_last_not_of(' ') + 1);
            };

        removeSpace(_tempStr);
        _tempIdx = _tempStr.find(',');
        b_author = _tempStr.substr(0, _tempIdx);
        removeSpace(b_author);
        _tempStr.erase(0, _tempIdx + 1);


        removeSpace(_tempStr);
        _tempIdx = _tempStr.find(',');
        b_title = _tempStr.substr(0, _tempIdx);
        removeSpace(b_title);
        _tempStr.erase(0, _tempIdx + 1);

        removeSpace(_tempStr);
        _tempIdx = _tempStr.find(',');
        b_country = _tempStr.substr(0, _tempIdx);
        removeSpace(b_country);
        _tempStr.erase(0, _tempIdx + 1);

        removeSpace(_tempStr);
        _tempIdx = _tempStr.find(',');
        b_price = std::stod(_tempStr.substr(0, _tempIdx));
        _tempStr.erase(0, _tempIdx + 1);

        removeSpace(_tempStr);
        _tempIdx = _tempStr.find(',');
        b_year = std::stoi(_tempStr.substr(0, _tempIdx));
        _tempStr.erase(0, _tempIdx + 1);

        removeSpace(_tempStr);
        removeSpace(_tempStr);
        b_description = _tempStr;
    }

    std::ostream& operator<<(std::ostream& os, const Book& src) 
    {
        os << setw(20) << std::right << src.b_author << " | ";
        os << setw(22) << src.title() << " | ";
        os << setw(5) << src.country() << " | ";
        os << setw(4) << src.year() << " | ";
        os << setw(6) << fixed << setprecision(2) << src.b_price << " | ";
        os << std::left << src.b_description << endl;

        return os;
    }
}