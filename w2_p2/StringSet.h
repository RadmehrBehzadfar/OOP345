/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 01 - 29

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <iostream>
#include <string>

namespace seneca
{
  class StringSet
  {
    size_t s_CurRecord { 0u };
    std::string *s_str { nullptr };

  public:
    StringSet() {}
    StringSet(const char *_filename);           // 1-argument constructor
    ~StringSet();

    StringSet(const StringSet &src);            // copy constructor
    StringSet &operator=(const StringSet &src); // copy assignment
    StringSet(StringSet &&src);                 // move constructor
    StringSet &operator=(StringSet &&src);      // move assignment

    size_t size() const;
    std::string operator[](size_t) const;
  };
}
#endif //! SENECA_STRINGSET_H