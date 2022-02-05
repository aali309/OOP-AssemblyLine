//  Atif Hammud Ali
//  LineManager.h
//  MS3
//  116743196
//  Created by atif on 11/24/20.
//  aali309@myseneca.ca
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager {
    std::vector<Workstation*> AssemblyLine{};
    std::deque<CustomerOrder> ToBeFilled{};
    std::deque<CustomerOrder> Completed{};
    unsigned int m_cntCustomerOrder{ 0 };
    static size_t cnt;
    std::vector<Workstation*> m_Station{};
public:
    LineManager(const std::string& file, std::vector<Workstation*>& stations, std::vector<CustomerOrder>& orders);
    bool run(std::ostream& os);
    void displayCompletedOrders(std::ostream& os) const;
    void displayStations();
    void displayStationsSorted() const;

};

#endif /* LineManager_h */
