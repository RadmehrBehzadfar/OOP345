/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#include <string>
#include <iostream>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"
#include "Workstation.h"
using namespace std;
namespace seneca
{
    // Static member variables
    static size_t m_widthField = 0; // Width of the field for displaying data
    static int id_generator = 0; 
    // Constructor
    Station::Station(const std::string& record)
    {
        // Generate a unique ID for the current station
        id = ++id_generator;

        // Initialize variables to extract data from the 'record' string
        size_t next_pos = 0;
        Utilities util;
        bool more;

        // Extract the item name from the 'record' and store it in 'itemName'
        itemName = util.extractToken(record, next_pos, more);

        // Extract the next serial number (as a string) from the 'record',
        // convert it to an integer, and store it in 'nextSerialStr'
        nextSerialStr = stoi(util.extractToken(record, next_pos, more));

        // Extract the number of items (as a string) from the 'record',
     
        itemNumStr = stoi(util.extractToken(record, next_pos, more));

        // Update the widthField if the current field width in 'util' is greater than the stored value
        m_widthField = std::max(util.getFieldWidth(), m_widthField);

        // Extract the description from the 'record' and store it in 'description'
        description = util.extractToken(record, next_pos, more);
    }

    // Get the item name
const std::string& Station::getItemName() const
{
    return itemName;
}

// Get the next serial number and increment it for the next call
size_t Station::getNextSerialNumber()
{
    return nextSerialStr++;
}

// Get the current quantity of items
size_t Station::getQuantity() const
{
    return itemNumStr;
}

// Update the quantity of items by decrementing it by 1
void Station::updateQuantity()
{
    itemNumStr = (itemNumStr > 0) ? itemNumStr - 1 : 0;
}

    // Display the station information to the output stream 'os'

    void Station::display(std::ostream& os, bool full) const
    {
        if (!full)
        {
            // Display minimal information for non-full mode
            os.width(3);
            os.fill('0');
            os.setf(ios::right);
            os << id;
            os.unsetf(ios::right);
            os.fill(' ');
            os << " | ";
            os.width(m_widthField);
            os.setf(ios::left);
            os << itemName;
            os << " | ";
            os << "";
            os.setf(ios::right);
            os.width(6);
            os.fill('0');
            os << nextSerialStr;
            os.unsetf(ios::right);
            os << " | ";
            os << "";
        }
        else
        {
            // Display complete information for full mode
            os.width(3);
            os.fill('0');
            os.setf(ios::right);
            os << id;
            os.unsetf(ios::right);
            os.fill(' ');
            os << " | ";
            os.width(m_widthField);
            os.setf(ios::left);
            os << itemName;
            os.unsetf(ios::left);
            os << " | ";
            os.setf(ios::right);
            os.width(6);
            os.fill('0');
            os << nextSerialStr;
            os.fill(' ');
            os << " | ";
            os.width(4);
            os << itemNumStr;
            os.unsetf(ios::right);
            os << " | ";
            os << description;
        }
        os << endl;
    }

} // namespace seneca
