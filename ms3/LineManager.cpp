/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 04 - 06

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/

#include <iostream>         
#include <fstream>       
#include <string>            
#include <sstream>           
#include "LineManager.h"    
#include "Workstation.h"    

using namespace std;        // Using the standard namespace

namespace seneca
{
    // Constructor definition for the LineManager class
    LineManager::LineManager(const string &file, const vector<Workstation *> &stations)
    {
        ifstream f;   // Creating an input file stream object
        f.open(file);  
        if (f.is_open())  
        {
            string line, token1, token2;
            vector<string> ones, twos;
            while (getline(f, line))   // Reading each line from the file
            {
                stringstream ss(line);   // Creating a stringstream object from the line
                getline(ss, token1, '|');   
                getline(ss, token2);   
                Workstation *ws = get_ws(token1, stations);  
                m_activeLine.push_back(ws);   
                ones.push_back(token1);   
                if (token1.compare(token2) != 0)
                { // real token2
                    ws->setNextStation(get_ws(token2, stations));   // Setting the next station for the workstation
                    twos.push_back(token2);   // Storing the second token
                }
                else
                {
                    twos.push_back("");   // Storing an empty string if token1 and token2 are same
                }
            }
            f.close();   // Closing the file
            int i = 0;
            int first = 0;
            // walk to first
            while (i != -1)
            {
                first = i;
                i = findNext(twos, ones[first]);   // Finding the next index based on the twos and ones vectors
            }
            m_firstStation = get_ws(ones[first], stations);   // Setting the first station in the active line
            m_cntCustomerOrder = g_pending.size();  
        }
        else
        {
            throw string("Failed to open file: " + file + "\n");   // Throwing an exception if file opening fails
        }
    }

    // Definition of the get_ws function for the LineManager class
    Workstation *LineManager::get_ws(string token, const vector<Workstation *> &stations)
    {
        for (Workstation *ws : stations)
        {
            if (ws->getItemName() == token)
            {
                return ws;   // Returning the workstation object if token matches
            }
        }
        return NULL;   
    }

    // Definition of the findNext function for the LineManager class
    int LineManager::findNext(vector<string> vec, string token)
    {
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i].compare(token) == 0)
            {
                return i;   // Returning the index if token matches
            }
        }
        return -1;   // Returning -1 if token doesn't match any element in the vector
    }

    // Definition of the reorderStations function for the LineManager class
    void LineManager::reorderStations()
    {
        m_activeLine.clear();   // Clearing the active line
        Workstation *next = m_firstStation;

        while (next)
        {
            m_activeLine.push_back(next);   // Adding each workstation to the active line
            next = next->getNextStation();   // Getting the next station
        }
    }

    // Definition of the run function for the LineManager class
    bool LineManager::run(std::ostream &os)
    {
        static size_t count = 0u;
        os << "Line Manager Iteration: " << ++count << endl;   // Printing the iteration count

        if (!g_pending.empty())
        {
            *m_activeLine.front() += move(g_pending.front());   // Moving the pending order to the front workstation
            g_pending.pop_front();   // Removing the order from the pending deque
        }

        for (auto ws : m_activeLine)
        {
            ws->fill(os);   // Filling items at each workstation
        }

        for (auto ws : m_activeLine)
        {
            ws->attemptToMoveOrder();   // Attempting to move orders at each workstation
        }

        return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();   // Returning true if all orders are completed or incomplete
    }

    // Definition of the display function for the LineManager class
    void LineManager::display(std::ostream &os) const
    { 
        for (auto ws : m_activeLine)
        {
            ws->display(os);   // Displaying information about each workstation
        }
    }
} 
