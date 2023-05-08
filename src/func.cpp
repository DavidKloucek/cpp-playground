#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

namespace DavidKloucek::OperatorOverloading
{
    class Size
    {
    public:
        int sum;
        Size(int i) : sum(i) {}
        Size operator+(const Size &e) const
        {
            return Size(this->sum + e.sum);
        }
        Size operator-(const Size &e) const
        {
            return Size(this->sum - e.sum);
        }

        friend std::ostream &operator<<(std::ostream &stream, const Size &o);
    };

    std::ostream &operator<<(std::ostream &stream, const Size &o)
    {
        stream << o.sum;
        return stream;
    }

    void run()
    {

        Size a(1);
        Size b(2);

        std::cout << a + b + Size(10) - Size(5) << endl;

        std::cout << std::endl
                  << std::endl
                  << std::endl;
    }
}

namespace DavidKloucek::FunctionAsArgument
{
    void printMultipliedNumber(int num, std::function<int(int)> const &fn)
    {
        std::cout << fn(num) << std::endl;
    };
    void printMultipliedNumber2(int num, int (*fn)(const int &))
    {
        std::cout << fn(num) << std::endl;
    };

    auto doubleNum = [](const int &i)
    {
        return i * 2;
    };
    int doubleNum2(const int &i)
    {
        return i * 3;
    };

    void run()
    {
        printMultipliedNumber(5, doubleNum);
        printMultipliedNumber2(5, &doubleNum2);
    }
}

namespace DavidKloucek::MultiTypeVar
{
    void run()
    {
        std::variant<std::string, int, float> val;
        val = 1;
        cout << sizeof(val) << endl;
        
        if (std::get_if<std::string>(&val))
        {
            cout << "Str: " << std::get<string>(val);
        }
        else if (std::get_if<int>(&val))
        {
            cout << std::get<int>(val) << endl;
        }
    }

}

namespace DavidKloucek::PointersAndFunction
{

    auto sumValues = [](auto a, auto b)
    {
        return a + b;
    };

    void run()
    {
        auto increment = [](int &i)
        {
            i++;
        };

        int a = 5;
        int b = 8;
        int *ref = &a;
        *ref = 2;
        ref = &b;
        *ref = 8;
        increment(*ref);
        cout << a << " | " << b << endl;

        cout << sumValues(10, 10) << endl;
    }

}

namespace DavidKloucek::FunctionTemplate
{
    template <typename T>
    T myMax(T x, T y)
    {
        return (x > y) ? x : y;
    }
    void run()
    {
        cout << std::endl;
        cout << myMax<int>(3, 7) << endl;
        cout << myMax<double>(3.0, 7.0) << endl;
        cout << myMax<char>('g', 'e') << endl;
    }
}

namespace DavidKloucek::Lambda
{
    void run()
    {
        auto multiply = [](int a, int b)
        {
            return a * b;
        };

        int x = 10;
        auto multiply2 = [x](int a, int b)
        {
            return a * b * x;
        };

        std::cout << multiply(3, 3) << std::endl;
        std::cout << multiply2(3, 3) << std::endl;
    }
}
