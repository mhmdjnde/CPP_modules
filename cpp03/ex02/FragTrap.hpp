#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &c);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &c);
        void highFivesGuys(void);
};
