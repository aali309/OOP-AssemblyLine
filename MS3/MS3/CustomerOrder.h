//  Atif Hammud Ali
//  CustomerOrder.h
//  MS3
//  116743196
//  Created by atif on 11/24/20.
//  aali309@myseneca.ca

// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include "Station.h"
#include "Utilities.h"
#include <iostream>

struct Item
{
    std::string m_itemName = "";
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;
    
    Item(const std::string& src) : m_itemName(src) {};
};


class CustomerOrder {
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    Item** m_lstItem;
    static size_t m_widthField;
public:
    CustomerOrder(); // default
    CustomerOrder(std::string src); //custom constructor
    CustomerOrder( const CustomerOrder&);
    CustomerOrder& operator=( const CustomerOrder&) = delete;
    CustomerOrder( CustomerOrder&& cust) noexcept;
    CustomerOrder& operator=( CustomerOrder&& cust) noexcept;
    ~CustomerOrder();
    
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
    
};

#endif /* CustomerOrder_h */
