#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2;

    clap1.attack("Bandit");
    clap2.attack("Skag");

    clap1.takeDamage(5);
    clap2.takeDamage(3);

    clap1.beRepaired(7);
    clap2.beRepaired(4);

    return 0;
}
