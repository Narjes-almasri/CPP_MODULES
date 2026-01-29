// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"


// int main() {
//     // std::cout << "=== Basic tests ===" << std::endl;
//     // const Animal* j = new Dog();
//     // const Animal* i = new Cat();

//     // delete j; 
//     // delete i; 

//     /*deep copy test*/
//     // Dog a;
//     // a.getBrain()->ideas[0] = "Original";
//     // Dog b = a;
//     // b.getBrain()->ideas[0] = "Copy";
//     // std::cout << "a's idea[0]: " << a.getBrain()->ideas[0] << std::endl; // should be "Original"
//     // std::cout << "b's idea[0]: " << b.getBrain()->ideas[0] << std::endl; // should be "Copy"
//     // std::cout << "b's idea[0]: " << b.getBrain()->ideas[0] << std::endl; // should be "Copy"
//     // std::cout << "\\\\\\\\\\\\\\\\\\Cat brain\\\\\\\\\\\\\\\\\\\\\n";
//     int n=4;
//     Animal* an[n];

//     for(int i =0; i < n/2 ; i++)
//     {
//         an[i] = new Cat();
//     }
//     std::cout << "\\\\\\\\\\\\\\\\\\\\Dog brain\\\\\\\\\\\\\\\\\\\n";
//     for(int i =n/2; i < n ; i++)
//     {
//         an[i] = new Dog();
//     }
//     std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
//     for (int i = 0; i < n; i++) 
//     {
//         an[i]->makeSound(); // test polymorphism
//         delete an[i];
//     }


// // std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";

// Dog basic;
// {
//     basic.setIdea(0 , "sara"); 
//     Dog tmp = basic;

//     std::cout<<"tmp = " <<tmp.getBrain()->ideas[0]<< "\n";
//     tmp.setIdea(0,"wow");    
//     std::cout<<"tmp = " <<tmp.getBrain()->ideas[0]<< "\n";    
//     std::cout<<"basic = "<<basic.getBrain()->ideas[0] << "\n";
// }
// std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";

// basic.setIdea(0 , "soso"); 
// std::cout<<basic.getBrain()->ideas[0] << "\n";


// return 0;
// }


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Array Test: 2 Cats + 2 Dogs ===" << std::endl;
    
    const int N = 4;
    Animal* animals[N];

    for (int i = 0; i < N / 2; ++i) {
        animals[i] = new Cat();
    }

    for (int i = N / 2; i < N; ++i) {
        animals[i] = new Dog();
    }

    // Test polymorphism
    for (int i = 0; i < N; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < N; ++i) {
        delete animals[i];
    }

    // std::cout << "\n=== Deep Copy Test: Dog ===" << std::endl;

    // Dog original;
    // original.setIdea(0, "Original");

    // Dog copy = original;         // uses copy constructor
    // copy.setIdea(0, "Copy");     // modify the copy

    // std::cout << "Original dog idea[0]: " << original.getBrain()->ideas[0] << std::endl;
    // std::cout << "Copy dog     idea[0]: " << copy.getBrain()->ideas[0] << std::endl;

    // Optional: test assignment operator
    // std::cout << "\n=== Assignment Test ===" << std::endl;
    // Dog another;
    // another.setIdea(0, "Before");
    // another = original;  // uses copy assignment
    // std::cout << "After assignment, idea[0]: " << another.getBrain()->ideas[0] << std::endl;

    return 0;
}