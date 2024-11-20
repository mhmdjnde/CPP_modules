#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap1;
    ClapTrap clap2("Clappy");
    clap2.attack("target");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap1 = clap2;
    clap1.attack("target");
    ScavTrap scav1;
    ScavTrap scav2("Scavy");
    scav2.attack("target");
    scav2.guardGate();
    return 0;
}
