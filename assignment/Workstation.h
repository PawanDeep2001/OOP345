#ifndef OOP_PROJECT_WORKSTATION_H

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

        void fill(std::ostream& os);

        bool attemptToMoveOrder();

        void setNextStation(Workstation* station);

        Workstation* getNextStation() const;

        void display(std::ostream& os) const;

        Workstation& operator+=(CustomerOrder&& newOrder);

    };
}
#define OOP_PROJECT_WORKSTATION_H

#endif //OOP_PROJECT_WORKSTATION_H
