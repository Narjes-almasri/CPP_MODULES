#include "Contact.hpp"
#include"stdlib.h"
int Contact::fill()
	{
		int i;
		std::cout<<"Enter the first name: " ;
		std::getline(std::cin, first_name);
		{
			int i;

			i=0;
			while (1)
			{
				if (std::isalpha(first_name[i]))
				{
					i++;
					continue;
				}
				if(first_name == "")
					return(0);
				if (first_name[i] == '\0')
					break;
				if (!std::isalpha(first_name[i]))
				{
					std::cout<<"wrong input\n" <<"Enter the first name: ";
					std::getline(std::cin, first_name);
					i = 0;
				}
			}
		}
		std::cout<<"Enter the last name: ";
		std::getline(std::cin, last_name);
		{
			i = 0;
			while (1)
			{
				if (std::isalpha(last_name[i]))
				{
					i++;
					continue;
				}
				if(last_name == "")
					return(0);
				if (last_name[i] == '\0')
					break;
				if (!std::isalpha(last_name[i]))
				{
					std::cout<<"wrong input\n" <<"Enter the last name: ";
					std::getline(std::cin, last_name);
					i = 0;
				}
			}
			if(last_name == "")
				return(0);
		}	
		std::cout<<"Enter the nickname: ";
		std::getline(std::cin, nickname);
		{
			for(int i=0;i < (int)nickname.length();i++)
			{
				if((std::isspace((nickname[i]))))
					continue;		
			}
			if(nickname == "")
			return(0);
		}
		std::cout<<"Enter the phone number: ";
		std::getline(std::cin, phone_number);
		{
			i = 0;
			while (1)
			{
				if (std::isdigit(phone_number[i]))
				{
					i++;
					continue;
				}
				if(phone_number == "")
					return(0);
				if (phone_number[i] == '\0')
					break;
				if (std::isalpha(phone_number[i]))
				{
					std::cout<<"wrong input\n" <<"Enter the phone_number : ";
					std::getline(std::cin, phone_number);
					i = 0;
				}
			}
			if(phone_number == "")
				return(0);
		}
		std::cout<<"Enter the darkest secret: ";
		std::getline(std::cin, darkest_secret);
		if(darkest_secret == "")
			return(0);
		std::cout<<"-------------------------------------------\n";	
		return 1;
	}

	std::string Contact::get_Firs_tName()
	{
		return first_name;
	}
	std::string Contact::get_Last_tName()
	{
		return last_name;
	}
	std::string Contact::get_phone()
	{
		return phone_number;
	}
	std::string Contact::get_nickname()
	{
		return nickname;
	}
	std::string Contact::get_darkest_secret()
	{
		return darkest_secret;
	}