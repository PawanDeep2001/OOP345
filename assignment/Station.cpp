#include <iomanip>

#include "Station.h"
#include "Utilities.h"

using namespace sdds;

size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station(const std::string& str) : id(0), serialNumber(0), quantity(0) {
    Utilities util;

    size_t pos = 0u;
    bool more = true;

    id = ++id_generator;
    name = util.extractToken(str, pos, more);

    // get m_ width
    m_widthField = std::max(m_widthField, util.m_widthField);

    serialNumber = std::stoi(util.extractToken(str, pos, more));
    quantity = std::stoi(util.extractToken(str, pos, more));
    description = util.extractToken(str, pos, more);

}

const std::string& Station::getItemName() const {
    return name;
}

size_t Station::getNextSerialNumber() {
    return serialNumber++;
}

size_t Station::getQuantity() const {
    return quantity;
}

void Station::updateQuantity() {
    if (quantity - 1 < 0) throw -1;
    quantity -= 1;
}

void Station::display(std::ostream& os, bool full) const {
    std::string delim = " | ";

    os << std::setfill('0') << std::setw(3) << id << delim;
    os << std::setfill(' ');
    os << std::setiosflags(std::ios::left) << std::setw((int) m_widthField) << name << delim;
    os << std::setfill('0') << std::setiosflags(std::ios::right) << std::setw(6) << serialNumber << delim;

    if (!full) {
        os << std::endl;
        os.unsetf(std::ios::right);
        os.unsetf(std::ios::left);
        return;
    }
    os.fill(' ');
    os << std::setw(4) << quantity << delim;
    os << description << std::endl;

    os.unsetf(std::ios::right);
    os.unsetf(std::ios::left);
}




