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
#include "ConfirmOrder.h"
using namespace std;
namespace sdds {
    ConfirmOrder::ConfirmOrder() {
        ;
    }
    ConfirmOrder::ConfirmOrder(const ConfirmOrder& c) {
        *this = c;
    }
    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& c) {
        if (this != &c){
            count = c.count;
            const Toy** temp = nullptr;
            temp = new const Toy * [count];
            for (size_t i = 0; i < count; i++) {
                (temp[i]) = c.toy[i];
            }
            delete[] toy;
            toy = temp;
        }
        return *this;
    }
    ConfirmOrder& ConfirmOrder::operator+=(const Toy& t) {
        bool found = false;
        for (size_t i = 0; i < count; i++) {
            if (&t == toy[i]) {
                found = true;
            }
        }
        if (found == false) {
            const Toy** temp = nullptr;
            temp = new const Toy * [count + 1]{};
            for (size_t i = 0; i < count; i++) {
                temp[i] = toy[i];
            }
            temp[count++] = &t;
            delete[] toy;
            toy = temp;
        }
        return *this;
    }
    ConfirmOrder& ConfirmOrder::operator-=(const Toy& t) {
        for (size_t i = 0; i < count; i++) {
            if (&t == toy[i]) {
                toy[i] = nullptr;
                count-=1;
            }
        }
        return *this;
    }
    ConfirmOrder::ConfirmOrder(ConfirmOrder&& c) noexcept {
        *this = move(c);
    }
    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& c) noexcept {
        if (this != &c) {
            count = c.count;
            c.count = 0;
            toy = c.toy;
            c.toy = nullptr;
        }
        return *this;
    }
    ConfirmOrder::~ConfirmOrder() {
        delete[] toy;
    }
    ostream& operator<<(ostream& os, const ConfirmOrder& c) {
        os << "--------------------------" << endl << "Confirmations to Send" << endl << "--------------------------" << endl;
        if (c.count == 0) {
            os << "There are no confirmations to send!" << endl;
        }
        if (c.count > 0) {
            for (size_t i = 0; i < c.count; i++)
            {
                if (c.toy[i]) {
                    os << *c.toy[i];
                }
            }
        }
        os << "--------------------------" << endl;
        return os;
    }
}
