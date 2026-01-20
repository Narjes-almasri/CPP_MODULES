#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>
ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout<<"defualt const\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("idk",145,137) ,target_shurbbery(target)
{	
	std::cout<<"parametrized const\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &n)
{
	std::cout<<"copy const\n";
	target_shurbbery = n.target_shurbbery;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &n)
{
	if(this != &n)
	target_shurbbery = n.target_shurbbery;//how can i call the copy const here
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(!get_is_signed())
		throw std::runtime_error("form is not signed");
	if(executor.getGrade() > get_grade_to_exec())
	throw GradeTooLowException();

	std::string filename= target_shurbbery + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open())
        throw std::runtime_error("Could not create file");
	file << "        ccee88oo" << std::endl;
	file << "     C8O8O8Q8PoOb o8oo" << std::endl;
	file << "   dOB69QO8PdUOpugoO9bD" << std::endl;
	file << " CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "         \\'//  /douUP" << std::endl;
	file << "          \\'////" << std::endl;
	file << "           |||/'\\" << std::endl;
	file << "           |||'/" << std::endl;
	file << "            |||||" << std::endl;
	file << "      .....//||||'...." << std::endl;

	   file.close();
}
