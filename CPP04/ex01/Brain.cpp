#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"brain defualt constractor called\n";
}
Brain::Brain(const Brain& d)
{
	std::cout<<"brain copy constractor called\n";
	int i = 0;
	while (i < 100)
	{
		ideas[i] = d.ideas[i];
		i++;
	}
}
Brain &Brain::operator=(const Brain& d)
{
	std::cout<<"brain copy assignment constractor called\n";
	if(this != &d)
	{
		int i = 0;
		while (i < 100)
		{
			ideas[i] = d.ideas[i];
			i++;
		}
	}
	return (*this);
}
Brain::~Brain()
{
	std::cout<<"brain destractor called\n";
	
}