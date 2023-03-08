/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :05/29/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds {
	ProteinDatabase::ProteinDatabase(const char* file) {
		ifstream f(file);
		string str;
		unsigned int c = 0;
		if (f.is_open()) {
			while (getline(f, str))
			{
				if (str[0] == '>')
					c++;
			}
			counter = c;
			f.close();
		}
		strings = new string[counter + 1];
		c = 0;
		f.open(file);
		if (f.is_open()) {
			while (getline(f, str))
			{
				if (str[0] != '>') {
					strings[c] += str;
				}
				else if (!strings[c].empty()) {
					c++;
				}
			}
			f.close();
		}
	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& P) {
		*this = P;
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& P) {
		if (this != &P) {
			strings = new string[P.counter];
			counter = P.counter;
			unsigned int i;
			for (i = 0; i < P.counter; i++) {
				strings[i] = P.strings[i];
			}
		}
		return *this;
	}
	ProteinDatabase::~ProteinDatabase() {
		delete[] strings;
		strings = nullptr;
	}
	size_t ProteinDatabase::size() {
		return counter;
	}
	string ProteinDatabase::operator[](size_t i) {
		if (i > counter - 1 || counter == 0 || i < 0) {
			return string();
		}
		return strings[i];
	}
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& P) noexcept {
		*this = move(P);
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& P) noexcept {
		if (this != &P) {
			delete[] strings;
			strings = P.strings;
			P.strings = nullptr;
			counter = P.counter;
			P.counter = 0;
		}
		return *this;
	}
}
