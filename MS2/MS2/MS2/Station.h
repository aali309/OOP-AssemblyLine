//  Atif Hammud Ali
//  Station.h
//  MS2 adopted from my MS1
//  116743196
//  Created by atif on 19/11/20.
//  aali309@myseneca.ca
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include <iostream>
#include <iomanip>

class Station{
    int stationId;
    std::string itemName;
    std::string stationDesc;
    unsigned int sNumb;
    unsigned int qtyLeft;
    static unsigned int m_widthField;
    static unsigned int id_generator;
public:
    Station(const std::string& src);
    const std::string& getItemName() const;
    unsigned int getNextSerialNumber();
    unsigned int getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
    
};
#endif /* Station_h */
