/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/26/2022
*/
#include <algorithm>
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book() {
		;
	}
	const string& Book::title() const {
		return Title;
	}
	const string& Book::country() const {
		return Country;
	}
	const size_t& Book::year() const {
		return Year;
	}
	double& Book::price() {
		return Price;
	}
	Book::Book(const string& b) {
		string str = b;
		string num;
		Author = str.substr(0, str.find(","));
		Author.erase(0, Author.find_first_not_of(" "));
		Author.erase(Author.find_last_not_of(" ") + 1);
		str.erase(0, str.find(",") + 1);

		Title = str.substr(0, str.find(","));
		Title.erase(0, Title.find_first_not_of(" "));
		Title.erase(Title.find_last_not_of(" ") + 1);
		str.erase(0, str.find(",") + 1);

		Country = str.substr(0, str.find(","));
		Country.erase(0, Country.find_first_not_of(" "));
		Country.erase(Country.find_last_not_of(" ") + 1);
		str.erase(0, str.find(",") + 1);

		num = str.substr(0, str.find(","));
		num.erase(0, num.find_first_not_of(" "));
		num.erase(num.find_last_not_of(" ") + 1);
		Price = stod(num);
		str.erase(0, str.find(",") + 1);
		
		num = str.substr(0, str.find(","));
		num.erase(0, num.find_first_not_of(" "));
		num.erase(num.find_last_not_of(" ") + 1);
		Year = stoi(num);
		str.erase(0, str.find(",") + 1);

		Description = str.substr(str.find_first_not_of(" "), str.find_last_not_of(" ") + 1);
	}
	ostream& operator<<(ostream& os, const Book& b) {
		os << setw(20) << b.Author << " | " << setw(22) << b.title() << " | " << setw(5) << b.country() << " | " << setw(4) << b.year() << " | " << fixed << setw(6) << setprecision(2) << b.Price << " | " << b.Description << endl;
		return os;
	}
}