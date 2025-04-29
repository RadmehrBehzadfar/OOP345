/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 25

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include "Station.h"
#include "Utilities.h"

namespace seneca {
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string& str) {
		Utilities util;
		bool more = true;
		size_t pos = 0;
		m_itemName = util.extractToken(str, pos, more);
		m_nextSerialNumber = std::stoul(util.extractToken(str, pos, more));
		m_quantity = std::stoul(util.extractToken(str, pos, more));
		m_description = util.extractToken(str, pos, more);
		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}
		m_id = ++id_generator;
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		return m_nextSerialNumber++;
	}

	size_t Station::getQuantity() const {
		return m_quantity;
	}

	void Station::updateQuantity() {
		if (m_quantity > 0)
			m_quantity--;
	}

	void Station::display(std::ostream& os, bool full) const {
		os << std::setfill('0') << std::setw(3) << m_id << " | "
			<< std::setw(14) << std::left << std::setfill(' ') << m_itemName << " | ";
		os << std::setw(6) << std::right << std::setfill('0') << m_nextSerialNumber << " | ";

		if (full)
			os << std::setw(4) << std::right << std::setfill(' ') << m_quantity << " | " << m_description;

		os << std::endl;

	}
}