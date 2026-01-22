#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
// #include "cstdint.h"
#include "Data.hpp"
class Serializer
{
	private:
	Serializer();
	Serializer(Serializer const &n);
	Serializer &operator=(Serializer const &n);
	~Serializer();
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
