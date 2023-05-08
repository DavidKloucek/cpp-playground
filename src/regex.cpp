#include <iostream>
#include <regex>

namespace DavidKloucek::Regex
{
    void runMatch()
    {
        std::string s = "";
        std::regex re("^\\d+$");

        std::cout << std::regex_match("a123", re) << std::endl;
        std::cout << std::regex_match("123", re) << std::endl;
    }
}