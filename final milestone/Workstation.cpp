// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 08/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <deque>
#include "Workstation.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
    deque<CustomerOrder> g_pending;
    deque<CustomerOrder> g_completed;
    deque<CustomerOrder> g_incomplete;

    Workstation::Workstation(const string& str) : Station(str), m_pNextStation(nullptr) {}

    void Workstation::fill(ostream& os) {
        if (m_orders.empty()==false) {
            if (!m_orders.front().isItemFilled(this->getItemName())) {
                m_orders.front().fillItem(*this, os);
            }
        }
    }

    bool Workstation::attemptToMoveOrder() {
        bool ret = false;
        if (m_orders.empty()==false) {
            if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
                if (m_pNextStation != nullptr) {
                    *m_pNextStation += move(m_orders.front());
                }
                else {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(move(m_orders.front()));
                    }
                    else {
                        g_incomplete.push_back(move(m_orders.front()));
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

    void Workstation::display(ostream& os) const {
        os << getItemName() << " --> ";
        if (m_pNextStation != nullptr) {
            os << m_pNextStation->getItemName() << endl;
        }
        else {
            os << "End of Line" << endl;
        }
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(move(newOrder));
        return *this;
    }
}

