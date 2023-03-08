/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :05/29/2022
*/

#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <string>
namespace sdds {
	class ProteinDatabase {
		std::string* strings{};
		unsigned int counter = 0;

	public:
		ProteinDatabase() {};
		ProteinDatabase(const char* fileName);
		~ProteinDatabase();
		ProteinDatabase(const ProteinDatabase& P);
		ProteinDatabase& operator=(const ProteinDatabase& P);
		std::size_t size();
		std::string operator[](size_t);
		ProteinDatabase(ProteinDatabase&& P) noexcept;
		ProteinDatabase& operator=(ProteinDatabase&& P) noexcept;
	};
}
#endif