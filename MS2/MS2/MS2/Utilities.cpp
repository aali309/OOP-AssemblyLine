//  Atif Hammud Ali
//  Utilities.cpp
//  MS2 adopted from my MS1
//  116743196
//  Created by atif on 11/19/20.
//  aali309@myseneca.ca
//

// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"
using namespace std;

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t newWidth)
{
    m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const
{
    return this->m_widthField;
}

string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
{
    std::string token = str.substr(next_pos);
            size_t position = token.find(m_delimiter);
            if (position == std::string::npos) {
                if(token[token.length() - 1] == '\r'){
                    token = token.substr(0, token.length() - 1);
                }
                more = false;
            } else {
                token = token.substr(0, position);
                if ( getFieldWidth() < token.length() ) {
                    setFieldWidth(token.length());
                }
                next_pos += position +1;
                more = true;
            }
    return token;
}

void Utilities::setDelimiter(char newDelimiter)
{
    m_delimiter = newDelimiter;
}
char Utilities::getDelimiter()
{
    return m_delimiter;
}


