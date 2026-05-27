#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
	T *d;
	unsiged int n
	Array()
	{
		d = new T[];
	}
	Array(unsiged int n)
	 {
		// T arr[n] = {};/
		d = new T[n];
	 }
	 Array(Array const &o)
	 {
		d = new T[o.n];
		for(unsigned int i=0;i<n;i++)
			d[i] = o.d[i];
	 }
	 Array &operator=(Array const &other)
	 {
			if (this != &other) {           // protect against self-assignment
			delete[] d;              // free old memory
			n = other.n;
			d = new T[n]();          // allocate new memory
			for (unsigned int i = 0; i < n; i++)
				d[i] = other.d[i]; // copy elements
			}
		return *this;
	 }
	~Array()
	{
		delete[] data;
	}
	T& operator[](unsigned int index) {
    if (index >= n)  // n is the size of the array
        throw std::out_of_range("Index out of bounds");
    return data[index]; // return reference so it can be modified
}
const T& operator[](unsigned int index) const {
    if (index >= n)
        throw std::out_of_range("Index out of bounds");
    return data[index]; // return const reference
}

};

#endif