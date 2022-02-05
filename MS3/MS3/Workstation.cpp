//  Atif Hammud Ali
//  Workstation.cpp
//  MS3
//  116743196
//  Created by atif on 11/24/20.
//  aali309@myseneca.ca
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include <sstream>
#include "Utilities.h"
#include "Workstation.h"
using namespace std;

Workstation::Workstation(const std::string& str) : Station(str) {
        m_pNextStation = nullptr; 
    }

void Workstation::runProcess(ostream& os) {
    if (!m_orders.empty()) {
        m_orders.front().fillItem(*this, os);
    }
}

bool Workstation::moveOrder() {
    bool flag = false;
    if (m_orders.empty()) {
        return flag;
    }
    
    flag = m_orders.front().isItemFilled(getItemName()) && m_pNextStation;
    if (flag) {
        *m_pNextStation += move(m_orders.front());
        m_orders.pop_front();
    }
    
    return flag;
}

void Workstation::setNextStation(Workstation& station) {
    m_pNextStation = static_cast<Workstation*>(&station);
}

const Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
    bool flag = false;
    if (m_orders.empty()) {
        return flag;
    }
    flag = m_orders.front().isOrderFilled();
    if (flag) {
        order = move(m_orders.front());
        m_orders.pop_front();
    }
    return flag;
}

void Workstation::display(ostream& os) {
    if (!m_pNextStation)
        os << (*this).getItemName() << " --> END OF LINE" << endl;
    else
        os << (*this).getItemName() << " --> " << m_pNextStation->getItemName() << endl;
    
}

Workstation& Workstation::operator+=(CustomerOrder&& order) {
    m_orders.push_back(move(order));
    return *this;
}
