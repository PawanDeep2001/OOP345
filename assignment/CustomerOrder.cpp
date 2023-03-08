#include <exception>
#include <iostream>
#include <iomanip>

#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

#define BLOCK_SIZE 20 // initial memory of the Item **

using namespace sdds;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(const std::string& str) : m_cntItem(0) {
    Utilities util;
    size_t pos = 0u;
    bool more = true;

    m_name = util.extractToken(str, pos, more);
    m_product = util.extractToken(str, pos, more);

    m_widthField = std::max(m_widthField, util.m_widthField);

    // allocate memory
    m_lstItem = new Item* [BLOCK_SIZE];

    int i = 0;
    std::string item_name;
    while (more && i < BLOCK_SIZE) {
        m_cntItem += 1;
        item_name = util.extractToken(str, pos, more);
        m_lstItem[i] = new Item(item_name);
        i++;
    }
}

CustomerOrder::~CustomerOrder() {
    // deallocate memory
    if (m_lstItem != nullptr) {
        for (unsigned int i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }

        delete[] m_lstItem;
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder& order) {
    throw std::exception();
}

// move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
    // move the data
    m_lstItem = order.m_lstItem;
    m_name = order.m_name;
    m_product = order.m_product;
    m_cntItem = order.m_cntItem;

    // destroy the source destination
    order.m_name = "";
    order.m_lstItem = nullptr;
    order.m_product = "";
    order.m_cntItem = 0;
}

// move operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
    if (this != &order) {
        // free up list item memory
        for (unsigned int i = 0; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;

        // move the data
        m_lstItem = order.m_lstItem;
        m_name = order.m_name;
        m_product = order.m_product;
        m_cntItem = order.m_cntItem;

        // destroy the source destination
        order.m_name = "";
        order.m_lstItem = nullptr;
        order.m_product = "";
        order.m_cntItem = 0;
    }
    return *this;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
    for (unsigned int i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == station.getItemName()) {
            if (!m_lstItem[i]->m_isFilled) {
                if (station.getQuantity() > 0) {
                    station.updateQuantity();
                    os << "    Filled " << m_name << ", " << m_product << " " << "[" << station.getItemName() << "]"
                       << std::endl;
                    m_lstItem[i]->m_isFilled = true;
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    break;
                } else {
                    os << "    Unable to fill " << m_name << ", " << m_product << " " << "[" << station.getItemName()
                       << "]"
                       << std::endl;
                }
            }
        }
    }
}

bool CustomerOrder::isOrderFilled() const {
    bool isFilled = true;
    for (unsigned int i = 0; i < m_cntItem; i++) {
        isFilled = isFilled && m_lstItem[i]->m_isFilled;
    }

    return isFilled;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
    bool is_filled = true;
    for (unsigned int i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == itemName) {
            is_filled = is_filled && m_lstItem[i]->m_isFilled;
        }
    }

    return is_filled;
}

void CustomerOrder::display(std::ostream& os) const {
    // print header
    os << m_name << " - " << m_product << std::endl;

    // loop through the items
    Item* item;
    for (unsigned int i = 0; i < m_cntItem; ++i) {
        item = m_lstItem[i];
        os << "[" << std::setfill('0') << std::setw(6) << item->m_serialNumber << "] ";
        os.fill(' ');
        os.setf(std::ios::left);
        os << std::setw(m_widthField) << item->m_itemName << " - ";
        if (item->m_isFilled) {
            os << "FILLED\n";
        } else {
            os << "TO BE FILLED\n";
        }

        os.unsetf(std::ios::left);
    }
}


