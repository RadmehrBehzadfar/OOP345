/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "Person.h"
namespace seneca {
	Person* buildInstance(std::istream& in);
	bool isDigit(std::string& src);
	std::string& trim(std::string& src);
}
#endif //! SENECA_UTILITIES_H