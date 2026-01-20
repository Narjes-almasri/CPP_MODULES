#include "Bureaucrat.hpp"

// // Bureaucrat::Bureaucrat()
// // {
// // 	std::cout<<"Defualt const\n";
// // }
// Bureaucrat::Bureaucrat(const std::string &n,int g) : name(n),grade(g)
// {
// 	std::cout<<"initilization list\n";
// 	if(grade < 1)
// 	{
// 		throw grade_too_high();
// 	}
// 	if( grade > 150)
// 	{
// 		throw grade_too_low();
// 	}
// 	// std::cout <<"grade too high";
// }
// Bureaucrat::Bureaucrat(const Bureaucrat &n):name(n.name)
// {
// 	std::cout<<"copy const\n";
// 	grade = n.grade;
// 	//name = n.name;//this is wrong cuz we cannot assign a const like this we  must initialize const members in the initializer list  
// }

// Bureaucrat &Bureaucrat::operator=(const Bureaucrat &n)
// {
// 	//only for grade why cuz its non const like the name
// 	std::cout<<"copy assignment const\n";
// 	if(this != &n)
// 	{
// 		grade = n.grade;
// 	}
// 	return *this;
// }
// Bureaucrat::~Bureaucrat()
// {
// 	std::cout<<"Destractor\n";
// }

// int Bureaucrat::getGrade() const
// {
// 	return grade;
// }


// // std::string Bureaucrat::getName()
// const std::string& Bureaucrat::getName() const
// {
// 	return name;
// }

// void Bureaucrat::incrementGrade()
// {
// 	// try
// 	// {
// 	// 	if(grade < 150 && grade >= 1)
// 	// 		grade++;
// 	// }
// 	// catch(const std::exception& e)
// 	// {
// 	// 	std::cerr << e.what() << '\n';
// 	// }
	
// 		if(grade <= 1)
// 			throw grade_too_high();
// 		grade--;
// }
// void Bureaucrat::decrementGrade()
// {
// 	if(grade <= 150)
// 		throw grade_too_low();
// 		grade++;
// }
// std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
// {
// 	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
// 	return os;
// }

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
	// std::cout<<"here " << name << " ," <<grade <<"\n"; 
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
