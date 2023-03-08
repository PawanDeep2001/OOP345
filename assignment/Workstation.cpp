#include <iostream>
#include <string>
#include <deque>

#include "Workstation.h"
#include "CustomerOrder.h"

using namespace sdds;

std::deque<CustomerOrder> sdds::g_pending;
std::deque<CustomerOrder> sdds::g_completed;
std::deque<CustomerOrder> sdds::g_incomplete;


Workstation::Workstation(const std::string& str) : Station(str), m_pNextStation(nullptr) {}

void Workstation::fill(std::ostream& os) {
    if (!m_orders.empty()) {
        // attempt to fill the item
        if (!m_orders.front().isItemFilled(this->getItemName())) {
            m_orders.front().fillItem(*this, os);
        }
    }
}

bool Workstation::attemptToMoveOrder() {
    bool ret = false;
    if (!m_orders.empty()) {
        if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
            if (m_pNextStation != nullptr) {
                *m_pNextStation += std::move(m_orders.front());
            } else {
                if (m_orders.front().isOrderFilled()) {
                    g_completed.push_back(std::move(m_orders.front()));
                } else {
                    g_incomplete.push_back(std::move(m_orders.front()));
                }
            }
            m_orders.pop_front();
            ret = true;
        }
    }

    return ret;
}

void Workstation::setNextStation(Workstation* station) {
    m_pNextStation = station;
}

Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}

void Workstation::display(std::ostream& os) const {
    os << getItemName() << " --> ";
    os << ((m_pNextStation != nullptr) ? m_pNextStation->getItemName() : "End of Line") << std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
    m_orders.push_back(std::move(newOrder));
    return *this;
}


