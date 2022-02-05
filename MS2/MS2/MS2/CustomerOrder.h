//  Atif Hammud Ali
//  CustomerOrder.h
//  MS2
//  116743196
//  Created by atif on 11/19/20.
//  aali309@myseneca.ca

// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Station.h"

struct Item
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
    std::string m_name{ "" };
    std::string m_product{ "" };
    unsigned int m_cntItem{ 0 };
    Item** m_lstItem{nullptr};
    static size_t m_widthField;
public:
    CustomerOrder() {};
    CustomerOrder(std::string&);
    CustomerOrder(CustomerOrder&);
    CustomerOrder& operator=(CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&& order) noexcept;
    CustomerOrder& operator=(CustomerOrder&& order) noexcept;
    ~CustomerOrder();

    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
};

#endif
