#include "AForm.hpp"

AForm::AForm():form_name("unknown"),is_signed(false),grade_to_sign(50),grade_to_exec(50)
{
	std::cout<<"defualt const\n";
}
AForm::AForm(const std::string formName,const int gradeToSign,const int gradeToExec) :form_name(formName),is_signed(false),grade_to_sign(gradeToSign),grade_to_exec(gradeToExec)
{
	std::cout<<"parametrized const\n";
	if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooLowException();
}
AForm::AForm(AForm const &n):form_name(n.form_name),is_signed(n.is_signed),grade_to_sign(n.grade_to_sign),grade_to_exec(n.grade_to_exec)
{}
AForm &AForm::operator=(AForm const &n)
{
	if(this != &n)
	is_signed = n.is_signed;
	return *this;
}
AForm::~AForm()
{}


std::string AForm::get_form_name()const
{
	return form_name;
}
bool AForm::get_is_signed()const
{
	return is_signed;
}
int AForm::get_grade_to_sign()const
{
	return grade_to_sign;
}
int AForm::get_grade_to_exec()const
{
	return grade_to_exec;
}

void AForm::beSigned(Bureaucrat &b)
{
	if(get_is_signed())
		throw std::runtime_error("form is already signed");
	if(b.getGrade() > get_grade_to_sign())
	throw GradeTooLowException();	
	// else
	is_signed = 1;
}
std::ostream& operator<<(std::ostream& os, const AForm& b)
{

	os <<  "AForm :"<<b.get_form_name() << " signed: " <<b.get_is_signed() <<" grade to sign: "<<b.get_grade_to_sign() << " grade to execute: " << b.get_grade_to_exec()<< ".";
	return os;
}