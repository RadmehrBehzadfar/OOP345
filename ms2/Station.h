/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 25

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iomanip>
#include <string>
#include <iostream>
namespace seneca {
    class Station {
        int m_id;
        std::string m_itemName;
        std::string m_description;
        size_t m_nextSerialNumber;
        size_t m_quantity;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string& str);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif 
