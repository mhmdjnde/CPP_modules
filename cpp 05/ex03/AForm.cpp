#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExec() const {
    return gradeToExec;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() 
       << " [Signed: " << (form.getIsSigned() ? "Yes" : "No") 
       << ", Sign Grade: " << form.getGradeToSign()
       << ", Execute Grade: " << form.getGradeToExec() << "]";
    return os;
}
