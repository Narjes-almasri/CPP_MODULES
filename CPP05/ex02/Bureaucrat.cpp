#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("unknown"),grade(50)
{
	std::cout<<"Defualt const\n";
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;

}
Bureaucrat::Bureaucrat(std::string n,int g) : name(n),grade(g)
{
	if(grade < 1)
	throw GradeTooHighException();
	if(grade > 150)
	throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &n): name(n.name),grade(n.grade)
{
	std::cout<<"copy const "<<"\n";
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &n)
{
	if(this != &n)
	grade = n.grade;
	return *this;
}
Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName()const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementBur()
{
	if(grade <= 1)// check BEFORE decrementing
	throw GradeTooHighException();
	grade--;
}
void Bureaucrat::decrementBur()
{
	if(grade >= 150)// check BEFORE incrementing
	throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout<< getName() << " signed " << f.get_form_name()<<"\n";
	}
	catch(std::exception &e)
	{
		std::cout <<getName() << "  couldn’t sign " << f.get_form_name() << " because " <<	e.what() << ".\n";
	}

	
}
void Bureaucrat::executeForm(AForm const & form)const
{
	try
	{
		form.execute(*this);
		 std::cout << name << " executed " << form.get_form_name() << "\n";
	}
	catch(std::exception & e)
	{
		std::cout << name << " couldn't execute " << form.get_form_name() << " because " << e.what() << "\n";
	}
}
