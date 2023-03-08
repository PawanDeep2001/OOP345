/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :06/26/2022
*/
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file)
			throw "Bad file name!";
		else {
			string str{};
			int i = 0;
			do {
				getline(file, str);
				if (file) {
					m_badWords[i] = str.substr(0, str.find(" "));
					do
					{
						str.erase(0, str.find(" ") + 1);
					} while (str[0]==' ');
					m_goodWords[i] = str;
					i++;
				}
			} while (file);
		}
	}
	void SpellChecker::operator()(string& text) {
		size_t a = 0;
		for (size_t i = 0; i < 6; i++) {
			while ((a = text.find(m_badWords[i])) != string::npos) {
				text.replace(a, m_badWords[i].length(), m_goodWords[i]);
				counter[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < 6; i++) {
			out << right << setw(15) << m_badWords[i] << ": " << counter[i] << " replacements" << endl;
		}
	}
}