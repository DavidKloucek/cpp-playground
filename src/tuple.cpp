#include <iostream>

namespace DavidKloucek::Tuple
{
    struct Person
    {
        std::string name;
        int Age;
    };
    std::tuple<std::string, int> createPerson()
    {
        return {"David", 27};
    };
    
    void run()
    {
        std::string name = "David";
        int age = 27;
        std::tie(name, age) = createPerson();
        auto [name2, age2] = createPerson();
    }
}
