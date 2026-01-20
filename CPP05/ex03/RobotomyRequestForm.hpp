#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	std::string robotmyreq_target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string robot_targt);
	RobotomyRequestForm(RobotomyRequestForm const &n);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &n);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};
#endif