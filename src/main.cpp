#include <iostream>
#include "threading.cpp"
#include "func.cpp"
#include "basic.cpp"
#include "oop.cpp"
#include "array.cpp"
#include "json.cpp"
#include "tuple.cpp"
#include "complex.cpp"
#include "optional.cpp"
#include "datetime.cpp"
#include "regex.cpp"
#include "pointer.cpp"

using namespace DavidKloucek;

int main(int argc, char **argv)
{
    DavidKloucek::Basics::runHello();

    std::cout << endl;

    return 0;
}
