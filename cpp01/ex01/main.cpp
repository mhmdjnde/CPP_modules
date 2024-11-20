#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int main()
{
    Zombie* z1 = zombieHorde(10, "jnde");
    for(int i = 0; i < 10; i++)
        z1[i].announce();
    delete[] z1;
    return 0;
}