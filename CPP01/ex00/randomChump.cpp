/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:57:44 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:57:45 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie z(name);
	z.name = name;
	std::cout<<name << " : " ;
	z.announce();
}
