#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
int ft_random()
{
	int num = (std::rand()%3);
	// std::cout<<"num = " << num << "\n";
	return num;

}

Base * generate(void)
{
	Base *b =NULL;
	int randomNum = ft_random();
	if(randomNum == 0)
	{
		b = new A();
			std::cout<<"A\n";
	}
	else if(randomNum == 1)
	{
		b = new B();
			std::cout<<"B\n";
	}
	else if(randomNum == 2)
	{
		b = new C();
			std::cout<<"C\n";
	}
	return b;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout<<"A\n";
	else if(dynamic_cast<B*>(p))
		std::cout<<"B\n";
	else if(dynamic_cast<C*>(p))
		std::cout<<"C\n";	
	// try
	// {
	// 	if(A* a = dynamic_cast<A*>(p))
	// 		{
	// 			(void)a;
	// 			std::cout<<"A\n";
	// 		}
	// if(	B* b = dynamic_cast<B*>(p))
	// 	{
	// 		(void)b;
	// 		std::cout<<"B\n";
	// 	}
	// 	if(C* c = dynamic_cast<C*>(p))
	// 	{
	// 		(void)c;
	// 		std::cout<<"C\n";
	// 	}
		
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "not one of the requierd classes"<< '\n';
	// }
}
void identify(Base& p)
{
	
	// dynamic_cast<Dog&>(ref)
	try
	{
		A& a = dynamic_cast<A&>(p);
		{
				(void)a;
				std::cout<<"A\n";
		}
		B& b = dynamic_cast<B&>(p);
		{
			(void)b;
			std::cout<<"B\n";
		}
		C& c = dynamic_cast<C&>(p);
		{
			(void)c;
			std::cout<<"C\n";
		}
		
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "not one of the requierd classes"<< '\n';
	}
	
	
}