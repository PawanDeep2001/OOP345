/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/26/2022
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
namespace sdds {
	class Book
	{
		std::string Author{};
		std::string Title{};
		std::string Country{};
		size_t Year{};
		double Price{};
		std::string Description{};
	public:
		Book();
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		const std::string& title() const;
		Book(const std::string& b);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(Description);
		};
		friend std::ostream& operator<<(std::ostream&, const Book&);
	};
}
#endif 