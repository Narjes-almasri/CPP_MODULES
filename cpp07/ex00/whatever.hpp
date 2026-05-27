#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

class Whatever
{
	public:
	template <typename T>
	static void swap(T &a,T &b)
	{
		T tmp = a;
		a = b ;
		b = tmp;
	}
	template <typename T>
	static T min(T a,T b)
	{
		if(a < b)
			return a;
		else 
			return b;	
	}
	template <typename T>
	static T max(T a,T b)
	{
		if(a > b)
			return a;
		else 
			return b;	
	}
// so here when we created the function template no code was created but when we called the function with int and double the compiler created two functions one for int and one for double.

	/*
		First: what does static mean here?

		When a function is static inside a class, it means:

		The function does NOT belong to an object.
		It belongs to the class itself.
		///////////////
		swap(a, b)
		min(a, b)
		max(a, b)
		Question:
		Do these functions use:

		any class variable?

		any object data?

		this?

		❌ No.

		They only use:

		the parameters a and b
		////////////////////
		What happens if they are NOT static?
		Whatever<int> w;
		w.swap(a, b);   // you MUST create an object


		But that object:

		stores no data

		does nothing

		exists only to call the function

		That’s wasted and meaningless.

		////////////////
		Why the subject REQUIRES static

		Because the subject wants:

		Whatever::swap(a, b);
		Whatever::min(a, b);
		Whatever::max(a, b);


		This syntax only works if the functions are static.
	*/

};
#endif