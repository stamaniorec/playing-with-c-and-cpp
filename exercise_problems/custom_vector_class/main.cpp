#include <iostream>
#include "vector.h"

/*
	If you ever decide to further improve 
	this custom vector class for whatever reason, 
	add the following things: 
	- templates 
	- destructor 
	- make the operator<< Vector& returning

*/

int main()
{
	Vector v(5, 100);
	v.push_back(150);
	v.push_back(200);	
	std::cout << v << std::endl;

	Vector v2;
	v2.push_back(300);
	std::cout << v2 << std::endl;
	
	v2 = v;
	std::cout << v2 << std::endl;

	return 0;
}
