#include <iostream>
#include <libs/json.hpp>

namespace DavidKloucek::Json
{
    void run()
    {
        using json = nlohmann::json;

        auto s = json::parse("{\"name\":\"David\"}");

        std::cout << s.size();
    }
}
