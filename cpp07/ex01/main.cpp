#include "iter.hpp"

void print(int &a)
{
	std::cout<< " non const " << a << "\n";
}
	void printChar(char &c) {
    std::cout << " char: " <<  c <<"\n";
}

void printConstInt(const int &x ) {
    std::cout << " const: " << x << std::endl;
}
void printDouble(double &x) {
    std::cout <<  " double =" << x << std::endl;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    const size_t len = 5;
    iter(arr, len, print);         //non const array
	std::cout<<"----------------------------\n";
    const int cArr[3] = {10,20,30};
    iter(cArr, 3, printConstInt);   // const arr
	std::cout<<"----------------------------\n";
	double arrr[] = {1.1, 2.2, 3.3, 4.4};
	iter(arrr, 4, printDouble);
	std::cout<<"----------------------------\n";
		char letters[] = {'a', 'b', 'c', 'd'};
		iter(letters, 4, printChar);
	std::cout<<"----------------------------\n";
}


/*
very important note 
 note: candidate template ignored: deduced conflicting types for parameter 'T' ('double' vs. 'int')
    8 |  void iter(T *address,const size_t len,void(*fun)( T&,T))
      |       ^
the T doesnt except 2 parameter if they werent the same type 	  
*/