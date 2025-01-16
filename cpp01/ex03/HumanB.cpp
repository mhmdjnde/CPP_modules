#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

void HumanB::attack()
{
    if (w)
        std::cout << name << " attacks with their " << w->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
    w = &wp;
}

HumanB::HumanB(std::string n) : w(NULL)
{
    name = n;
}