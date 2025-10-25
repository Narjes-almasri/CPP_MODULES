/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:58:04 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:58:05 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

int main()
{
	Zombie *s = NULL;
	s = zombieHorde(4,"sara");
	for(int i=0; i < 4 ; i++)
	{
		std::cout<<"sara ";
		s->announce();
	}
	delete []s;
return 0;	
}