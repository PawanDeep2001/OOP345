#ifndef OOP_PROJECT_STATION_H

#include <string>
#include "Utilities.h"

namespace sdds {
    class Station {
      public:
        int id;
        std::string name;
        std::string description;
        size_t serialNumber;
        size_t quantity;

        static size_t m_widthField;
        static size_t id_generator;

        Station(const std::string& str);

        const std::string& getItemName() const;

        size_t getNextSerialNumber();

        size_t getQuantity() const;

        void updateQuantity();

        void display(std::ostream& os, bool full) const;
    };
}
#define OOP_PROJECT_STATION_H

#endif
