/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <naalmasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:59:10 by naalmasr          #+#    #+#             */
/*   Updated: 2025/10/18 19:59:14 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int ac,char **av)
{
	std::string line;
	std::string res;
	size_t ind ;
	int current_pos=0;

	if(ac == 4)
	{
		std::string s1 = std::string(av[2]);
		std::string s2 = std::string(av[3]);
		std::ifstream in_file(av[1]);
		int len= s1.length();
		
		if(s1.empty() || s2.empty())
		{
				std::cout<<"error in arguments !\n";
				in_file.close();
				return 0;
		}
		std::string filename = std::string(av[1]) + ".replace";
		std::ofstream out_file(filename.c_str());
		if(in_file.is_open())
		{
			while(std::getline(in_file,line))
			{
				res="";
				current_pos = 0;

				while(1)
				{
						ind = line.find(s1,current_pos);
						if(ind == std::string::npos)
						{
							res += line.substr(current_pos);
							break;
						}
						{
							res += line.substr(current_pos, ind - current_pos);
							res+=  s2;
							current_pos= ind + len;
						}
						 
				}
					out_file<< res << "\n";
			}
			out_file.close();
			in_file.close();
		}
		else
			
		{
			std::cout<<"error : file cant open!\n";
		}

	}
	else
	{
		std::cout<<"error : number of arguments are wrong!\n";
	}
	return 0;
}