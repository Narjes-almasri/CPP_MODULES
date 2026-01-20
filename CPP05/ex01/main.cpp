#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"
/*int main() {
    try {
        Bureaucrat boss("Boss", 1);  // invalid!
        Form f("ex01",2,3);
        f.beSigned(boss);
         std::cout << boss  << std::endl;
         std::cout << f << std::endl;
        //  boss.incrementBur();
        // std::cout << boss  << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    /////////////////////////////////////////
        // try {
        //     Bureaucrat bob("Bob", 1);
        //     std::cout << bob << std::endl;  // Bob, bureaucrat grade 1.
            
        //     bob.incrementBur();  // Should throw! Already at 1
        // }
        // catch (std::exception& e) {
        //     std::cout << "Caught: " << e.what() << std::endl;
        // }

        // try {
        //     Bureaucrat alice("Alice", 150);
        //     std::cout << alice << std::endl;  // Alice, bureaucrat grade 150.
            
        //     alice.decrementBur();  // Should throw! Already at 150
        // }
        // catch (std::exception& e) {
        //     std::cout << "Caught: " << e.what() << std::endl;
        // }
/////////////////////////////
// try{
//     Bureaucrat d("sara",150);
//     std::cout<<d<<"\n";
//     d.decrementBur();
//     std::cout<<d<<"\n";
// }
// catch (const std::runtime_error&e)//
// {
//     std::cout<<"error: " << e.what() << "\n";
// }
/////////////////////////////
    // try {
    //     Bureaucrat b("Bob", 150);
    //     b.incrementBur();  // 150 → 149 (OK)
    //     b.decrementBur();  // 149 → 150 (OK)
    //     b.decrementBur();  // 150 → 151 → 💥
    // }
    // catch (const std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }
}
*/

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void printSeparator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
    printSeparator("TEST 1: Creating Forms with Valid Grades");
    try {
        Form form1("Form A", 50, 25);
        Form form2("Form B", 1, 1);
        Form form3("Form C", 150, 150);
        
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
        std::cout << "✓ All forms created successfully!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 2: Creating Forms with Invalid Grades (Too High)");
    try {
        Form invalidForm("Invalid", 0, 50);  // Grade 0 is too high!
        std::cout << "✗ Should have thrown exception!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "✓ Caught exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 3: Creating Forms with Invalid Grades (Too Low)");
    try {
        Form invalidForm("Invalid", 50, 151);  // Grade 151 is too low!
        std::cout << "✗ Should have thrown exception!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "✓ Caught exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 4: Successful Signing");
    try {
        Form taxForm("Tax Form", 50, 25);
        Bureaucrat alice("Alice", 30);  // Grade 30 is good enough
        
        std::cout << "Before signing:" << std::endl;
        std::cout << taxForm << std::endl;
        
        alice.signForm(taxForm);
        
        std::cout << "\nAfter signing:" << std::endl;
        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 5: Failed Signing (Grade Too Low)");
    try {
        Form vipForm("VIP Form", 10, 5);
        Bureaucrat bob("Bob", 50);  // Grade 50 is not good enough
        
        std::cout << vipForm << std::endl;
        bob.signForm(vipForm);  // Should fail
        
        std::cout << "\nAfter attempt:" << std::endl;
        std::cout << vipForm << std::endl;  // Should still be unsigned
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 6: Multiple Bureaucrats Signing Same Form");
    try {
        Form document("Document", 75, 50);
        Bureaucrat alice("Alice", 30);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 100);
        
        std::cout << "Initial state:" << std::endl;
        std::cout << document << std::endl;
        std::cout << std::endl;
        
        // Alice tries (should succeed)
        alice.signForm(document);
        
        // Bob tries (form already signed)
        bob.signForm(document);
        
        // Charlie tries (form already signed)
        charlie.signForm(document);
        
        std::cout << "\nFinal state:" << std::endl;
        std::cout << document << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 7: Edge Cases - Grade 1 Bureaucrat");
    try {
        Form ceoForm("CEO Form", 1, 1);
        Bureaucrat ceo("CEO", 1);
        
        std::cout << ceoForm << std::endl;
        ceo.signForm(ceoForm);
        std::cout << ceoForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 8: Edge Cases - Grade 150 Bureaucrat");
    try {
        Form internForm("Intern Form", 150, 150);
        Form bossForm("Boss Form", 1, 1);
        Bureaucrat intern("Intern", 150);
        
        std::cout << "Intern signing intern form:" << std::endl;
        intern.signForm(internForm);  // Should succeed
        
        std::cout << "\nIntern signing boss form:" << std::endl;
        intern.signForm(bossForm);  // Should fail
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 9: Form Copy Constructor");
    try {
        Form original("Original", 50, 25);
        Bureaucrat signer("Signer", 30);
        
        signer.signForm(original);
        
        Form copy(original);
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("TEST 10: Mixed Scenarios");
    try {
        Form form1("Easy Form", 100, 80);
        Form form2("Medium Form", 50, 40);
        Form form3("Hard Form", 10, 5);
        
        Bureaucrat low("Low-Level", 120);
        Bureaucrat mid("Mid-Level", 45);
        Bureaucrat high("High-Level", 5);
        
        std::cout << "Low-Level employee attempts:" << std::endl;
        low.signForm(form1);   // ✓
        low.signForm(form2);   // ✗
        low.signForm(form3);   // ✗
        
        std::cout << "\nMid-Level employee attempts:" << std::endl;
        mid.signForm(form1);   // Already signed
        mid.signForm(form2);   // ✓
        mid.signForm(form3);   // ✗
        
        std::cout << "\nHigh-Level employee attempts:" << std::endl;
        high.signForm(form1);  // Already signed
        high.signForm(form2);  // Already signed
        high.signForm(form3);  // ✓
        
        std::cout << "\n--- Final Form States ---" << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }

    printSeparator("END OF TESTS");
    
    return 0;
}