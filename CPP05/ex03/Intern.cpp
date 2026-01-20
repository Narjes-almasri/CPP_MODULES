#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}
AForm *Intern::makeForm(std::string const &name,std::string const &target)
{
	AForm *form;
	std::string arr[3] ={"shrubbery creation", "robotomy request", "presidential pardon"};
		if(arr[0] == name)
		{
			
			form = new ShrubberyCreationForm(target);
			std::cout <<"Intern creates " << name <<"\n";
			return form;
		}
		else if(arr[1] == name)
		{
			form = new RobotomyRequestForm(target);
			std::cout <<"Intern creates " << name <<"\n";
			return form;
		}
		else if(arr[2] == name)
		{
			form = new PresidentialPardonForm(target);
			std::cout <<"Intern creates " << name <<"\n";
			return form;
		}
	else
	{
		std::cout <<"error "<<"Intern cannot create "<<name<<"\n";
			return NULL;
	}
}
/*
core idea we will make intern class and give it 
form name and target thenn he will see if this target is one of 
the 3 options then will allocates print  and return a pointer then he did that job if not he will print error msg and
 return null cuz subject said (//The exercise explicitly says: It returns a pointer to a AForm object.In C++, a pointer must point to an object in memory.)
*/