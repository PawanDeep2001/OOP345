/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :06/12/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Child.h"
using namespace std;
namespace sdds {
    Child::Child() {
        ;
    }
    Child::Child(string lName, int lAge, const Toy* aToys[], size_t lCount) {
        count = lCount;
        toys = new const Toy * [count];
        for (size_t i = 0; i < count; ++i) {
            toys[i] = new Toy(*aToys[i]);
        }
        name = lName;
        age = lAge;
    }
    Child::Child(const Child& c) {
        *this = c;
    }
    Child& Child::operator=(const Child& c)  {
        if (this != &c) {
            for (size_t i = 0; i < count; i++) {
                delete toys[i];
            }
            delete[] toys;
            count = c.count;
            toys = new const Toy * [count];
            for (size_t i = 0; i < count; i++) {
                toys[i] = new Toy(*c.toys[i]);
            }
            name = c.name;
            age = c.age;
        }
        return *this;
    }
    Child::Child(Child&& c) noexcept {
        *this = move(c); 
    }
    Child& Child::operator=(Child&& c) noexcept {
        if (this != &c) {
            name = c.name;
            c.name = "";
            age = c.age;
            c.age = 0;
            count = c.count;
            c.count = 0;
            delete[] toys;
            toys = c.toys;
            c.toys = nullptr;
        }
        return *this;
    }
    size_t Child::size() const {
        return count;
    }
    Child::~Child(){
        for (size_t i = 0u; i < count; i++) {
            delete toys[i];
        }
        delete[] toys;
    }
    ostream& operator<<(ostream& os, const Child& c) {
        static int counter = 1;
        os << "--------------------------" << endl << "Child " << counter << ": " << c.name << " " << c.age << " years old:" << ::endl << "--------------------------" << endl;
        if (c.count == 0) {
            os << "This child has no toys!" << endl;
        }
        else {
            for (size_t i = 0; i < c.count; i++) {
                os << *c.toys[i];
            }
        }
        os << "--------------------------" << endl;
        counter++;
        return os;
    }

}
