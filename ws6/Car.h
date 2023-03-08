/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle {
		std::string Maker{};
		std::string Condition{};
		double TopSpeed{};
	public:
		Car(std::istream& in);
		~Car();
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif