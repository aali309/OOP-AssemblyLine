//  Atif Hammud Ali
//  LineManager.cpp
//  MS3
//  116743196
//  Created by atif on 11/24/20.
//  aali309@myseneca.ca
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "Utilities.h"
#include "LineManager.h"
using namespace std;

size_t LineManager::cnt = 1;

LineManager::LineManager(const string& file, vector<Workstation*>& stations, vector<CustomerOrder>& orders) {
    Utilities myUtil;

    ifstream ifs(file);
    if (!ifs.is_open()) {
        throw string("ERROR:  Failed to open the file [") + file + "].";
    }

    string record = "";
    string CurrentStation = "";
    string NextStation = "";
    size_t next_pos;
    bool more;

    //Configure the assembly line
    while (!ifs.eof())
    {
        next_pos = 0;
        std::getline(ifs, record);

        CurrentStation = myUtil.extractToken(record, next_pos, more);
        if (more)
            NextStation = myUtil.extractToken(record, next_pos, more);
        else
            NextStation = "";

        //Loop through the stations vector space and set the information
        for (size_t i = 0; i < stations.size(); i++)
        {
            if (stations[i]->getItemName() == CurrentStation)
            {
                for (size_t j = 0; j < stations.size(); j++)
                {
                    if (stations[j]->getItemName() == NextStation)
                    {
                        stations[i]->setNextStation(*stations[j]);
                        break;
                    }
                }

                m_Station.push_back(stations[i]);
                    
            }
        }
    }
    ifs.close();

    for (size_t x = 0; x < orders.size(); x++)
        ToBeFilled.push_back(std::move(orders[x]));

    
    m_cntCustomerOrder = ToBeFilled.size();

    //Make a local copy of the address to the assembly line stations
    AssemblyLine = stations;
}

bool LineManager::run(ostream& os) {

    if (!ToBeFilled.empty()) {
        *(m_Station[0]) += move(ToBeFilled.front());
        ToBeFilled.pop_front();
    }

    os << "Line Manager Iteration: " << cnt << endl;

    for (auto i : AssemblyLine) {
        i->runProcess(os);
    }

    for (auto i : m_Station) {
        i->moveOrder();
    }

    CustomerOrder tmp{};
    for (auto i : AssemblyLine) {
        if (i->getIfCompleted(tmp)) {
            Completed.push_back(move(tmp));
        }
    }
    cnt++;

    return Completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(ostream& os) const {
    for (auto& order : Completed) {
        order.display(os);
    }
}

void LineManager::displayStations() {
    for (auto station : AssemblyLine) {
        station->display(cout);
    }
}

void LineManager::displayStationsSorted() const {
    for (auto station : m_Station) {
        station->display(cout);
    }
}
