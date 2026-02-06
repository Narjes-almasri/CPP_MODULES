/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:57:52 by naalmasr          #+#    #+#             */
/*   Updated: 2026/02/06 20:34:41 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

Zombie::~Zombie()
{ 
	std::cout<<Zombie::name<<" Zombie destructed\n";
}

void Zombie::announce(void)
{
	std::cout<<"BraiiiiiiinnnzzzZ..."<<"\n";
}
Zombie::Zombie(std::string name) 
{
	std::cout<<"Zombie " << name << "  is created \n" ;
}