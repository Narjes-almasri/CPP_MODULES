#include "Contact.hpp"
#include "PhoneBook.hpp"


int main()
{
	std::string cmd;
	PhoneBook b;

	while(1)
	{
		std::cout<<"enter ADD, SEARCH or EXIT\n";
		std::getline(std::cin,cmd);
		if (!std::cin)
			return (0);
		if(cmd == "ADD")
			b.addCont();
		if(cmd == "SEARCH")
			b.searchCont();
		if(cmd == "EXIT")
			break;
	}
		
}