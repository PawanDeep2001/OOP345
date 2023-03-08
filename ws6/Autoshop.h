/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		~Autoshop();
		void display(std::ostream& out) const;
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto p = m_vehicles.begin(); p < m_vehicles.end(); p++) {
				if (test(*p)==true) {
					vehicles.push_back(*p);
				}
			}
		}
	};
}
#endif 