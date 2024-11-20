#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac == 2)
    {
        harl.filter(av[1]);
    }
    return 0;
}
