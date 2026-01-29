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

    // // Optional: test assignment operator
    // std::cout << "\n=== Assignment Test ===" << std::endl;
    // Dog another;
    // another.setIdea(0, "Before");
    // another = original;  // uses copy assignment
    // std::cout << "After assignment, idea[0]: " << another.getBrain()->ideas[0] << std::endl;

    return 0;
}