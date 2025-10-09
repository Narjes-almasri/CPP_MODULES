#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <cctype>

class Contact 
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	
	public:
	int fill();
	std::string get_Firs_tName();
	std::string get_Last_tName();
	std::string get_phone();
	std::string get_nickname();
	std::string get_darkest_secret();

};
#endif