/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/24/2022
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool sinValidator(std::string str) {
			int n = 0;
			int total = 0;
			unsigned int i = 0;
			if (str.length()==9) {
				do {
					n = str[i]-'0';
					if (i % 2 == 0) {
						total += n;
					}
					else {
						if (n*2<=9) {
							total += n * 2;
						}
						else {
							total += n * 2 - 9;
						}
					}
					i++;
				} while (i != str.length());
			}
			if (total%10==0) {
				return true;
			}
			else {
				return false;
			}
		}
		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(T* obj) {
			list.push_back(*obj);
		}


		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T& obj) {
			list.push_back(obj);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H