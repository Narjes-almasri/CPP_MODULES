#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
	private:
	std::string target_shurbbery;

	public:
	ShrubberyCreationForm (std::string target);
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &n);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &n);
	~ShrubberyCreationForm();
	
	void execute(Bureaucrat const & executor) const;
};
#endif