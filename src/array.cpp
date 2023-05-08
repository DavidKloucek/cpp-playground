#include <iostream>
#include <unordered_map>

namespace DavidKloucek::StaticArray
{
    struct Vertex
    {
        int x, y, z;
    };

    void run()
    {
        Vertex *v = new Vertex[10];
        v[0] = {1, 2, 3};

        std::cout << v[0].y;
    }
}

namespace DavidKloucek::Map
{
    void run()
    {
        struct City
        {
            std::string name;
            int size;
        };

        std::unordered_map<std::string, City> cities;
        cities["Louny"] = {"Louny", 100};
        cities["Praha"] = {"Praha", 5};
        cities["Brno"] = {"Brno", 50};

        for (auto&[key, value] : cities) {
            std::cout << key << " | " << value.name << " | " << value.size << std::endl;
        }
    }
}
