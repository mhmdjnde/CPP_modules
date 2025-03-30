#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    Bureaucrat berau("MhMd", 137);
    ShrubberyCreationForm form("JnDe");
    RobotomyRequestForm form2("easy");
    try
    {
        berau.signForm(form);
        berau.executeForm(form);
        berau.signForm(form2);
        berau.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
}