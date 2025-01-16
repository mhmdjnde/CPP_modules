#include <iostream>
#include "HumanA.hpp"

class HumanB {
private:
    Weapon* w;
    std::string name;
public:
    HumanB(std::string n);
    void attack();
    void setWeapon(Weapon &wp);
};
