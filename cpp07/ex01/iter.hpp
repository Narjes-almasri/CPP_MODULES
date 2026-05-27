#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
 void iter(T *address,const size_t len,void(*fun)( T&))
{
	for(size_t i =0; i < len; i++)
	{
		fun(address[i]);
	}
}

template <typename T>
 void iter(const T *address,const size_t len,void(*fun)(const T&))
{
	for(size_t i =0; i < len; i++)
	{
		fun(address[i]);
	}
}
#endif