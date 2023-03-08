// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 08/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"
namespace sdds {
    class LineManager {
        std::vector<Workstation*> m_activeLine{};
        size_t m_cntCustomerOrder{};
        Workstation* m_firstStation{};
    public:
        LineManager(const std::string& file, std::vector<Workstation*> stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif 
