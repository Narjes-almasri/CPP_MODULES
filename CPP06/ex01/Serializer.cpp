#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t i = (uintptr_t) ptr;
	return i;
}
Data* Serializer::deserialize(uintptr_t raw)
{
	Data * n = (Data *)raw;
	return n;
}

////canonical
Serializer::Serializer(){}
Serializer::Serializer(Serializer const &n)
{
	(void)n;
}
Serializer &Serializer::operator=(Serializer const &n)
{
	(void)n;
	return *this; 
}
Serializer::~Serializer(){}
