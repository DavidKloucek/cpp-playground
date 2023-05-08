#include <iostream>

namespace DavidKloucek::DateTime
{
    void runDateTime()
    {
        time_t now;
        struct tm locTime;
        now = time(NULL);
        locTime = *localtime(&now);
        std::cout << "Day: " << locTime.tm_mday << std::endl;
    }
}
