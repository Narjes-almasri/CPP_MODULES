#include "Serializer.hpp"

int main()
{
	Data b("sami",20);
	uintptr_t i = Serializer::serialize(&b);
	std::cout << "converted to numerical value: " << Serializer::serialize(&b)<<"\n";

	std::cout << "converted back to pointer: " << Serializer::deserialize(i)<<"\n";
	std::cout << "the original pointer: " << &b<<"\n";

		if(&b == Serializer::deserialize(i))
		std::cout<<"pointers are equallll\n";
		else
		std::cout<<"pointers are not equal\n";

}