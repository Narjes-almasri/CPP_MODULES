/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:58:40 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:58:43 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout<<HumanA::name<<" attacks with their " << HumanA::weapon.getType()<<"\n";
}



/*
HumanA::HumanA(std::string n, Weapon& w) {
    name = n;      // works, but inefficient (assigns after default construct)
    weapon = w;    //  ERROR: reference not initialized!
}
	The compiler will reject this because weapon is never initialized—only assigned (which isn’t allowed for references).

*/
HumanA::HumanA(std::string n, Weapon& w):name(n) ,weapon(w)
{}