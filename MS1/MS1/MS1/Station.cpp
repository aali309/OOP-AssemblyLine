//  Atif Hammud Ali
//  Station.cpp
//  MS1
//  116743196
//  Created by atif on 11/11/20.
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
        size_t next_pos = 0;
        bool more = false;
        stationId = ++Station::id_generator;
        if (src.empty()) {
            itemName = "";
            stationDesc = "";
            sNumb = 0;
            qtyLeft = 0;
            
        }
        else {
            itemName = objU.extractToken(src, next_pos, more);
            if (more) {
                sNumb = stoi(objU.extractToken(src, next_pos, more));
            }
            if (more) {
                qtyLeft = stoi(objU.extractToken(src, next_pos, more));
            }
            if (m_widthField < objU.getFieldWidth()) {
                m_widthField = objU.getFieldWidth();
            }
            if (more) {
                stationDesc = objU.extractToken(src, next_pos, more);
            }
            
        }
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


