#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*formCreators[])(const std::string &) = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialForm
    };

    for (size_t i = 0; i < 3; ++i) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Error: Form name '" << formName << "' is invalid." << std::endl;
    return 0;
}

AForm *Intern::createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}
