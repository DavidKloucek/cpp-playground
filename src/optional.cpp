#include <iostream>
#include <fstream>
//#include <boost/algorithm/string/join.hpp>

namespace DavidKloucek::Optional
{
    struct Person
    {
        std::string name;
        std::optional<std::vector<string>> adresses;
    };

    void printAddressList(vector<string> addrs)
    {
        for (auto a : addrs) {
            std::cout << " - " << a << std::endl;
        }
    }

    void printPerson(const Person &p, const bool &useFallbackAddr = false)
    {
        std::cout << p.name << std::endl;
        if (!useFallbackAddr)
        {
            if (p.adresses.has_value())
            {
                printAddressList(p.adresses.value());
                //std::cout << "Addresses: " << boost::algorithm::join(p.adresses.value(), ", ") << std::endl;
            }
            else
            {
                std::cout << "No adresses" << std::endl;
            }
        }
        else
        {
                printAddressList(p.adresses.value_or(std::vector<string>{"Brno"}));
            //std::cout << "Addresses: " << boost::algorithm::join(p.adresses.value_or(std::vector<string>{"Brno"}), ", ") << std::endl;
        }
        std::cout << std::endl;
    }

    void run()
    {
        Person me{"David", vector<string>{"Prague", "Louny"}};
        Person homeless{"Lucas", std::nullopt};

        printPerson(me);
        printPerson(homeless);
        printPerson(homeless, true);
    }
}
