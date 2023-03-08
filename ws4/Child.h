/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :06/12/2022
*/
#ifndef SDDS_CHILD_H_
#define SDDS_CHILD_H_
#include <iostream>
#include "Toy.h"
namespace sdds {
    class Child{
        std::string name="";
        int age=0;
        const Toy** toys=nullptr;
        size_t count=0;
    public:
        Child();
        Child(std::string lName, int lAge, const Toy* aToys[], size_t lCount);
        Child(const Child& c);
        Child& operator=(const Child& c);
        Child(Child&& c) noexcept;
        Child& operator=(Child&& c) noexcept;
        size_t size() const;
        ~Child();
        friend std::ostream& operator<<(std::ostream& os, const Child& c);
    };
}
#endif