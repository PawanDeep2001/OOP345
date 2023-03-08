// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 07/31/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <exception>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

using namespace std;
namespace sdds {
    size_t CustomerOrder::m_widthField = 0;
    CustomerOrder::CustomerOrder() : m_cntItem(0), m_lstItem(nullptr) {}
    CustomerOrder::CustomerOrder(const string& str) {
        Utilities utilities;
        size_t pos = 0;
        bool more = true;
        m_cntItem = 0;
        m_name = utilities.extractToken(str, pos, more);
        m_product = utilities.extractToken(str, pos, more);
        if (utilities.getFieldWidth() > m_widthField) {
            m_widthField = utilities.getFieldWidth();
        }
        m_lstItem = new Item * [BLOCK_SIZE];
        int i = 0;
        string item_name;
        while (more == true && i < BLOCK_SIZE) {
            m_cntItem++;
            item_name = utilities.extractToken(str, pos, more);
            m_lstItem[i] = new Item(item_name);
            i++;
        }
    }
    CustomerOrder::~CustomerOrder() {
        if (m_lstItem != nullptr) {
            for (unsigned int i = 0; i < m_cntItem; i++) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;
        }
        m_lstItem = nullptr;
    }
    CustomerOrder::CustomerOrder(const CustomerOrder& order) {
        throw exception();
    }
    CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept {
        m_lstItem = order.m_lstItem;
        m_name = order.m_name;
        m_product = order.m_product;
        m_cntItem = order.m_cntItem;

        order.m_name = "";
        order.m_lstItem = nullptr;
        order.m_product = "";
        order.m_cntItem = 0;
    }
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept {
        if (this != &order) {
            for (unsigned int i = 0; i < m_cntItem; i++) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;
            m_lstItem = order.m_lstItem;
            m_name = order.m_name;
            m_product = order.m_product;
            m_cntItem = order.m_cntItem;

            order.m_name = "";
            order.m_lstItem = nullptr;
            order.m_product = "";
            order.m_cntItem = 0;
        }
        return *this;
    }
    bool CustomerOrder::isOrderFilled() const {
        bool ans = true;
        for (unsigned int i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_isFilled == false) {
                ans = false;
            }
        }
        return ans;
    }

    bool CustomerOrder::isItemFilled(const string& itemName) const {
        bool ans = true;
        for (unsigned int i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == itemName) {
                if (m_lstItem[i]->m_isFilled == false) {
                    ans = false;
                }
            }
        }
        return ans;
    }
    void CustomerOrder::fillItem(Station& station, ostream& os) {
        for (unsigned int i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == station.getItemName() && m_lstItem[i]->m_isFilled == false) {
                if (station.getQuantity() > 0) {
                    station.updateQuantity();
                    os << "Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
                    m_lstItem[i]->m_isFilled = true;
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                }
                else {
                    os << "Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
                }
                break;
            }
        }
    }
    void CustomerOrder::display(ostream& os) const {
        os << m_name << " - " << m_product << endl;
        for (unsigned int i = 0; i < m_cntItem; ++i) {
            os << "[" << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << "   - ";
            if (m_lstItem[i]->m_isFilled == true) {
                os << "FILLED\n";
            }
            else {
                os << "TO BE FILLED\n";
            }
        }
    }
}
