/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"
#include "iomanip"


namespace seneca
{
    class Professor : public Employee
    {
    private:
        std::string m_department;
        static std::string trim(const std::string& str);
    public:
        Professor(std::istream& in);

        void display(std::ostream& out) const override;
        std::string status() const override;
        std::string department() const;
    };
}

#endif //! SENECA_PROFESSOR_H
