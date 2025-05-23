/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include <iostream>
#include "Person.h"
namespace seneca {
	class Employee : public Person {
		std::string m_name{};
		std::string m_age{};
		std::string m_id{};
	public:
		Employee(std::istream& istr);
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;
		void display(std::ostream& out) const;
	};
}
#endif //! SENECA_EMPLOYEE_H
