/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/26/2022
*/
#include <algorithm>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds {
	Movie::Movie() {
		;
	}
	const string& Movie::title() const {
		return Title;
	}
	Movie::Movie(const string& strMovie) {
		string str = strMovie;
		string num;
		Title = str.substr(0, str.find(","));
		Title.erase(0, Title.find_first_not_of(" "));
		Title.erase(Title.find_last_not_of(" ") + 1);
		str.erase(0, str.find(",") + 1);
		num = str.substr(0, str.find(","));
		num.erase(0, num.find_first_not_of(" "));
		num.erase(num.find_last_not_of(" ") + 1);
		str.erase(0, str.find(",") + 1);
		rel_year = stoi(num);
		description = str.substr(str.find_first_not_of(" "), str.find_last_not_of(" ") + 1);;
	}
	ostream& operator<<(ostream& os, const Movie& m) {
		if (!m.title().empty()) {
			os << setw(40) << m.title() << " | " << setw(4) << m.rel_year << " | " << m.description << endl;
		}
		return os;
	}
}