#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

// class BureaucratException : public std::exception{
// 	private:
// 		std::string message;
// 	public:
// 		BureaucratException(std::string message)
// 		{
// 			std::cout << "BurBureaucratException default construction called" << std::endl;
// 			this->message = message;
// 		}
		
// 		virtual ~BureaucratException() throw() {}

// 		const char* what() const throw(){
//         return message.c_str();
//     	}
// };

class Bureaucrat{
	private:
		const 	std::string name;
		int 	grade;
		Bureaucrat& operator=(const Bureaucrat& other);
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		std::string	getName() const;
		int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:

				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
