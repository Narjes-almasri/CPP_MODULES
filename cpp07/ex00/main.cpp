#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;
	Whatever::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << Whatever::min( a, b ) << std::endl;
	// so here when we created the function template no code was created but when we called the function with int
	//  and double the compiler created two functions one for int and one for double.
	std::cout << "max( a, b ) = " << Whatever::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	Whatever::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << Whatever::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << Whatever::max( c, d ) << std::endl;
	return 0;
}
/*
Should output:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/