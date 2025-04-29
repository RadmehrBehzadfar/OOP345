/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "College.h"
namespace seneca {
    College::~College()
    {
        for (auto i = m_persons.begin(); i != m_persons.end(); ++i)
        {
            delete (*i);
        }
    }
    College& College::operator+=(Person* thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }
    void College::display(std::ostream& out) const
    {
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (auto i = m_persons.begin(); i != m_persons.end(); ++i)
        {
            (*i)->display(out);
            std::cout << std::endl;
        }
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (auto i = m_persons.begin(); i != m_persons.end(); ++i)
        {
            std::cout.setf(std::ios::left);
            std::cout << "| ";
            std::cout.width(10);
            std::cout << (*i)->status();
            std::cout << "| ";
            std::cout.width(10);
            std::cout << (*i)->id();
            std::cout << "| ";
            std::cout.width(20);
            std::cout << (*i)->name();
            std::cout << " | ";
            std::cout.width(3);
            std::cout << (*i)->age();
            std::cout << " |" << std::endl;
        }
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }
}