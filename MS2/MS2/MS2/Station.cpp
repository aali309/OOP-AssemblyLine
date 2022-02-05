//  Atif Hammud Ali
//  Station.cpp
//  MS2 adopted from my MS1
//  116743196
//  Created by atif on 11/19/20.
//  aali309@myseneca.ca
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include "Station.h"
using namespace std;

unsigned int Station::m_widthField = 0;
unsigned int Station::id_generator = 0;

Station::Station(const std::string& src)
{
    Utilities objU;
            bool more;
            size_t nextPOS = 0;
            if (nextPOS != string::npos) {
                itemName= objU.extractToken(src, nextPOS, more);
    string serial = objU.extractToken(src, nextPOS, more);
                sNumb = stoi(serial);
                
    string quantity = objU.extractToken(src, nextPOS, more);
                qtyLeft = stoi(quantity);
            }
            
            if (m_widthField < objU.getFieldWidth()) {
                Station::m_widthField = objU.getFieldWidth();
            }
            if (nextPOS != string::npos) {
                stationDesc = objU.extractToken(src, nextPOS, more);
            }
            stationId = ++id_generator;
        }

const string& Station::getItemName() const
{
    return this->itemName;
}

unsigned int Station::getNextSerialNumber()
{
    return sNumb++;
}

unsigned int Station::getQuantity() const
{
    return this->qtyLeft;
}

void Station::updateQuantity()
{
   if (this->qtyLeft > 0)
   {
       --this->qtyLeft;
   }
   else{
       throw "No quantity!";
   }
}

void Station::display(ostream& os, bool full) const
{
        os << '[' << setw(3) << setfill('0') << right << stationId
                 << "] Item: " << setw(m_widthField) << setfill(' ') << left << itemName
                 << " [" << setw(6) << setfill('0') << right << sNumb << "]" << setfill(' ') << left;
    
    if(full){
        os << " Quantity: " << setw(m_widthField) << qtyLeft
            << " Description: " << stationDesc;
    }
        os << endl;
}

