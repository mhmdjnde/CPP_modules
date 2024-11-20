#include <iostream>
#include "zombie.hpp"

Zombie::Zombie(std::string n)
{
	name = n;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	if (name == "Foo")
		std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << "<" << name << ">" <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}
