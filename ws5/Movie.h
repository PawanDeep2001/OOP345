/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/26/2022
*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds {
	class Movie {
		std::string Title{};
		int rel_year{};
		std::string description{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(description);
			spellChecker(Title);
		}
		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}

#endif