/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:57:29 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:57:30 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

int main()
{
	Zombie *soso = NULL;
	soso = soso->newZombie("soso");
	delete(soso);
	Zombie *sami = NULL;
	sami->randomChump("sami");
}