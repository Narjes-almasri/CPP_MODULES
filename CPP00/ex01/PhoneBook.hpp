
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
	int i;

	public:
	PhoneBook();
	void addCont();
	void searchCont();
};

#endif