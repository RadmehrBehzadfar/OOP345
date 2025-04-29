/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <string>

namespace seneca
{
    class Toy
    {
        unsigned int order_id{};
        std::string name{};
        unsigned int itemNum{};
        double price{};
        unsigned int hst{ 13 };
        void trim(std::string& string);

    public:
        Toy() {};

        Toy(const Toy& toy);

        void update(int numItems) { itemNum = numItems; };

        Toy(const std::string& toy);

        friend std::ostream& operator<<(std::ostream& ostr, const Toy& toy);

        operator bool() const;
    };
}
#endif //! SENECA_TOY_H