/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:00:40 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 20:00:41 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"


int main(int ac,char **av)
{
	if(ac != 2)
	{
		std::cout<<"error : in number of args\n";
		return 0;
	}
	else
	{
		Harl k;
		std::string level = av[1];
		k.complain( level );
	}
}