#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
    Weapon &w;
    std::string name;
    HumanA(std::string n, Weapon &wp);
    void attack();
};
