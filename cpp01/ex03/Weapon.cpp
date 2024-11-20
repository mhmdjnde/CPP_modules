#include <iostream>
#include "Weapon.hpp"

void	Weapon::setType(std::string t)
{
	type = t;
}

const std::string	Weapon::getType()
{
	return type;
}

Weapon::Weapon(std::string t)
{
	type = t;
}
