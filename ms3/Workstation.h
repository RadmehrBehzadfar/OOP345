/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_WORKSTATION_H 
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca
{
    // Declaration of external dequeues for pending, completed, and incomplete orders
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    // Declaration of the Workstation class, inheriting from Station
    class Workstation : public Station
    {
    private:
        std::deque<CustomerOrder> m_orders;    // Deque to hold orders at the workstation
        Workstation *m_pNextStation;           // Pointer to the next workstation in the process

    public:
        // Constructor for the Workstation class
        Workstation(const std::string &src);

        // Function to fill an order
        void fill(std::ostream &os);

        // Function to attempt to move an order to the next workstation
        bool attemptToMoveOrder();

        // Function to set the next workstation in the process
        void setNextStation(Workstation *station);

        // Function to get the next workstation in the process
        Workstation *getNextStation() const;

        // Function to display information about the workstation
        void display(std::ostream &os) const;

        // Overloaded += operator to add a new order to the workstation
        Workstation &operator+=(CustomerOrder &&newOrder);
    };
}

#endif // SENECA_WORKSTATION_H
