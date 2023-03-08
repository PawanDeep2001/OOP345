/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/10/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Utilities.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		string str{};
		Vehicle* vehicle{};
		getline(in, str, '\n');
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		if (in)
		{
			if (str[0] == 'C' || str[0] == 'c')
			{
				istringstream c(str);
				vehicle = new Car(c);
			}
			else if (str[0] == 'R' || str[0] == 'r')
			{
				istringstream r(str);
				vehicle = new Racecar(r);
			}
			else {
				throw str[0];
			}
		}
		else
		{
			return nullptr;
		}
		return vehicle;
	}
}