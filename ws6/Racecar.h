/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
using namespace std;
namespace sdds {
	class Racecar :public Car {
		double m_booster{};
	public:
		Racecar(std::istream& in);
		~Racecar();
		void display(std::ostream& out)const;
		double topSpeed()const;
	};
}
#endif