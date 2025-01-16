#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &wp) : w(wp)
{
    name = n;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << w.getType() << std::endl;
}
