/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 25

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include "CustomerOrder.h"
#include "Utilities.h"

namespace seneca {
	size_t CustomerOrder::m_widthField = 1; // Initializing static member

	CustomerOrder::CustomerOrder() : m_name(""), m_product(""), m_cntItem(0), m_lstItem(nullptr) {}

	CustomerOrder::CustomerOrder(const CustomerOrder& other) {
		throw std::logic_error("Copy constructor for CustomerOrder is not allowed.");
	}

	CustomerOrder::CustomerOrder(const std::string& record)
	{
		Utilities util;
		bool more = true;
		size_t next_pos = 0;
		size_t pos = 0;
		m_widthField = util.getFieldWidth();

		// Extract customer name
		m_name = util.extractToken(record, next_pos, more);

		// Extract order name
		m_product = util.extractToken(record, next_pos, more);

		// Count the number of items
		m_cntItem = 0;
		pos = next_pos;
		while (more) {
			util.extractToken(record, next_pos, more);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < m_cntItem; ++i) {
			m_lstItem[i] = new Item(util.extractToken(record, pos, more));
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
		: m_name(std::move(src.m_name)),
		m_product(std::move(src.m_product)),
		m_cntItem(src.m_cntItem),
		m_lstItem(src.m_lstItem)
	{
		// Set the source object's pointers to null or appropriate default values
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src) {
			// Release resources owned by the destination object
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			// Move-assign members from the source object
			m_name = std::move(src.m_name);
			m_product = std::move(src.m_product);
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;

			// Set the source object's pointers to null or appropriate default values
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}


	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;

	}

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled)
				return false;
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
				return false;
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
				if (station.getQuantity() > 0) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					break;
				}
				else {
					os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(30) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled)
				os << "FILLED";
			else
				os << "TO BE FILLED";
			os << std::endl;
		}
	}
}