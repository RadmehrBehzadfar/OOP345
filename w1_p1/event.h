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
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca
{
	extern unsigned int g_sysClock;
	class Event
	{

		char* m_desc;
		unsigned int time;
	public:
		Event();
		Event(const Event& event);
		Event& operator=(const Event& event);
		void display() const;
		void set(const char* arr = nullptr);
		~Event();
	};
}

#endif // SENECA_EVENT_H
