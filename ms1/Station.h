/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>

namespace seneca
{
  class Station
  {
    int m_id            { 0 };
    std::string m_name  { "" };
    std::string m_desc  { "" };
    size_t m_serial_num { 0u };
    size_t m_curr_items { 0u };

    static size_t m_widthField;
    static size_t id_generator;

  public:
    Station(const std::string& src);

    const std::string &getItemName() const;

    size_t getNextSerialNumber();

    size_t getQuantity() const;

    void updateQuantity();

    void display(std::ostream &os, bool full) const;
  };
}
#endif // !SENECA_STATION_H
