/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :05/21/2022
*/

#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <iostream>
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds {
	class FoodOrder
	{
		char m_name[10];
		char* m_description;
		double m_price;
		bool m_special;
	public:
		FoodOrder();
		~FoodOrder();
		void read(std::istream& istr);
		void display();
	};
}

#endif