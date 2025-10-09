
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"




class PhoneBook
{
	private:
	Contact contacts[8];
	int i;//i = 0 here will cuz an error why? In C++98, you cannot initialize non-static member variables directly inside the class body like that.




	public:
	PhoneBook();//i have to made this cuz In C++98, the only way to initialize member variables when an object is created is via: A constructo
	void addCont();
	void searchCont();
};

#endif