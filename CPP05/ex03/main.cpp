#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;

    // Test all forms
    AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
    AForm* f4 = someRandomIntern.makeForm("unknown form", "Nobody");

    // Optional: execute to check behavior (requires proper Bureaucrat)
    Bureaucrat boss("Boss", 1);
    if (f1) boss.executeForm(*f1);
    if (f2) boss.executeForm(*f2);
    if (f3) boss.executeForm(*f3);

    // Clean up memory
    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
