#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
	private:
	std::string pardon_target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string pardon);
	PresidentialPardonForm(PresidentialPardonForm const &n);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &n);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};
#endif