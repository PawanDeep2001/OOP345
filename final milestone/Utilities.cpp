// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 08/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include <iostream>
#include <string>
using namespace std;
namespace sdds{
    char Utilities::m_delimiter = {};
    void Utilities::setFieldWidth(size_t newWidth){
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const{
        return m_widthField;
    }
    string Utilities::extractToken(const string& str, size_t& next_pos, bool& more){
        size_t pos = str.find(getDelimiter(), next_pos);
        if (pos == next_pos) {
            more = false;
            throw "delimiter not found";
        }
        else {
            string local_str = str.substr(next_pos, pos - next_pos);
            local_str.erase(local_str.find_last_not_of(' ') + 1);
            local_str.erase(0, local_str.find_first_not_of(' '));
            next_pos = pos + 1;
            if (m_widthField<local_str.size()){
                m_widthField = local_str.size();
            }
            if (pos==string::npos) {
                more = false;
            }
            else {
                more = true;
            }
            return local_str;
        }
    }
    void Utilities::setDelimiter(char newDelimiter){
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter(){
        return m_delimiter;
    }
}