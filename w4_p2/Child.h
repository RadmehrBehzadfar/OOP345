/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include "Toy.h"

namespace seneca
{
    class Child
    {
        std::string m_name{};
        unsigned int m_age{};
        size_t toyNum{};
        const seneca::Toy** m_toyArray{};

    public:
        Child(std::string name, int age, const Toy* toys[], size_t count);

        Child(const Child& child);

        void operator=(const Child& child);

        Child(Child&& child) noexcept;

        void operator=(Child&& child) noexcept;

        size_t size() const;

        friend std::ostream& operator<<(std::ostream& ostr, const Child& child);

        ~Child();
    };
}
#endif //! SENECA_CHILD_H