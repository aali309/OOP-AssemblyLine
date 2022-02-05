//  Atif Hammud Ali
//  Workstation.h
//  MS3
//  116743196
//  Created by atif on 11/24/20.
//  aali309@myseneca.ca
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"

class Workstation :public Station {
    std::deque<CustomerOrder> m_orders{};
    Workstation* m_pNextStation{};

public:
    Workstation(const std::string& src);
    Workstation(const Workstation&) = delete;
    Workstation(const Workstation&&) = delete;
    Workstation& operator=(Workstation&) = delete;
    Workstation& operator=(const Workstation&&) = delete;

    void runProcess(std::ostream&);
    bool moveOrder();
    void setNextStation(Workstation& station);
    const Workstation* getNextStation() const;
    bool getIfCompleted(CustomerOrder& order);
    void display(std::ostream&);
    Workstation& operator+=(CustomerOrder&& order);

};
#endif /* Workstation_h */
