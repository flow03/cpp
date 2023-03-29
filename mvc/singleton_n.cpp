// #include <iostream>

#include "singleton_n.hpp"

namespace singleton_n
{
	// private
	static int a, b;
	// extern int c;
	int internal_sum() {return a + b;}
	
	// public
	void load() {a = 10; b = 15;}

	void out() {std::cout << a << ' ' << b << std::endl;}

	const int& get_a() {return a;}

	int sum(){return internal_sum();}
}












