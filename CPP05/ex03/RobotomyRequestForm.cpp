#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "defualt const\n";
}
RobotomyRequestForm::RobotomyRequestForm(std::string robot_targt):AForm("robot",72,45),robotmyreq_target(robot_targt)
{
		std::cout << "parametarized const\n";
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &n)
{
	robotmyreq_target = n.robotmyreq_target;
	std::cout << "copy const\n";
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &n)
{
	std::cout << "copy assignment const\n";
	if(this != &n)
	robotmyreq_target = n.robotmyreq_target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(!get_is_signed())
		throw std::runtime_error("form is not signed");
	if(executor.getGrade() > get_grade_to_exec())
		throw GradeTooLowException();
	std::cout << "--bzzzzzzzt--- drill noise mn sooq al jum3a\n";
	
	if(rand()%2==0)
		std::cout << robotmyreq_target <<"has been robotomized successfully \n";
	else
	std::cout << "robotomy on " << robotmyreq_target << " failed\n";
}