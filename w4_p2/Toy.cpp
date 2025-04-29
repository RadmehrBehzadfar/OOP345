/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Toy.h"

namespace seneca
{
    void Toy::trim(std::string& string)
    {
        int firstCharLoc{};
        int lastCharLoc{};
        int found = 0;
       
        for (int i = 0; i < (int)string.length() && found == 0; i++)
        {
            if (isalnum(string[i]))
            {
                firstCharLoc = i;
                found = 1;
            }
        }
        string.erase(string.begin(), string.begin() + firstCharLoc);

        found = 0;
        for (int i = (int)string.length(); i > 0 && found == 0; i--)
        {
            if (isalnum(string[i]))
            {
                lastCharLoc = i;
                found = 1;
            }
        }
        string.erase(lastCharLoc + 1);
    }

    Toy::Toy(const std::string& toy)
    {
        std::string temp{};
        int deliStart{};
        int deliEnd{};
        
        deliEnd = toy.find(':');
        temp = toy.substr(0, deliEnd);
        trim(temp);
        order_id = std::stoi(temp);
        
        deliStart = deliEnd + 1;
        deliEnd = toy.find(':', deliStart);
        temp = toy.substr(deliStart, deliEnd - deliStart);
        trim(temp);
        name = temp;
        
        deliStart = deliEnd + 1;
        deliEnd = toy.find(':', deliStart);
        temp = toy.substr(deliStart, deliEnd - deliStart);
        trim(temp);
        itemNum = std::stoi(temp);
        
        deliStart = deliEnd + 1;
        temp = toy.substr(deliStart);
        trim(temp);
        price = std::stod(temp);
    }

    Toy::Toy(const Toy& toy)
    {
        order_id = toy.order_id;
        name = toy.name;
        itemNum = toy.itemNum;
        price = toy.price;
    }

    std::ostream& operator<<(std::ostream& ostr, const Toy& toy)
    {
        double subTotal{ toy.price * toy.itemNum };
        double tax = subTotal * toy.hst / 100;
        ostr << "Toy";
        ostr.width(8);
        ostr << toy.order_id << ":";
        ostr.width(18);
        ostr << std::right << toy.name;
        ostr.width(3);
        ostr << toy.itemNum << " items";
        ostr.width(8);
        ostr << toy.price << "/item  subtotal:";
        ostr.width(7);
        ostr << std::fixed << std::setprecision(2) << subTotal << " tax:";
        ostr.width(6);
        ostr << std::setprecision(2) << tax << " total:";
        ostr.width(7);
        ostr << subTotal + tax << std::endl;
        return ostr;
    }

    Toy::operator bool() const
    {
        return order_id;
    }
}