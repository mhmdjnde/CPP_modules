#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;

	if (this != &c)
	{
    	this->name = c.name;
    	this->hitPoints = c.hitPoints;
    	this->energyPoints = c.energyPoints;
    	this->attackDamage = c.attackDamage;
	}
    return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap gives high fives!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &c) : ClapTrap(c)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = c;
}
