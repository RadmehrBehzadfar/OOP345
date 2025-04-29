/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Workstation.h"

namespace seneca
{

    class LineManager
    {
    private:
        std::vector<Workstation *> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation *m_firstStation;

        Workstation *get_ws(std::string token, const std::vector<Workstation *> &stations);
        int findNext(std::vector<std::string> vec, std::string token);

    public:
        LineManager(const std::string &file, const std::vector<Workstation *> &stations);

        void reorderStations();

        bool run(std::ostream &os);

        void display(std::ostream &os) const; // inserts information about the current object into stream os
    };
}

#endif // !SDDS_WORKSTATION_H
