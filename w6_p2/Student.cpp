/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 11

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include "Student.h"
#include <sstream>
#include <iomanip>

namespace seneca
{
    Student::Student(std::istream& in) 
    {
        in.ignore();
        std::getline(in >> std::ws, m_name, ',');
        m_name = m_name.substr(0, m_name.find_last_not_of(" \t") + 1);

        std::string temp;
        std::getline(in >> std::ws, temp, ',');

        if (isdigit(temp[0])) {
            m_age = temp.substr(0, temp.find_last_not_of(" \t")+1);
        }
        else {
            in.ignore(3000, '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }

        std::string tempId;
        char c;

        while (in.get(c) && c != ',' && c != '\n') {
            if (c != ' ') {
                tempId.push_back(c);
            }
        }
        m_id = tempId.substr(0, tempId.find_last_not_of(" \t") + 1);

        if (m_id.empty() || m_id[0] != 'S') {
            in.ignore(3000, '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }

        in >> m_count;

        m_courses = new std::string[m_count];

        in.ignore();
        std::string tempCourseList;
        std::getline(in, tempCourseList, '\n');
        std::istringstream iss(tempCourseList);

        for (size_t i = 0; i < m_count; ++i) {
            std::getline(iss, m_courses[i], ',');
            size_t start = m_courses[i].find_first_not_of(" \t");
            size_t end = m_courses[i].find_last_not_of(" \t");

            if (start != std::string::npos && end != std::string::npos)
                m_courses[i] = m_courses[i].substr(start, end - start + 1);
            else
                m_courses[i] = "";
        }
    }

    Student::~Student()
    {
        delete[] m_courses;
    }

    std::string Student::status() const 
    {
        return "Student";
    }

    std::string Student::name() const
    {
        return m_name;
    }

    std::string Student::id() const{
        return m_id;
    }

    std::string Student::age() const{
        return m_age;
    }

    void Student::display(std::ostream& out) const
    {
        out << "| " << std::left << std::setw(10) << "Student"
            << "| " << std::left << std::setw(10) << id()
            << "| " << std::left << std::setw(20) << name()
            << " | " << std::left << std::setw(3) << age()
            << " |";

        for (size_t i = 0; i < m_count; ++i) {
            out << m_courses[i];
            if (i < m_count - 1) {
                out << ", ";
            }
        }


    }
}
