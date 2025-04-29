/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Workstation.h"

using namespace std;

namespace seneca
{
    std::deque<CustomerOrder> g_pending; 
    std::deque<CustomerOrder> g_completed;
    std::deque<CustomerOrder> g_incomplete;

    // Constructor definition for the Workstation class
    Workstation::Workstation(const string &src) : Station(src)
    {
        m_pNextStation = NULL;   // Initializing the pointer to the next station as NULL
    }

    // Definition of the fill function for the Workstation class
    void Workstation::fill(std::ostream &os)
    {
        if (!m_orders.empty())
        {
            m_orders.front().fillItem(*this, os);   // Filling the first item in the order at the workstation
        }
    }

    // Definition of the attemptToMoveOrder function for the Workstation class
    bool Workstation::attemptToMoveOrder()
    {
        if (!m_orders.empty())
        {
            if (!m_orders.front().isItemFilled(getItemName()) && this->getQuantity() > 0)
            {
                return false; // If the item is not filled and there is quantity available, do nothing
            }
            else if (!m_orders.front().isItemFilled(getItemName()) && this->getQuantity() <= 0)
            {
                if (m_pNextStation)
                {
                    *m_pNextStation += move(m_orders.front());   // Move the order to the next station
                }
                else
                {
                    g_incomplete.push_back(move(m_orders.front()));   // If there's no next station, add to incomplete orders
                }
                m_orders.pop_front();   // Remove the order from the workstation
                return true;
            }
            else if (m_orders.front().isItemFilled(getItemName()))
            {
                if (m_pNextStation)
                {
                    *m_pNextStation += move(m_orders.front());   // Move the order to the next station
                }
                else
                {
                    if (m_orders.front().isOrderFilled())
                    {
                        g_completed.push_back(move(m_orders.front()));   // If the order is filled, add to completed orders
                    }
                    else
                    {
                        g_incomplete.push_back(move(m_orders.front()));   // If the order is not filled, add to incomplete orders
                    }
                }
                m_orders.pop_front();   // Remove the order from the workstation
                return true;
            }
        }
        return false;   // Return false if no action is taken
    }

    // Definition of the setNextStation function for the Workstation class
    void Workstation::setNextStation(Workstation *station)
    {
        m_pNextStation = station;   // Set the next station for the current workstation
    }

    // Definition of the getNextStation function for the Workstation class
    Workstation *Workstation::getNextStation() const
    {
        return m_pNextStation;   // Return the pointer to the next station
    }

    // Definition of the display function for the Workstation class
    void Workstation::display(std::ostream &os) const
    {
        if (m_pNextStation)
        {
            os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;   // Display the connection between current and next station
        }
        else
        {
            os << getItemName() << " --> " << "End of Line" << endl;   // If there's no next station, display end of line
        }
    }

    // Overloaded += operator definition for the Workstation class
    Workstation &Workstation::operator+=(CustomerOrder &&newOrder)
    {
        m_orders.push_back(move(newOrder));   // Add a new order to the workstation
        return *this;   // Return a reference to the modified workstation
    }

}
