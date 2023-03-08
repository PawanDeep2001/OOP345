// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 07/31/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "Station.h"
using namespace std;
namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;
    Station::Station(const string& str) {
        Utilities utilities;
        size_t pos = 0;
        bool more=true;
        id = id_generator+1;
        id_generator++;
        name = utilities.extractToken(str, pos, more);
        serNum = stoi(utilities.extractToken(str, pos, more));
        itemStock = stoi(utilities.extractToken(str, pos, more));
        if (utilities.getFieldWidth()> m_widthField){
            m_widthField = utilities.getFieldWidth();
        }
        desc = utilities.extractToken(str, pos, more);
    }
    const string& Station::getItemName() const {
        return name;
    }
    size_t Station::getNextSerialNumber() {
        return serNum++;
    }
    size_t Station::getQuantity() const {
        return itemStock;
    }
    void Station::updateQuantity() {
        if (itemStock > 0) {
            itemStock -= 1;
        }
    }
    void Station::display(ostream& os, bool full) const {
        if (full==false) {
            os << right << setfill('0') << setw(3) << id << " | " << left << setw(m_widthField) << setfill(' ')  << name << "  | " << right << setfill('0') << setw(6) << serNum << " | " << endl;
        }
        else {
            os << right << setfill('0') << setw(3) << id << " | " << left << setw(m_widthField) << setfill(' ')  << name << "  | " << right << setfill('0') << setw(6) << serNum << " | " << right << setw(4) << setfill(' ') << itemStock << " | "<< left << desc << endl;
        }
    }
}