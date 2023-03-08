/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :06/12/2022
*/
#ifndef SDDS_CONFIRMORDER_H_
#define SDDS_CONFIRMORDER_H_
#include <iostream>
#include "Toy.h"
namespace sdds{
    class ConfirmOrder{
        const Toy** toy=nullptr;
        size_t count=0;
    public:
        ConfirmOrder();
        ConfirmOrder(const ConfirmOrder& c);
        ConfirmOrder& operator=(const ConfirmOrder& c);
        ConfirmOrder& operator+=(const Toy& t);
        ConfirmOrder& operator-=(const Toy& t);
        ConfirmOrder(ConfirmOrder&& c) noexcept;
        ConfirmOrder& operator=(ConfirmOrder&& c) noexcept;
        ~ConfirmOrder();
        friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& c);
    };
}
#endif