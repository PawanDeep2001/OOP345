/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/05/2022
*/
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include <cmath>
#include "Collection.h"
namespace sdds {
	template <typename T>
	class Set : public Collection<T, 100>
	{
	public:
		bool add(const T& item) {
			for (size_t i = 0; i < this->counter; i++) {
				if (this->array[i] == item){
					return false;
				}
			}
			this->array[this->counter] = item;
			this->counter++;
			return true;
		}
		~Set() {};
	};
	template <>
	bool Set<double>::add(const double& item) {
		for (size_t i = 0; i < this->counter; i++) {
			if (fabs(floor(array[i] * 100) / 100) == fabs(floor(item * 100) / 100)) {
				return false;
			}
		}
		this->array[this->counter] = item;
		this->counter++;
		return true;
	}
}
#endif