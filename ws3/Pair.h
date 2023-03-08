/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/05/2022
*/
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <iostream>
namespace sdds
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
		// TODO: Add here the missing the prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair();
		std::ostream& display(std::ostream& os)const;
		bool operator==(const Pair& p2);
	};
	std::ostream& operator<<(std::ostream& os, const Pair& p);
}
#endif