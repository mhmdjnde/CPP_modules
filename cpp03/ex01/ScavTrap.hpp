#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &c);
        void attack(const std::string& target);
        void guardGate();
};

#endif
