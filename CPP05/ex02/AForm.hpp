#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat ;
class AForm
{
	private:
	const std::string form_name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_exec;

	public:
	AForm();
	AForm(const std::string formName,const int gradeToSign,const int gradeToExec);
	AForm(AForm const &n);
	AForm &operator=(AForm const &n);

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


	virtual void execute(Bureaucrat const & executor) const=0;
	virtual ~AForm();
	
};
std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif