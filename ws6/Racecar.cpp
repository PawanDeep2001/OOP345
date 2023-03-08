/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(istream& in) :Car(in) {
		string str{};
		string booster{};
		getline(in, str);
		booster = str.substr(str.find_last_of(",") + 1);
		stringstream s(booster);
		s >> m_booster; 
	}
	Racecar::~Racecar() {
		;
	}
	void Racecar::display(ostream& out)const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed()const { 
		return Car::topSpeed() * (1 + m_booster); 
	}
}