#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
 {
	 (void)other;
 }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{ 
    (void)other; 
    return *this; 
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string literal) 
{
try{
	if (literal == "nan" || literal == "nanf") 
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
		return;
	}
	if (literal == "inf" || literal == "inff" || 
	literal == "+inf" || literal == "+inff" ||
	literal == "-inf" || literal == "-inff") 
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		
		if (literal[0] == '-') {
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		} else {
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}
		return;
	}
	
	if(literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		char ch = literal[1];
		// std::cout<< "char : "<<"'" << ch << "'"<< "\n";
		if (std::isprint((char) ch))
		 {
   		 std::cout << "char: '" << char(ch)<< "'\n";
		} 	
	else 
		{
   		 std::cout << "char: Non displayable\n";
		}
		
		std::cout<< "int : "<< (int)ch<< "\n";
		//std::fixed << std::setprecision(1) to force the format .0
		std::cout<< "float : "<< std::fixed << std::setprecision(1) <<(float)ch<< "f\n";
		std::cout<< "double : "<< std::fixed << std::setprecision(1) << (double)ch<< "\n";
	}
	else if((std::isdigit((int)literal[1])) || (literal[0] == '+' || literal[0] == '-'))
	{
		int  in ;
		in = std::stoi(literal);
		if (std::isprint((char) in))
   		 std::cout << "char: '" << char(in)<< "'\n";	
	else 
   		 std::cout << "char: Non displayable\n";
	
		{
			std::cout<< "int : ";
			in = std::stoi(literal);
			std::cout<<in;
			std::cout<< "\n";
		}

	std::cout<< "float : "<< std::fixed << std::setprecision(1) <<(float)in<< "f\n";
	std::cout<< "double : "<< std::fixed << std::setprecision(1) << (double)in<< "\n";
	}
	else if(literal[literal.length()-1] == 'f')
	{
		float fl =  std::stof(literal);
		// std::cout<< "char : "<<"'" << (char)fl << "'"<< "\n";
		if (std::isprint((char) fl))
		 {
   		 std::cout << "char: '" << char(fl)<< "'\n";
		} 	
	else 
		{
   		 std::cout << "char: Non displayable\n";
		}
		std::cout<< "int : "<< (int)fl<< "\n";
		//std::fixed << std::setprecision(1) to force the format .0
		std::cout<< "float : "<< std::fixed << std::setprecision(1) <<fl<< "f\n";
		std::cout<< "double : "<< std::fixed << std::setprecision(1) << (double)fl<< "\n";
	}
	else 
	{
		double dou = std::stod(literal);
		// std::cout<< "char : "<<"'" << (char)dou << "'"<< "\n";
		if (std::isprint((char) dou))
		 {
   		 std::cout << "char: '" << char(dou)<< "'\n";
		} 	
	else 
		{
   		 std::cout << "char: Non displayable\n";
		}
		if (std::isnan(dou) || std::isinf(dou)) 
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		} else
		std::cout<< "int : "<< (int)dou<< "\n";
		//std::fixed << std::setprecision(1) to force the format .0
		std::cout<< "float : "<< std::fixed << std::setprecision(1) <<(float)dou<< "f\n";
		std::cout<< "double : "<< std::fixed << std::setprecision(1) << dou<< "\n";
	}
	}
	catch(std::exception &e)
	{
		std::cout<<"error : invalid input\n";
	}
	
}
