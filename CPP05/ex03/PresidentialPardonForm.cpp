#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string pardon): AForm("pardooon",25,5),pardon_target(pardon)
{}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &n):AForm(n)
{
	pardon_target = n.pardon_target;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &n)
{
	if (this != &n)
	{
		AForm::operator=(n); 
	pardon_target = n.pardon_target;
	} 
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(!get_is_signed())
		throw std::runtime_error("form is not signed");
	if(executor.getGrade() > get_grade_to_exec())
	throw GradeTooLowException();

	std::cout<< pardon_target <<" has been pardoned by Zaphod Beeblebrox\n";
}