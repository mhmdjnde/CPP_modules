#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing FragTrap Default Constructor ===" << std::endl;
    FragTrap frag1;  // Default constructor

    std::cout << "\n=== Testing FragTrap Parameterized Constructor ===" << std::endl;
    FragTrap frag2("Fraggy");  // Parameterized constructor

    std::cout << "\n=== Testing FragTrap Copy Assignment ===" << std::endl;
    FragTrap frag3;
    frag3 = frag2;  // Assignment operator

    std::cout << "\n=== Testing FragTrap Attack ===" << std::endl;
    frag2.attack("Enemy");

    std::cout << "\n=== Testing FragTrap High Fives ===" << std::endl;
    frag2.highFivesGuys();  // Special function

    std::cout << "\n=== Testing FragTrap Take Damage ===" << std::endl;
    frag2.takeDamage(20);  // Inherited function

    std::cout << "\n=== Testing FragTrap Be Repaired ===" << std::endl;
    frag2.beRepaired(50);  // Inherited function

    std::cout << "\n=== Testing ScavTrap Functionality ===" << std::endl;
    ScavTrap scav1("Scavvy");  // Testing ScavTrap

    scav1.attack("Target");
    scav1.guardGate();

    std::cout << "\n=== Destruction Phase ===" << std::endl;
    return 0;  // Destruction starts here for all objects created
}
