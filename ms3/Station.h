/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <string>
#include <vector>
#include <list>

namespace seneca
{
    class Station
    {
    private:
        int id{};               
        std::string itemName{};  
        size_t nextSerialStr{}; 
		 std::string description{};
        size_t itemNumStr{};   

    public:
        // Constructor: Initializes a Station object using a record string
        Station(const std::string& record);

        // Get the item name of the Station
        const std::string& getItemName() const;

        // Get the next serial number of the Station and increment it
        size_t getNextSerialNumber();

        // Get the quantity of the Station
        size_t getQuantity() const;

        // Update the quantity of the Station by decrementing it if it's greater than 0
        void updateQuantity();

        // Display the Station's information on the output stream
        void display(std::ostream& os, bool full) const;
    };
}

#endif
