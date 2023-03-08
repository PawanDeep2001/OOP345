#include "Utilities.h"

using namespace sdds;

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
}

void Utilities::setDelimiter(char newDelimiter) {
    m_delimiter = newDelimiter;
}

size_t Utilities::getFieldWidth() const {
    return m_widthField;
}

char Utilities::getDelimiter() {
    return m_delimiter;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
    std::string temp;

    while (next_pos < str.size()) {
        if ((str[next_pos] == m_delimiter)) {
            next_pos++;
            break;
        } else {
            temp += (str[next_pos]);
            next_pos++;
        }

    }

    if (temp.empty()) {
        more = false;
        throw -1;
    }

    if (next_pos >= str.size()) {
        more = false;
    }

    temp = sdds::trim(temp);
    m_widthField = std::max(temp.size(), m_widthField);
    return temp;
}

std::string sdds::trim(const std::string& s) {
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }

    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

