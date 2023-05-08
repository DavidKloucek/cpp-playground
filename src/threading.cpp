#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

namespace DavidKloucek::Threading
{
    using namespace std::chrono_literals;

    void doWork()
    {
        std::cout << "W START" << std::endl;
        std::this_thread::sleep_for(2s);
        std::cout << "W DONE" << std::endl;
    }

    long fibonacci(unsigned n)
    {
        if (n < 2)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    void run()
    {
        std::cout << "START" << std::endl;

        std::thread worker(doWork);
        worker.join();

        std::cout << "DONE" << std::endl;
    }
}