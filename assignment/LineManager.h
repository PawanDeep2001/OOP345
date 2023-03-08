
#ifndef OOP_PROJECT_LINEMANAGER_H

#include <vector>

#include "Workstation.h"

namespace sdds {
    class LineManager {
      private:
        std::vector<Workstation*> m_active_line;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;
        size_t run_iteration_counter;

      public:
        LineManager(const std::string& file, std::vector<Workstation*> stations);

        void reorderStations();

        bool run(std::ostream& os);

        void display(std::ostream& os) const;

    };
}
#define OOP_PROJECT_LINEMANAGER_H

#endif //OOP_PROJECT_LINEMANAGER_H
