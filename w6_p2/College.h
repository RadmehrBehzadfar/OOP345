/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <vector>
#include <list>
#include "Person.h"
namespace seneca {
	class College {
		std::vector<Person*> m_persons;
	public:
		College() {};
		College(const College&) = delete;
		College& operator=(const College&) = delete;
		~College();
		College& operator +=(Person* thePerson);
		//First Test
		void display(std::ostream& out) const;

		//Second test
		template <typename T>
		void select(const T& test, std::list<const Person*>& persons)
		{
			for (auto i = m_persons.begin(); i != m_persons.end(); i++)
			{
				if (test(*i))
				{
					persons.push_back(*i);
				}
			}
		}
	};
}

#endif //! SENECA_COLLEGE_H
