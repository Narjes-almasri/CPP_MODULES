#include "PhoneBook.hpp"

PhoneBook::PhoneBook()//this means Every time a PhoneBook object is created, set i to 0.” 
{
	i = 0;
}

static void print_list(int index, const std::string& first, const std::string& last, const std::string& nick) {
	
    std::string f; 
    if (first.length() > 10)
        f = first.substr(0, 9) + ".";
    else
        f = first;

    std::string l; 
    if (last.length() > 10)
        l = last.substr(0, 9) + ".";
    else
        l = last;

    std::string n;
    if (nick.length() > 10)
        n = nick.substr(0, 9) + ".";
    else
        n = nick;

    std::cout << std::right<< std::setw(10) << index << "|" << std::setw(10) << f << "|"<< std::setw(10) << l << "|" << std::setw(10) << n << std::endl;
}


void PhoneBook::addCont()
{
	/*
		This means:

		Each time the user types ADD, only one contact should be added.
		Your loop adds 8 contacts in a row without returning to the main menu → breaks the command loop.
		✅ Correct behavior:

		User types ADD → program asks for one contact → saves it → goes back to “Enter command:”
		Next ADD → adds another (or overwrites oldest if full)
		So addContact() must add exactly one contact per call — not 8.
	*/

	Contact c; //Every time you call addContact(), you create one temporary Contact called c


	if(!c.fill())//You fill it with user input
	{
		std::cout<<"contact cant save an empty field \n";
		return;
	}
		contacts[i%8]= c;//Now you need to save it into the array//Put this new contact in the correct slot — and if we’re past 8, wrap around and replace the oldest.”
		i++;//= total number of contacts ever added (starts at 0)//so next time, we know how many we’ve added in total (even if we overwrote some)
}
void PhoneBook::searchCont()
{
	int n = i;
	std::string ind;
	int j=0;
	if(n > 8)
	{
		n = 8;
	}
int fl=1;
	if(fl==1)
	{
		std::cout<<std::right<< std::setw(10)<< "index " << "| " << "firstName" << "| " << "lastName" << " | " << "nickeName" << " |\n";
		fl=0;
	}
	while(j < n)	
	{
		print_list(j,contacts[j].get_Firs_tName(),contacts[j].get_Last_tName(),contacts[j].get_nickname());
		j++;
	}
	if(i == 0)
	{
		std::cout<<"there is nothing to search for cuz its empty\n";
		return;
	}	
	std::cout<<"enter an index:\n";
	std::getline(std::cin,ind);
	if (ind.length() != 1 || ind[0] < '0' || ind[0] > '7')
    	return;
	int indd = ind[0] - '0';
	if(indd > 8)
	{
		std::cout<<"you have entered an index thats not exist\n";
		return;
	}

		std::cout << "First name: " << contacts[indd].get_Firs_tName() << std::endl;
    	std::cout << "Last name: " << contacts[indd].get_Last_tName() << std::endl;
    	std::cout << "Nickname: " << contacts[indd].get_nickname() << std::endl;
    	std::cout << "Phone number: " << contacts[indd].get_phone() << std::endl;
    	std::cout << "Darkest secret: " << contacts[indd].get_darkest_secret() << std::endl;

}