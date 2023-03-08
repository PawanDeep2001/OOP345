/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :05/21/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include "foodorder.h"
using namespace std;
double g_taxrate;
double g_dailydiscount;
namespace sdds {
	FoodOrder::~FoodOrder() {
		if (m_description!=nullptr && strcmp(m_name, ""))
		{
			delete[] m_description;
			m_description = nullptr;
		}
	}

	FoodOrder::FoodOrder() {
		m_description = nullptr;
		m_price = 0;
		strcpy(m_name, "");
		m_special = false;
	}

	void FoodOrder::read(std::istream& istr) {
		if (istr)
		{
			char yn{};
			string description;
			istr.getline(m_name, 10, ',');
			getline(istr,description, ',');
			if (strcmp(description.c_str(),""))
			{
				m_description = new char[strlen(description.c_str()) + 1];
				strcpy(m_description, description.c_str());
			}
			istr >> m_price;
			istr.ignore(1000, ',');
			istr >> yn;
			if (yn=='N')
			{
				m_special = false;
			}
			else
			{
				m_special = true;
			}
			istr.ignore(1000, '\n');
		}
	}

	void FoodOrder::display() {
		static int counter=1;
		if (strcmp(m_name,""))
		{
			double price;
			cout << setw(2) << left << counter << ". ";
			cout << setw(10) <<  left << m_name << "|";
			cout << setw(25) << left << m_description << "|";
			price = m_price + (m_price * g_taxrate);
			cout << setw(12) << left << fixed << setprecision(2) << price << "|";
			if (m_special == true)
			{
				cout << setw(13)  << right << setprecision(2) << price - g_dailydiscount;
			}
			cout << endl;
			counter++;
		}
		else
		{
			cout << setw(2) << left << counter << ". " << "No Order" << endl;
			counter++;
		}
	}
}