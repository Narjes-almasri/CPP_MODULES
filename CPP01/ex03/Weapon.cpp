/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:58:59 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:59:01 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

	const std::string &Weapon::getType()const
	{
		return(Weapon::type);
	}

	void Weapon::setType(std::string setw)
	{
		this->type = setw;
	}
	Weapon::Weapon(std::string d)
	{
		this->type = d;
	}