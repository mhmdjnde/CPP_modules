#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	target = "easy default";
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
	{
		throw GradeTooLowException();
	}
	if (executor.getGrade() > this->getGradeToExec())
	{
		throw GradeTooLowException();
	}
	std::cout << target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}
