#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::filter(std::string level)
{
    int lvl;
    if (level == "DEBUG")
        lvl = 1;
    else if (level == "INFO")
        lvl = 2;
    else if (level == "WARNING")
        lvl = 3;
    else if (level == "ERROR")
        lvl = 4;
    else
        lvl = 0;
    switch (lvl)
    {
        case 1:
            debug();
            info();
            warning();
            error();
            break ;
        case 2:
            info();
            warning();
            error();
            break ;
        case 3:
            warning();
            error();
            break ;
        case 4:
            error();
            break ;
        default:
            return ;
    }
}
