/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:00:34 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 20:00:35 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" ;
}
void Harl::info( void )
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void )
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" ;
}
void Harl::error( void )
{
	std::cout<<"This is unacceptable! I want to speak to the manager now.\n" ;
}


void Harl::complain( std::string level )
{
	Harl obj;
	std::string arr[4]={"DEBUG","INFO","WARNING","ERROR"};
	void (Harl::*h[4])()={&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
	int level_index = 4;
	for(int i =0;i < 4 ; ++i)
	{
		if(level == arr[i])
		{
			level_index = i;
			break;
		}	
	}

	switch (level_index)
	{
		case 0:
			
		{
			std::cout<<"[ DEBUG ]" << "\n";
			(obj.*h[0])();
		}	
		case 1:
		{
			std::cout<<"[ INFO ]" << "\n";
			(obj.*h[1])();
		}
		case 2:
		{
			std::cout<<"[ WARNING ]" << "\n";
			(obj.*h[2])();

		}
		case 3:
		{
			std::cout<<"[ ERROR ]" << "\n";
			(obj.*h[3])();
			break;
		}
		default:
		std::cout<<"[ Probably complaining about insignificant problems ]\n";

	}

}


