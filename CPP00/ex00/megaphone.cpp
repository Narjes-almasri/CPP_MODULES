/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:16:15 by macbook           #+#    #+#             */
/*   Updated: 2025/10/07 13:20:19 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
int main(int ac,char **av)
{
	if(ac > 1)
	{
		int i=1;
		int j=0;
		char c;
		char letter;
		while(av[i] != NULL)
		{ 
			j = 0;
			while(av[i][j] != '\0')
			{
				if(( (av[i][j] >= 32 && av[i][j] <= 126)) && !(av[i][j] >= 'a' && av[i][j] <= 'z') )
				std::cout << av[i][j];
				else 
				{
					c = av[i][j];
					if(c >= 'a' && c <= 'z')
					letter =(char) std::toupper(c);
					std::cout << letter;
				}
				j++;
			}
			if(av[i+1] != NULL)
				std::cout << " ";
			i++;
		}
		std::cout<<"\n";
	}
	else
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
