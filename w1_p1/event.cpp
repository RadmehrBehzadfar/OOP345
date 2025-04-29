/*/////////////////////////////////////////////////////////////////////////
						Workshop 1 Part 2
Full Name  : Radmehr Behzadfar
Student ID#: 148786221
Email      : rbehzadfar@myseneca.ca
Section    : NRA
Date : 2024-01-22

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"

namespace seneca
{
	unsigned int g_sysClock = 0;
	Event::Event()
	{
		m_desc = nullptr;
		time = 0;
	}

	Event::Event(const Event& event)
	{
		if (event.m_desc)
		{
			m_desc = new char[strlen(event.m_desc) + 1];
			strncpy(m_desc, event.m_desc, strlen(event.m_desc) + 1);
			time = event.time;
		}
		else
		{
			m_desc = nullptr;
			time = 0;
		}
	}

	Event& Event::operator=(const Event& event)
	{
		if (this != &event)
		{
			if (event.m_desc)
			{
				delete[] m_desc;
				m_desc = new char[strlen(event.m_desc) + 1];
				strncpy(m_desc, event.m_desc, strlen(event.m_desc) + 1);
				time = event.time;
			}
			else
			{
				m_desc = nullptr;
				time = 0;
			}
		}
		return *this;
	}

	void Event::display() const
	{
		static unsigned int counter = 0;
		std::cout << std::setw(2) << std::setfill(' ') << ++counter << ". ";
		if (m_desc)
		{
			int MM = time / 60;
			int SS = time % 60;
			int HH = MM / 60;
			MM = MM % 60;
			std::cout << std::setw(2) << std::setfill('0') << HH << ":"
				<< std::setw(2) << std::setfill('0') << MM << ":"
				<< std::setw(2) << std::setfill('0') << SS << " => " << m_desc << std::endl;
		}
		else
			std::cout << "| No Event |" << std::endl;
	}

	void Event::set(const char* arr)
	{
		time = seneca::g_sysClock;
		if (arr != nullptr)
		{
			delete[] m_desc;
			m_desc = new char[strlen(arr) + 1];
			strncpy(m_desc, arr, strlen(arr) + 1);
		}
		else
		{
			delete[] m_desc;
			m_desc = nullptr;
		}
	}

	Event::~Event()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}
}