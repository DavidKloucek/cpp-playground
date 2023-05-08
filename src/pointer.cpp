#include <iostream>

namespace DavidKloucek::Pointer
{
    class User
    {
    public:
        int id;
        User(int id) : id(id)
        {
            std::cout << "Create " << id << std::endl;
        }
        ~User()
        {
            std::cout << "Destroy " << this->id << std::endl;
        }
    };

    void run()
    {
        auto user1 = std::make_unique<User>(1);
        auto user2 = std::make_unique<User>(2);

        auto user3 = new User(3);
        delete user3;
    }
}
