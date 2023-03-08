/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :06/12/2022
*/
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>
namespace sdds {
    class Toy {
        int order_id=0;
        std::string name="";
        int counter=0;
        double price=0;
        double tax = 0.13;
    public:
        Toy();
        Toy(const std::string& t);
        void update(int num);
        friend std::ostream& operator<<(std::ostream& os, const Toy& t);
    };
}
#endif