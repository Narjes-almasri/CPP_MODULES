#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// #include <iostream>
// #include <exception> 
// class Bureaucrat
// {
// 	private:
// 	const std::string name;
// 	int grade;

// 	public:
// 	Bureaucrat();
// 	Bureaucrat(const std::string &n,int g);
// 	Bureaucrat(const Bureaucrat &n);
// 	Bureaucrat &operator=(const Bureaucrat &n);
// 	~Bureaucrat();
	
// 	int getGrade() const;
// 	// std::string getName();
// 	const std::string& getName() const;
	
// 	void incrementGrade();
// 	void decrementGrade();
	
// 	class grade_too_high : public std::exception
// 	{
// 		public:
// 		virtual const char* what() const throw() //see why
// 		{
// 			// std::cout<< "grade is toooo high\n";
// 			return ("grade is toooo high");
// 		}
// 	};
// 	class grade_too_low : public std::exception
// 	{
// 		public:
// 		virtual const char* what() const throw() //see why
// 		{
// 			// std::cout<< "grade is toooo low\n";
// 			return ("grade is toooo low");
// 		}
// 	};
	
// };
// std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
//
#include <iostream>
#include <stdexcept>
class Bureaucrat 
{
	private:
	const std::string name;// immutable name ==>Immutable means "cannot be changed after creation".
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string n,int g);
	Bureaucrat(const Bureaucrat &n);
	Bureaucrat &operator=(const Bureaucrat &n);
	~Bureaucrat();
	std::string getName()const;
	int getGrade() const;

	void incrementBur();
	void decrementBur();

	class GradeTooHighException :public std::runtime_error
	{
		public:
		GradeTooHighException() : std::runtime_error("Grade is tooooo high"){}
	};
	class GradeTooLowException : public std::runtime_error
	{
		public:
		GradeTooLowException () : std::runtime_error("Grade is too low"){}
	};

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
 #endif

 /*
 
 throw GradeTooHighException()
    ↓
Constructor passes "Grade is tooooo high" to runtime_error ==>here (does it mean it sends this msg to the what() in the runtime_error  class?)
    ↓
runtime_error stores it internally ==> in the the what() in the runtime_error  class ?
    ↓
catch (std::exception& e)==>this e will call the what in the runtime_error class right how did she know? cuz the error happen from an obj of class Bureaucrat that has inside it the customised exception that inherits from runtime_error class 
    ↓
e.what() → runtime_error returns the stored message
    ↓
Output: "Grade is tooooo high"
 
 */