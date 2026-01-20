#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// // int main()
// // {
// //     std::cout << "=== EX02: Advanced Forms ===" << std::endl;

// //     // Create bureaucrats
// //     Bureaucrat boss("Boss", 1);
// //     Bureaucrat mid("Mid", 50);
// //     Bureaucrat low("Low", 140);

// //     // Shrubbery Form
// //     std::cout << "\n--- Shrubbery Form ---" << std::endl;
// //     ShrubberyCreationForm shrub("home");
// //     low.signForm(shrub);     // low grade 140 ≤ 145 → OK
// //     // low.executeForm(shrub);  // 140 > 137 → should fail
// //     // mid.executeForm(shrub);  // 50 ≤ 137 → OK

// //     // // Robotomy Form
// //     // std::cout << "\n--- Robotomy Form ---" << std::endl;
// //     // RobotomyRequestForm robot("Wall-E");
// //     // mid.signForm(robot);     // 50 ≤ 72 → OK
// //     // low.executeForm(robot);  // 140 > 45 → fail
// //     // boss.executeForm(robot); // 1 ≤ 45 → success (50% chance)

// //     // // Presidential Pardon
// //     // std::cout << "\n--- Presidential Pardon ---" << std::endl;
// //     // PresidentialPardonForm pardon("Arthur Dent");
// //     // boss.signForm(pardon);   // 1 ≤ 25 → OK
// //     // mid.executeForm(pardon); // 50 > 5 → fail
// //     // boss.executeForm(pardon); // 1 ≤ 5 → success

// //     // std::cout << "\n=== Done ===" << std::endl;
// //     return 0;
// // }

// int main()
// {
//     // try {
//     //     Bureaucrat intern("Intern", 1);
//     //     ShrubberyCreationForm form("home");
        
//     //     intern.signForm(form);      // ✓ Can sign (grade 140 <= 145)
//     //     form.execute(intern);   // ✓ Can execute (grade 140 <= 137)
        
//     //     // A file named "home_shrubbery" is created with ASCII trees!
        
//     // } 
//     // catch (std::exception & e) 
//     // {
//     //     std::cout << e.what() << std::endl;
//     // }
//     ///////////////////////////////
//     //robotmyrequest//////////////
// //      srand(time(NULL));  // ← Important! Seeds random number generator
// // try {
// //         Bureaucrat bob("Bob", 40);
// //         RobotomyRequestForm robot("Bender");
        
// //         bob.signForm(robot);
// //         robot.execute(bob);
        
// //     } 
// //     catch (std::exception & e) 
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
//     /////////////pardooon
//     try
//     {
//        Bureaucrat b("sara",1);
//        PresidentialPardonForm v("uni");
//        b.signForm(v);
//        v.execute(b);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
//     return 0;
// }
int main()
{
    srand(time(NULL));
    
    try {
        // Different grade levels
        Bureaucrat intern("Intern", 140);
        Bureaucrat employee("Employee", 50);
        Bureaucrat boss("Boss", 1);
        
        std::cout << "=== Test 1: Shrubbery (Easy) ===" << std::endl;
        ShrubberyCreationForm shrub("garden");
        intern.signForm(shrub);     
        intern.executeForm(shrub);  
        
        std::cout << "\n=== Test 2: Robotomy (Medium) ===" << std::endl;
        RobotomyRequestForm robot("Bender");
        intern.signForm(robot);      
        employee.signForm(robot);    
        employee.executeForm(robot); 
        boss.executeForm(robot);    
        
        std::cout << "\n=== Test 3: Presidential (Hard) ===" << std::endl;
        PresidentialPardonForm pardon("Arthur");
        employee.signForm(pardon);   
        boss.signForm(pardon);       
        boss.executeForm(pardon);   
        
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}