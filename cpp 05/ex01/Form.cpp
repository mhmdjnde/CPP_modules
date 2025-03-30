#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExec(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExec() const {
    return gradeToExec;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << " [Signed: " << (form.getIsSigned() ? "Yes" : "No") 
       << ", Sign Grade: " << form.getGradeToSign()
       << ", Execute Grade: " << form.getGradeToExec() << "]";
    return os;
}
