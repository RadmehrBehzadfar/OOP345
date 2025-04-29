/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 18

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/


#ifndef SENECA_SETSUMMABLE_H
#define SENECA_SETSUMMABLE_H

#include <string>
#include "Set.h"

namespace seneca
{
  template<size_t N, typename T>
  class SetSummable : public Set<N, T>
  {
  public:
    T accumulate(const std::string &filter) const {
      T _temp(filter);

      for (auto i = 0u; i < this->size(); ++i) {
        if (_temp.isCompatibleWith(this->get(i)))
          _temp += this->get(i);
      }

      return _temp;
    }
  };
}
#endif // !SENECA_SETSUMMABLE_H
