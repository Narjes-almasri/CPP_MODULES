#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"
class Form;
class Bureaucrat 
{
	private:
	const std::string name;// immutable name ==>Immutable means "cannot be changed after creation".
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string n,int g);
	Bureaucrat(const Bureaucrat &n);
	Bureaucrat &operator=(const Bureaucrat &n);
	~Bureaucrat();
	std::string getName()const;
	int getGrade() const;

	void incrementBur();
	void decrementBur();

	class GradeTooHighException :public std::runtime_error
	{
		public:
		GradeTooHighException() : std::runtime_error("Grade is tooooo high"){}
	};
	class GradeTooLowException : public std::runtime_error
	{
		public:
		GradeTooLowException () : std::runtime_error("Grade is too low"){}
	};
	void signForm(Form &fb);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
 #endif

