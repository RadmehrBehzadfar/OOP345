///////////////////////////////////////////////////////////////////////////
// Student ID#: 148786221
// Email: rbehzadfar@myseneca.ca
// Section: NRA
// Date: 2024-04-06
//
// Authenticity Declaration:
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace seneca
{
    size_t CustomerOrder::m_widthField = 0u;

    // Copy constructor
    CustomerOrder::CustomerOrder(const CustomerOrder& source)
    {
        throw false; // Not implemented
    }

    // Move constructor
    CustomerOrder::CustomerOrder(CustomerOrder&& source) noexcept
    {
        *this = std::move(source); // Utilizing move assignment operator
    }

    // Destructor
    CustomerOrder::~CustomerOrder()
    {
        if (m_lstItem)
        {
            // Deallocate memory for each item
            for (auto i = 0u; i < m_cntItem; ++i)
                delete m_lstItem[i];

            delete[] m_lstItem; // Deallocate memory for the array of pointers
            m_lstItem = nullptr; // Set pointer to null after deallocation
        }
    }

    // Check if the order is completely filled
    bool CustomerOrder::isOrderFilled() const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (!m_lstItem[i]->m_isFilled)
            {
                return false;
            }
        }
        return true;
    }

    // Check if a specific item is filled
    bool CustomerOrder::isItemFilled(const std::string& itemName) const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
            {
                return false;
            }
        }
        return true;
    }

    // Constructor from string
    CustomerOrder::CustomerOrder(const std::string& source)
    {
        Utilities util;
        bool more = true;
        size_t point = 0u;
        size_t index = 0u;

        try
        {
            // Extracting information from the source string
            m_name = util.extractToken(source, point, more);
            m_product = util.extractToken(source, point, more);
            m_cntItem = std::count(source.begin(), source.end(),
                util.getDelimiter()) - 1;

            // Allocate memory for the array of Item pointers
            if (m_cntItem)
                m_lstItem = new Item * [m_cntItem];

            // Populate the array with items
            while (more && m_cntItem)
            {
                m_lstItem[index] = new Item(util.extractToken(source, point, more));
                ++index;
            }

            // Update the width field if necessary
            CustomerOrder::m_widthField = max(util.getFieldWidth(), CustomerOrder::m_widthField);
        }
        catch (std::string err)
        {
            cout << err; // Output error message
        }
    }

    // Move assignment operator
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& source) noexcept
    {
        if (this != &source)
        {
            // Deallocate memory for existing resources
            if (m_lstItem)
            {
                for (auto i = 0u; i < m_cntItem; ++i)
                    delete m_lstItem[i];

                delete[] m_lstItem;
            }

            // Move resources from source to this object
            m_name = source.m_name;
            m_product = source.m_product;
            m_cntItem = source.m_cntItem;
            m_lstItem = source.m_lstItem;

            // Reset source object
            source.m_name = "";
            source.m_product = "";
            source.m_cntItem = 0u;
            source.m_lstItem = nullptr;
        }

        return *this;
    }

    // Fill an item from a station
    void CustomerOrder::fillItem(Station& station, std::ostream& os)
    {
        bool isSingle = true;

        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i] && station.getItemName() == m_lstItem[i]->m_itemName && !m_lstItem[i]->m_isFilled && isSingle)
            {
                if (station.getQuantity() > 0)
                {
                    // Fill the item
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled " << m_name << ", " << m_product
                        << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;

                    isSingle = false;
                }
                else
                {
                    os << "    Unable to fill " << m_name << ", " << m_product
                        << " [" << m_lstItem[i]->m_itemName << "]" << std::endl; // Output message indicating inability to fill
                }
            }
        }
    }

    // Display the order details
    void CustomerOrder::display(std::ostream& os) const
    {
        os << m_name << " - " << m_product << endl;

        for (auto i = 0u; i < m_cntItem; ++i)
        {
            // Output item details
            os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName;
            os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
        }
    }
}
