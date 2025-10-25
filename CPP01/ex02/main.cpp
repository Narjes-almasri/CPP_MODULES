/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:58:31 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 20:00:03 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>


int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout<<"mem address of str: " << &str << "\n";
	std::cout<<"mem address of stringPTR: " << stringPTR << "\n";
	std::cout<<"mem address of stringREF: " << &stringREF << "\n";
	std::cout<<"\n";
	std::cout<<"the value of str: " << str << "\n";
	std::cout<<"the value of stringPTR: " << *stringPTR << "\n";
	std::cout<<"the value of stringREF: " << stringREF << "\n";


	return 0;
}