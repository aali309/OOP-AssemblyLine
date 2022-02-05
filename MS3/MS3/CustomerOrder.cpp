//  Atif Hammud Ali
//  CustomerOrder.cpp
//  MS3
//  116743196
//  Created by atif on 11/24/20.
//  aali309@ my seneca.ca

// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField;

CustomerOrder::CustomerOrder() {
    m_name = "";
    m_product = "";
    m_cntItem = 0;
    m_lstItem = nullptr;
    
}

CustomerOrder::CustomerOrder(std::string src) {
    Utilities utilities;
    size_t position = 0;
    bool more = false;
    std::vector<Item*> v_item;
    
    m_name = utilities.extractToken(src, position, more);
    m_product = utilities.extractToken(src, position, more);
    
    while(more) {
        v_item.push_back(new Item(utilities.extractToken(src, position, more)));
    }
    
    m_cntItem = v_item.size();
    m_lstItem = new Item* [m_cntItem];
    
    for (size_t i = 0; i < m_cntItem; i++) {
        m_lstItem[i] = std::move(v_item[i]);
    }
    
    if (m_widthField < utilities.getFieldWidth()) {
        m_widthField = utilities.getFieldWidth();
    }

}

CustomerOrder::CustomerOrder(const CustomerOrder&) {
    throw std::string("No copy allowed");
}

CustomerOrder::CustomerOrder( CustomerOrder &&cust) noexcept {
    *this = std::move(cust);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder &&cust) noexcept {
    
    if(this != &cust) {
        
        m_name = cust.m_name;
        m_product = cust.m_product;
        m_cntItem = cust.m_cntItem;
        m_lstItem = cust.m_lstItem;
        cust.m_lstItem = nullptr;
        cust.m_product = '\0';
        cust.m_cntItem = 0;
        cust.m_name = '\0';
        
    }
    return *this;
}

CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
        m_lstItem[i] = nullptr;
    }
    delete [] m_lstItem;
    m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const {
    size_t size = 0;
    for (size_t i = 0; i < m_cntItem; i++) {
        if(m_lstItem[i]->m_isFilled) {
            size ++;
        }
    }
    
    if (size < m_cntItem) {
        return false;
    } else {
        return true;
    }
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == itemName)
            return m_lstItem[i]->m_isFilled;
    }
    return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    for(size_t i = 0; i < m_cntItem; i++) {
        if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity() > 0) {
            station.getQuantity();
            m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
            m_lstItem[i]->m_isFilled= true;
            station.updateQuantity();
            os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
        }
        if (station.getItemName() == m_lstItem[i]->m_itemName && station.getQuantity() <= 0) {
            os << "Unable to fill" << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
        }
    }
    
}

void CustomerOrder::display(std::ostream &os) const {
    os << m_name << " - " << m_product << std::endl;
    for (size_t i = 0; i < m_cntItem; i++) {
        os << "["
            << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber
            << "] "
            << std::setw(m_widthField) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName
            << " - ";
        
        if (m_lstItem[i]->m_isFilled) {
            os << "FILLED";
        } else {
            os << "MISSING";
        }

        os << std::endl;
    }
    
}
