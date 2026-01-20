#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat ;
class Form
{
	private:
	const std::string form_name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_exec;

	public:
	Form();
	Form(const std::string formName,const int gradeToSign,const int gradeToExec);
	Form(Form const &n);
	Form &operator=(Form const &n);
	~Form();
	class GradeTooHighException : public std::runtime_error
	{
		public:
		GradeTooHighException():std::runtime_error("the grade is to high in the form"){};
	};
	class GradeTooLowException : public std::runtime_error
	{
		public:
		GradeTooLowException () : std::runtime_error("the grade is too low in form"){};
	};
	std::string get_form_name()const;
	bool get_is_signed()const;
	int get_grade_to_sign()const;
	int get_grade_to_exec()const;
	
	void beSigned(Bureaucrat &b);
	
};
std::ostream& operator<<(std::ostream& os, const Form& b);

#endif