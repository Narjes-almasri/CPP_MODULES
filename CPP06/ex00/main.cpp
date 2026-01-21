#include "ScalarConverter.hpp"

// ➜ Narjes@MacBook ~/Desktop/42/cpp06/ex00 % ./convert  "'c'"
// char: 'c'
// int : 99
// float : 99.0f
// double : 99.0

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    
    return 0;
}


// int main()
// {
//     ScalarConverter::convert("0");
//     std::cout << "---\n";

// 	/* 
// 		• what is inf / inff?
// 			inf / inff (Infinity)
// 			Represents positive infinity (∞)
		
// 			inf → double version
// 			inff → float version
// 		-----------
// 		+inf / +inff (Positive Infinity)
// 		Same as inf / inff
// 		Explicitly positive: +∞	
// 		-----------
// 		-inf / -inff (Negative Infinity)
// 		Represents negative infinity (-∞)

// 		==>Infinity and NaN are not whole numbers - they're mathematical concepts
// 			That's why you print "impossible" 
// 	*/
//     ScalarConverter::convert("-inff");
//     std::cout << "---\n";

//     ScalarConverter::convert("+inff");
//     std::cout << "---\n";
//  //////////////////////
// 	/* 
// 	• what is nan?
// 		nan / nanf (Not a Number)
// 		Represents an undefined or unrepresentable value
		
// 		nan → double version
// 		nanf → float version
// 	*/
//     ScalarConverter::convert("nan");
//     std::cout << "---\n";
    
//     ScalarConverter::convert("42.0f");
//     std::cout << "---\n";
    
//     ScalarConverter::convert("'c'");
//     std::cout << "---\n";
    
//     ScalarConverter::convert("-42");
//     std::cout << "---\n";
    
//     ScalarConverter::convert("+inf");
//     std::cout << "---\n";

//     ScalarConverter::convert("-inf");
    
//     return 0;
// }
