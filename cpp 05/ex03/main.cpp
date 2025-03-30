#include "Intern.hpp"

int main() {
    Intern someRandomIntern;

    // Test creating a robotomy request form
    AForm *robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotomyForm) {
        std::cout << *robotomyForm << std::endl;
        delete robotomyForm; // Proper cleanup
    }

    // Test creating a shrubbery creation form
    AForm *shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (shrubberyForm) {
        std::cout << *shrubberyForm << std::endl;
        delete shrubberyForm; // Proper cleanup
    }

    // Test invalid form request
    AForm *invalidForm = someRandomIntern.makeForm("unknown form", "Nobody");
    if (!invalidForm) {
        std::cout << "Invalid form request handled correctly." << std::endl;
    }

    return 0;
}
