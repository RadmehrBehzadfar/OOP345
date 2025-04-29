/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_PAIRSUMMABLE_H
#define SENECA_PAIRSUMMABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

namespace seneca
{
  template<typename V, typename K>
  class PairSummable : public Pair<V, K>
  {
    static V initial;
    static size_t m_fieldWidth;

  public:
    PairSummable() : Pair<V, K>() {}

    PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
      if (key.size() > m_fieldWidth)
        m_fieldWidth = key.size();
    }

    bool isCompatibleWith(const PairSummable<V, K> &b) const { return this->key() == b.key(); }

    PairSummable& operator+=(const PairSummable& src) {
      // if condition met, adds the value of the parameter object to the value of the current object
      if (isCompatibleWith(src))
        *this = PairSummable(this->key(), this->value() + src.value());

      return *this;
    }

    void display(std::ostream& os) const override {
      os << std::left << std::setw(m_fieldWidth);
      Pair<V, K>::display(os);
      os << std::right;
    }
  };

  template<>
  PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src) {
    if (this->value() == "")
      *this = PairSummable(this->key(), src.value());
    else
      *this = PairSummable(this->key(), this->value() + ", " + src.value());

    return *this;
  }

  // uniform initialization
  template<typename V, typename K>
  V PairSummable<V, K>::initial {};

  template<typename V, typename K>
  size_t PairSummable<V, K>::m_fieldWidth { 0u };
}
#endif // !SENECA_PAIRSUMMABLE_H