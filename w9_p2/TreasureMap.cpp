/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 31

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <future>
#include "TreasureMap.h"

namespace seneca
{

    size_t digForTreasure(const std::string& str, char mark)
    {
        size_t cnt = 0;
        for (auto& x : str)
        {
            if (x == mark)
            {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename)
    {
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else
        {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap()
    {
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const
    {
        if (map)
        {
            for (size_t i = 0; i < rows; ++i)
            {
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) 
    {
        // Binary write
        if (map) 
        {
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            std::ofstream f(filename, std::ios::out | std::ios::binary | std::ios::trunc);
            if (f.is_open()) {
                if (f) {
                    // Writing the number of rows.
                    f.write(reinterpret_cast<char*>(&rows), sizeof(rows));
                    // Writing the col size.
                    f.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
                    // Writing every row.
                    for (size_t i = 0; i < rows; i++) 
                    {

                        f.write(&map[i][0], map[i].size());

                    };
                    f.close();
                };
                // END TODO
            }
            else
            {
                throw "Cannot open the file.";
            };
        }
        else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename)
    {
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
        std::ifstream f(filename, std::ios::in | std::ios::binary);
        if (f.is_open())
        {
            // Reading the number of rows.
            f.read(reinterpret_cast<char*>(&rows), sizeof(size_t));
            // Reading the colsize
            f.read(reinterpret_cast<char*>(&colSize), sizeof(size_t));
            // Allocating the memory
            map = new std::string[rows];

            for (size_t i = 0; i < rows; i++) 
            {
                map[i].resize(colSize);
                f.read(&map[i][0], colSize);
            };
            f.close();
        // END TODO
        }
        else 
        {
            throw "File cannot be opened.";
        };
    }

    void TreasureMap::clear()
    {
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        std::string string1 = map[0] + map[1] + map[2];
        std::string string2 = map[3] + map[4] + map[5];
        std::string string3 = map[6] + map[7] + map[8];
        std::string string4 = map[9] + map[10] + map[11];

        auto f = bind(digForTreasure, std::placeholders::_1, mark);

        std::packaged_task<size_t(std::string)> task1(f);
        std::packaged_task<size_t(std::string)> task2(f);
        std::packaged_task<size_t(std::string)> task3(f);
        std::packaged_task<size_t(std::string)> task4(f);

        std::future<size_t> future1 = task1.get_future();
        std::future<size_t> future2 = task2.get_future();
        std::future<size_t> future3 = task3.get_future();
        std::future<size_t> future4 = task4.get_future();

        std::thread thread1(std::move(task1), string1);
        std::thread thread2(std::move(task2), string2);
        std::thread thread3(std::move(task3), string3);
        std::thread thread4(std::move(task4), string4);

        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();

        count = future1.get() + future2.get() + future3.get() + future4.get();

        return count;
    }
}