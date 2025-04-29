/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 02 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Toy.h"
#include "ConfirmOrder.h"

namespace seneca
{
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& co)
    {
        *this = co;
    }

    void ConfirmOrder::operator=(const ConfirmOrder& co)
    {
        if (this != &co)
        {
            if (keeptrack)
            {
                for (int i = 0; i < keeptrack; i++)
                {
                    m_toyArray[i] = nullptr;
                }
                delete[] m_toyArray;
            }
            keeptrack = co.keeptrack;
            m_toyArray = new const Toy * [keeptrack];
            for (int i = 0; i < keeptrack; i++)
            {
                m_toyArray[i] = co.m_toyArray[i];
            }
        }
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& co) noexcept
    {
        keeptrack = co.keeptrack;
        m_toyArray = new const Toy * [keeptrack];
        for (int i = 0; i < keeptrack; i++)
        {
            m_toyArray[i] = co.m_toyArray[i];
            co.m_toyArray[i] = nullptr;
        }
        delete[] co.m_toyArray;
        co.m_toyArray = nullptr;
        co.keeptrack = 0;
    }

    void ConfirmOrder::operator=(ConfirmOrder&& co) noexcept
    {
        if (this != &co)
        {
            if (keeptrack)
            {
                for (int i = 0; i < keeptrack; i++)
                {
                    m_toyArray[i] = nullptr;
                }
                delete[] m_toyArray;
            }
            keeptrack = co.keeptrack;
            m_toyArray = new const Toy * [keeptrack];
            for (int i = 0; i < keeptrack; i++)
            {
                m_toyArray[i] = co.m_toyArray[i];
                co.m_toyArray[i] = nullptr;
            }
            delete[] co.m_toyArray;
            co.m_toyArray = nullptr;
            co.keeptrack = 0;
        }
    }
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
    {
        bool outArray = true;
        for (int i = 0; i < keeptrack; i++)
        {
            if (&toy == m_toyArray[i])
            {
                outArray = false;
            }
        }
        if (outArray)
        {
            
            keeptrack += 1;
            const Toy** temp = new const Toy * [keeptrack];
            for (int i = 0; i < keeptrack - 1; i++)
            {
                temp[i] = m_toyArray[i];
                m_toyArray[i] = nullptr;
            }
            temp[keeptrack - 1] = &toy;
            delete[] m_toyArray;
            
            m_toyArray = temp;
            temp = nullptr;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
    {
        bool outArray = true;
        for (int i = 0; i < keeptrack; i++)
        {
            if (&toy == m_toyArray[i])
            {
                outArray = false;
                m_toyArray[i] = nullptr;
            }
        }
        if (!outArray)
        {
            
            keeptrack -= 1;
            int track{};
            const Toy** temp = new const Toy * [keeptrack];
            for (int i = 0; i < keeptrack + 1; i++)
            {
                if (m_toyArray[i] != nullptr)
                {
                    temp[track++] = m_toyArray[i];
                    m_toyArray[i] = nullptr;
                }
            }
            delete[] m_toyArray;
            
            m_toyArray = temp;
            temp = nullptr;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& co)
    {
        ostr << "--------------------------" << std::endl;
        ostr << "Confirmations to Send" << std::endl;
        ostr << "--------------------------" << std::endl;
        if (!co.keeptrack)
        {
            ostr << "There are no confirmations to send!" << std::endl;
        }
        else
        {
            for (int i = 0; i < co.keeptrack; i++)
            {
                ostr << *co.m_toyArray[i];
            }
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    ConfirmOrder::~ConfirmOrder()
    {
        for (int i = 0; i < keeptrack; i++)
        {
            m_toyArray[i] = nullptr;
        }
        delete[] m_toyArray;
        m_toyArray = nullptr;
    }
}