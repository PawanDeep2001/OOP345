#ifndef OOP_PROJECT_UTILITIES_H

#include <string>

namespace sdds {
    /**
     * Custom function to remove whitespaces from the input string
     *
     * @param s string you want toi trim
     * @return s without starting and trailing whitespaces
     */
    std::string trim(const std::string& s);

    class Utilities {
      public:
        // specifies the length of the token extracted; used for display purposes
        size_t m_widthField = 1;
        // separates the tokens in any given std::string object.
        static char m_delimiter;

        void setFieldWidth(size_t newWidth);

        size_t getFieldWidth() const;

        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

        static void setDelimiter(char newDelimiter);

        static char getDelimiter();

    };
}
#define OOP_PROJECT_UTILITIES_H

#endif