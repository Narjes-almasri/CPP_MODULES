/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:58:47 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:58:48 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "HumanB.hpp"


HumanB::HumanB(std::string n):name(n)
{
	weapon = 0;
}
void HumanB::attack()
{
	if(HumanB::weapon != 0)
	std::cout<<name<<" attacks with their " << HumanB::weapon->getType()<<"\n";
}

void HumanB::setWeapon(Weapon& w)
{
	weapon = &w;
}