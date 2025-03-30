#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	target = "easy default";
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToSign())
	{
		throw GradeTooLowException();
	}
	if (executor.getGrade() > this->getGradeToExec())
	{
		throw GradeTooLowException();
	}
	std::ofstream file((this->target + "_shrubbery").c_str());
	file << "    /\\    \n";
	file << "   /  \\   \n";
	file << "  /    \\  \n";
	file << " /      \\ \n";
	file << "/________\\\n";
	file << "    ||    \n";
	file << "    ||    \n";
	file << "    ||    \n";

		file.close();
}
