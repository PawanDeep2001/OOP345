/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/05/2022
*/
#include <iomanip>
#include "Pair.h"
using namespace std;
namespace sdds{
	Pair::Pair() {
		;
	}
	std::ostream& Pair::display(std::ostream& os)const{
		os << setw(20) << right << m_key << ": " << m_value;
		return os;
	}
	bool Pair::operator==(const Pair& p2) {
		return m_key == p2.m_key;
	}
	std::ostream& operator<<(std::ostream& os, const Pair& p){
		return p.display(os);
	}
}