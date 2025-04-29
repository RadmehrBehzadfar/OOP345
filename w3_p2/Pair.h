/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_PAIR_H_
#define SENECA_PAIR_H_

#include <iostream>

namespace seneca
{
  template<typename V, typename K>
  class Pair
  {
    K m_key;
    V m_value;

  public:
    Pair() : m_key(), m_value() {}
    Pair(const K &key, const V &value) : m_key(key), m_value(value) {}
    const V &value() const { return m_value; }
    const K &key() const { return m_key; }

    virtual void display(std::ostream &os) const {
      os << key() << " : " << value() << std::endl;
    }
  };

  template<typename V, typename K>
  std::ostream &operator<<(std::ostream &os, const Pair<V, K> &pair) {
    pair.display(os);
    return os;
  }
}
#endif  // !SENECA_PAIR_H_