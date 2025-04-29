/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 17

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace seneca
{
  struct Song {
    std::string m_artist {};
    std::string m_title  {};
    std::string m_album  {};
    std::string m_year   {};
    double      m_price  {};
    size_t      m_length {};
  };

  class SongCollection
  {
    std::vector<Song> m_song;
    size_t            m_total { 0u };

  public:
    SongCollection(const char *src);

    void display(std::ostream &out) const;

    void sort(std::string src);

    void cleanAlbum();

    bool inCollection(std::string src) const;

    std::list<Song> getSongsForArtist(std::string src) const;
  };
  std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SENECA_SONGCOLLECTION_H