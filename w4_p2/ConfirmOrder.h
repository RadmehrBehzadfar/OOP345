/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

namespace seneca
{
    class ConfirmOrder //declaring the class ConfirmOrder...
    {
        const seneca::Toy** m_toyArray{};// m_toyArray a pointer to an array of pointers(Toy)
        int keeptrack{};

    public:
        ConfirmOrder() {}; //default constructor
        ConfirmOrder(const ConfirmOrder& co); // cpy constructor
        void operator=(const ConfirmOrder& co);
        ConfirmOrder(ConfirmOrder&& co) noexcept;
        void operator=(ConfirmOrder&& co) noexcept;
        ConfirmOrder& operator+=(const Toy& toy); // adds the toy onject
        ConfirmOrder& operator-=(const Toy& toy);// removes it
        friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& co); // overloading operator...
        ~ConfirmOrder(); //dest
    };

}
#endif //! SENECA_CONFIRMORDER_H 