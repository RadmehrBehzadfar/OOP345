/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_SET_H_
#define SENECA_SET_H_

#include <iostream>

namespace seneca
{
  template <size_t N, typename T>
  class Set
  {
    size_t m_idx { 0u };
    T m_array[N] {};

  public:
    // returns the current number of elements
    size_t size() const { return m_idx; }

    // returns a reference to the element at index idx of the statically allocated array
    const T &get(size_t idx) const { return m_array[idx]; }

    void operator+=(const T &item) {
      // check the collection has capacity
      if (m_idx < N)
        m_array[m_idx++] = item; // adds a copy of item to the collection
    }
  };
}
#endif // !SENECA_SET_H_