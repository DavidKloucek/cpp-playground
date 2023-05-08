#include <iostream>
#include <string>

#define MULTIPLY_TWO_NUMBERS(a, b) a *b

namespace DavidKloucek::Basics
{
    void runHello()
    {
        std::cout << "Hello World!" << std::endl;
    }

    void runMacros()
    {
        std::cout << MULTIPLY_TWO_NUMBERS(5, 5);
    }

    void runStringComparison()
    {
        std::string a("test");

        if (strcmp(a.c_str(), "test") == 0)
        {
            std::cout << "Same";
        }
        else
        {
            std::cout << "Different";
        }
    }

    void runMemset()
    {
        char str[] = "almost every programmer should know memset!";
        memset(str, '-', 6);
        puts(str);
    }

}
