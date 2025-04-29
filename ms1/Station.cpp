/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace seneca
{

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const std::string& inputStr) {
        Utilities utility;
        size_t position = 0;
        bool more = true;
        m_id = ++id_generator;

        try {
            m_name = utility.extractToken(inputStr, position, more);
            m_serial_num = stoi(utility.extractToken(inputStr, position, more));
            m_curr_items = stoi(utility.extractToken(inputStr, position, more));
            m_widthField = std::max(utility.getFieldWidth(), m_widthField);
            if (more) {
                m_desc = utility.extractToken(inputStr, position, more);
            }
        } catch (const string& error) {
            cout << error << endl;
        }
    }

    const std::string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        return m_serial_num++;
    }

    size_t Station::getQuantity() const {
        return m_curr_items;
    }

    void Station::updateQuantity() {
        if (m_curr_items > 0) {
            --m_curr_items;
        }
    }

  void Station::display(std::ostream& os, bool full) const {
		os << std::setfill('0') << std::setw(3) << m_id << " | "
			<< std::setw(14) << std::left << std::setfill(' ') << m_name << " | ";
		os << std::setw(6) << std::right << std::setfill('0') << m_serial_num << " | ";

		if (full)
			os << std::setw(4) << std::right << std::setfill(' ') << m_curr_items << " | " << m_desc;
        os << std::endl;
	}
}
