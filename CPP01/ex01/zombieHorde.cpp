/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:58:22 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:58:25 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *z = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		// z[i]->name =name;
		 z[i].setName(name);
	}
	return (z);
}