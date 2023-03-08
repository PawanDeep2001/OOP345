// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 08/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
namespace sdds {
    class Station {
        int id;
        std::string name;
        std::string desc;
        unsigned int serNum;
        unsigned int itemStock;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string& str);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif