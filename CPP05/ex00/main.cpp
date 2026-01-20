#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // try {
    //     Bureaucrat boss("Boss", 1);  // invalid!
    //      std::cout << boss  << std::endl;
    //      boss.incrementBur();
    //     std::cout << boss  << std::endl;
    // }
    // catch (const std::exception& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }
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
try{
    Bureaucrat d("sara",150);
    std::cout<<d<<"\n";
    d.decrementBur();
    std::cout<<d<<"\n";
}
catch (const std::runtime_error&e)//
{
    std::cout<<"error: " << e.what() << "\n";
}
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

// #include "Bureaucrat.hpp"
// #include <iostream>

// int main()
// {
//     std::cout << "=== Testing Bureaucrat ===" << std::endl;

//     // ✅ 1. Valid creation
//     try {
//         Bureaucrat bob("Bob", 75);
//         std::cout << "1. Created: " << bob << std::endl;
//     }
//     catch (const std::exception& e) {
//         std::cout << "1. Error: " << e.what() << std::endl;
//     }

//     // ❌ 2. Grade too high (0)
//     try {
//         Bureaucrat top("Top", 0);
//     }
//     catch (const std::exception& e) {
//         std::cout << "2. Caught: " << e.what() << std::endl;
//     }

//     // ❌ 3. Grade too low (200)
//     try {
//         Bureaucrat low("Low", 200);
//     }
//     catch (const std::exception& e) {
//         std::cout << "3. Caught: " << e.what() << std::endl;
//     }

//     // ✅➡️❌ 4 & 5. Promotion tests
//     try {
//         Bureaucrat b("Promotable", 2);
//         std::cout << "4. Before promotion: " << b << std::endl;
//         b.incrementGrade();  // 2 → 1
//         std::cout << "5. After promotion: " << b << std::endl;
//         b.incrementGrade();  // 1 → 0 → should throw
//     }
//     catch (const std::exception& e) {
//         std::cout << "5. Promotion error: " << e.what() << std::endl;
//     }

//     // ✅➡️❌ 6 & 7. Demotion tests
//     try {
//         Bureaucrat b("Demotable", 149);
//         std::cout << "6. Before demotion: " << b << std::endl;
//         b.decrementGrade();  // 149 → 150
//         std::cout << "7. After demotion: " << b << std::endl;
//         b.decrementGrade();  // 150 → 151 → should throw
//     }
//     catch (const std::exception& e) {
//         std::cout << "7. Demotion error: " << e.what() << std::endl;
//     }

//     // ✅ 8. Copy constructor
//     try {
//         Bureaucrat original("CopyMe", 50);
//         Bureaucrat copy = original;  // calls copy constructor
//         std::cout << "8. Original: " << original << std::endl;
//         std::cout << "   Copy:    " << copy << std::endl;
//     }
//     catch (const std::exception& e) {
//         std::cout << "8. Copy error: " << e.what() << std::endl;
//     }

//     // ✅ 9. Assignment operator
//     try {
//         Bureaucrat a("Alice", 10);
//         Bureaucrat b("Bob", 20);
//         std::cout << "9. Before assignment: a=" << a << ", b=" << b << std::endl;
//         a = b;  // calls operator=
//         std::cout << "   After assignment: a=" << a << ", b=" << b << std::endl;
//         // Note: names stay the same (const), only grade changes
//     }
//     catch (const std::exception& e) {
//         std::cout << "9. Assignment error: " << e.what() << std::endl;
//     }

//     // ✅ 10 & 11. Getters and printing
//     try {
//         Bureaucrat b("GetterTest", 100);
//         std::cout << "10. getName(): \"" << b.getName() << "\"" << std::endl;
//         std::cout << "11. getGrade(): " << b.getGrade() << std::endl;
//         std::cout << "12. Full print: " << b << std::endl;
//     }
//     catch (const std::exception& e) {
//         std::cout << "10-12. Getter error: " << e.what() << std::endl;
//     }

//     std::cout << "\n=== All tests completed ===" << std::endl;
//     return 0;
// }