#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

namespace DavidKloucek::Complex
{
    using namespace std;

    class PrintableIdentificator
    {
    public:
        virtual string printableIdentifier() = 0;
    };

    class User : public PrintableIdentificator
    {
    private:
        int id;
        string name;

    public:
        User(int i) : id(i)
        {
            cout << "Create: " << this->id << endl;
        }
        ~User()
        {
            cout << "Destroy: " << this->id << endl;
        }
        int getId()
        {
            return this->id;
        }
        string printableIdentifier()
        {
            return "User@" + std::to_string(this->id);
        }
    };

    void run()
    {
        vector<User *> userList;

        auto usr1 = std::make_unique<User>(1);
        auto usr3 = std::make_unique<User>(3);
        auto usr2 = std::make_unique<User>(2);

        userList.push_back(usr1.get());
        userList.push_back(usr2.get());
        userList.push_back(usr3.get());

        std::sort(userList.begin(), userList.end(), [](const auto &a, const auto &b)
                  { return a->getId() < b->getId(); });

        for (auto u : userList)
        {
            cout << "LOOP: " << &u << " | " << u->getId() << " | " << u->printableIdentifier() << endl;
        }

        userList.clear();

        std::cout << "End" << std::endl;
    }
}
