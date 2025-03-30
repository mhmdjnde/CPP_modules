#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::decrementGrade()
{
		if (grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			grade++;
}

void	Bureaucrat::incrementGrade()
{
		if (grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			grade--;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("too high grade");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}
