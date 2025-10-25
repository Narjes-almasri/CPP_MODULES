/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:57:36 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:57:37 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie *z = new Zombie(name);
	z->name = name;
	std::cout<<name << " : " ;
	z->announce();
	return (z);
}