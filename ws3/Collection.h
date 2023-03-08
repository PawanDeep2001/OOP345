/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :06/05/2022
*/
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
#include "Pair.h"
namespace sdds
{
    template <typename T, unsigned int capacity>
    class Collection
    {
    protected:
        unsigned int counter{};
        T array[capacity]{};
        T dummy{};
    public:
        ~Collection() {};
        int size() {
            return counter;
        }
        void display(std::ostream& os = std::cout) {
            os << "----------------------\n| Collection Content |\n----------------------" << std::endl;
            for (size_t i = 0; i < counter; i++)
            {
                os << array[i] << std::endl;
            }
            os << "----------------------\n";
        }
        virtual bool add(const T& item) {
            if (counter < capacity) {
                array[counter] = item;
                counter++;
                return true;
            }
            else {
                return false;
            }
        }
        T operator[](size_t index) {
            if (index >= 0 && index < capacity) {
                return array[index];
            }
            else {
                return dummy;
            }
        }
    };
    template <>
    Pair Collection<Pair, 100>::operator[](size_t index) {
        if ( index >= 0 && index < counter) {
            return array[index];
        }
        else {
            dummy = Pair("No Key", "No Value");
            return dummy;
        }
    }
}
#endif 