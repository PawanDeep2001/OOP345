/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/12/2022
*/
#include <iomanip>
#include "Toy.h"
using namespace std;
namespace sdds {
    Toy::Toy() {
        ;
    }
    void Toy::update(int num){
        counter = num;
    }
    Toy::Toy(const std::string& t) {
        size_t start = 0;
        size_t end = t.find(':');
        order_id = stoi(t.substr(start, end));
        start = end + 1;
        end = t.find(':', start);
        name = t.substr(start, end - start);
        for (size_t i = 0; i < name.length(); i++)
        {
            name.erase(i, name.find_first_not_of(' '));
            name.erase(name.find_last_not_of(' ') + 1);
        }
        start = end + 1;
        end = t.find(':', start);
        counter = stoi(t.substr(start, end - start));
        start = end + 1;
        end = t.find(':', start);
        price = stod(t.substr(start, end));
    }

    ostream& operator<<(ostream& os, const Toy& t) {
        double t1 = 0;
        double tax = 0;
        double tot = 0;
        t1 = t.price * t.counter;
        tax = t1 * t.tax;
        tot = t1 + tax;
        os << "Toy" << setw(8) << t.order_id << ":" << right << setw(18) << t.name << setw(3) << t.counter << " items" << setw(8) << t.price << "/item  subtotal:" << setw(7) << t1 << " tax:" << setw(6) << setprecision(2) << fixed << tax << " total:" << setw(7) << tot << endl;
        return os;
    }
}