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
#include "Employee.h"
#include "Utilities.h"
#include "Student.h"
#include "Professor.h"
#include <string>
#include <sstream>
namespace seneca {
	Person* buildInstance(std::istream& in) {
		std::string str = "";
		char type = '\0';
		char comma = '\0';

		getline(in, str);
		str.erase(0, str.find_first_not_of(' '));

		std::stringstream strs;
		strs << str;
		strs >> type >> comma;

		if (strs)
		{
			if (type == 'e' || type == 'E')
			{
				return new Employee(strs);
			}
			else if (type == 's' || type == 'S')
			{
				return new Student(strs);
			}
			else if (type == 'p' || type == 'P')
			{
				return new Professor(strs);
			}
		}

		return nullptr;
	}
	bool isDigit(std::string& src) {
		auto begin = src.begin();
		while (begin != src.end() && std::isdigit(*begin)) {
			++begin;
		}
		return !src.empty() && begin == src.end();
	}
	std::string& trim(std::string& src) {
		bool valid = false;

		while (!valid)
		{
			if (src[0] == ' ')
			{
				src.erase(0, src.find_first_not_of(' '));
			}
			else if (src[src.length() - 1] == ' ')
			{
				src.erase(src.find_last_not_of(' ') + 1);
			}
			else
			{
				valid = true;
			}
		}
		return src;
	}

}

