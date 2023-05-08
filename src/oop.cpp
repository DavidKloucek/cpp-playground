#include <iostream>
#include <unistd.h>

using namespace std;

namespace DavidKloucek::FriendFunction
{
    class Meter
    {
    private:
        int meter = 0;
        friend class MeterUser;
        friend void add5(Meter &m);
    };

    class MeterUser
    {
    public:
        int doSomething(Meter m)
        {
            return m.meter;
        }
    };

    void add5(Meter &m)
    {
        m.meter += 5;
    }

    void run()
    {
        auto m = Meter();
        auto mu = MeterUser();
        add5(m);
        cout << "C name: " << mu.doSomething(m) << endl;
    }
}

namespace DavidKloucek::VirtualDestructor
{
    class Base
    {
    public:
        Base()
        {
            cout << "Base Constructor Called\n";
        }
        ~Base()
        {
            cout << "Base Destructor called\n";
        }
    };

    class Derived1 : public Base
    {
    public:
        Derived1()
        {
            cout << "Derived constructor called\n";
        }
        ~Derived1()
        {
            cout << "Derived destructor called\n";
        }
    };

    void run()
    {

        Base *b = new Derived1();
    }
}

namespace DavidKloucek::Constructors
{
    class Person
    {
        int age;
        string name;

    public:
        Person(int age)
        {
            this->age = age;
        };
        Person(string name)
        {
            this->name = name;
        }
    };

    class Xyz
    {
    private:
        int width;
        int height;

    public:
        Xyz(int i) : width(i), height(i) {}
        Xyz(int defaultWidth, int defaultHeight)
        {
            this->width = defaultWidth;
            this->height = defaultHeight;
        }
        int sum()
        {
            return this->width + this->height;
        }
    };

    void run()
    {
        Person a = 10;
        Person b(1);
        Person c("c");
        Person d = Person("d");

        auto x1 = Xyz(5);
        auto x2 = Xyz(5, 5);
        auto x3 = Xyz{5, 5};

        cout << x1.sum() + x2.sum() + x3.sum() << endl;
    }
}

namespace DavidKloucek::TemplateAndInterface
{
    class Base
    {
    public:
        virtual std::string work() = 0;
    };

    class A : Base
    {
    public:
        std::string work()
        {
            return std::string("A");
        }
    };

    class B : Base
    {
    public:
        std::string work()
        {
            return std::string("B");
        }
    };

    class C
    {
    public:
        std::string work()
        {
            return std::string("C");
        }
    };

    template <typename T, std::enable_if_t<std::is_base_of_v<Base, T>, bool> = true>
    void printWork(T bs)
    {
        cout << bs.work();
    }

    void run()
    {
        A a;
        B b;
        C c;
        printWork(a);
        printWork(b);
        // printWork(c);
    }
}

namespace DavidKloucek::CopyConstructor
{
    class Vertex
    {
        float x, y, z;

    public:
        Vertex(float x, float y, float z) : x(x), y(y), z(z)
        {
        }
        Vertex(const Vertex &v) : x(v.x), y(v.y), z(v.z)
        {
            cout << "Copied!" << std::endl;
        }
    };

    void run()
    {
        Vertex v1{1, 2, 3};
        Vertex v2(v1);
    }
}

namespace DavidKloucek::Singleton
{
    class UserService
    {
    private:
        UserService() {}

    public:
        static UserService &getInstance()
        {
            static UserService instance;
            return instance;
        }
        UserService(UserService const &) = delete;
        void operator=(UserService const &) = delete;
        int i;
    };

    void run()
    {

        auto us1 = &UserService::getInstance();
        auto us2 = &UserService::getInstance();

        std::cout << us1 << std::endl;
        std::cout << us2 << std::endl;
    }
}

namespace DavidKloucek::Exceptions
{
    class MathException : public exception
    {
    private:
        char *msg;

    public:
        MathException(char *msg) : msg(msg) {}

        const char *what() const throw()
        {
            return this->msg;
        }
    };

    double division(int a, int b)
    {
        if (b == 0)
        {
            throw MathException((char *)"Division by zero");
        }
        return (a / b);
    }

    void run()
    {
        try
        {
            auto res = division(9, 0);
            cout << res << endl;
        }
        catch (const MathException &ex)
        {
            cerr << ex.what() << endl;
        }
    }
}
