/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/26/2022
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
namespace sdds {
	template<typename T>
	class Collection {
		std::string Name{};
		T* Array{};
		size_t Size{};
		void (*Observer)(const Collection<T>&, const T&) {};
	public:
		Collection(std::string name) {
			Name = name;
		}
		Collection(const Collection& c) = delete;
		Collection& operator=(const Collection& c) = delete;
		~Collection() {
			delete[] Array;
			Array = nullptr;
		};
		const std::string& name() const {
			return Name;
		};
		size_t size() const {
			return Size;
		};
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			Observer = observer;
		};
		Collection<T>& operator+=(const T& item) {
			bool ans = false;
			for (size_t i = 0; i < Size; i++) {
				if (Array[i].title()== item.title()) {
					ans = true;
				}
			}
			if (ans==false) {
				T* coll = new T[Size + 1];
				for (size_t i = 0; i < Size; i++) {
					coll[i] = Array[i];
				}
				coll[Size] = item;
				Size += 1;
				delete[] Array;
				Array = nullptr;
				Array = new T[Size];
				for (size_t i = 0; i < Size; i++) {
					Array[i] = coll[i];
				}
				delete[] coll;
				coll = nullptr;
				if (Observer != nullptr){
					Observer((*this), item);
				}
			}
			return *this;
		};
		T& operator[](size_t idx) const {
			std::string error = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
			if (idx < size())
				return Array[idx];
			else {
				throw std::out_of_range(error);
			}
		};
		T* operator[](std::string title) const {
			T* ans = nullptr;
			for (size_t i = 0; i < Size; i++) {
				if (Array[i].title()==title) {
					return &Array[i];
				}
			}
			return ans;
		};
		friend std::ostream& operator<<(std::ostream& os, const Collection& c) {
			for (size_t i = 0; i < c.size(); i++) {
				os << c[i];
			}
			return os;
		}
	};
}

#endif