/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "Autoshop.h"
using namespace std;
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	Autoshop::~Autoshop() {
		for (auto p = m_vehicles.begin(); p < m_vehicles.end(); p++) {
			delete* p;
		}
	}
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl<< "| Cars in the autoshop!        |" << endl << "--------------------------------" << endl;
		for (auto p = m_vehicles.begin(); p < m_vehicles.end(); p++) {
			(*p)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}
}