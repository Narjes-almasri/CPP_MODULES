#include "Base.hpp"

int main()
{
	std::srand(std::time(nullptr)); 
// 	Base * generate(void);
// int ft_random();
// void identify(Base* p);
// void identify(Base& p);
	Base *h =NULL;
	std::cout<<"the random class is = ";
	h = generate();
	std::cout<<"--------\n";
	std::cout<<"identify the class by passing pointer = ";
	identify(h);
	std::cout<<"--------\n";
	std::cout<<"identify the class by passing referance = ";
	identify(h);
delete h;
}