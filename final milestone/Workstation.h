// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 08/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"

namespace sdds {
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;
    class Workstation : public Station {
    public:
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation;
        Workstation(const std::string& str);
        Workstation(const Workstation& ) = delete;
        Workstation(Workstation&& ) = delete;
        Workstation& operator=(Workstation& ) = delete;
        Workstation& operator=(Workstation&& ) = delete;
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station=nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}
#endif 
