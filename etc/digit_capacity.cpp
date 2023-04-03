#include <iostream>
// #include <stdio.h>	// printf
// #include <stdlib.h>	// itoa
// #include <cstring>	// strlen
// #include <string>
// #include <sstream>	//stringstream

int digit_capacity(int num)
{
	int res = 0;
	
	while( num > 0)
	{
		num /= 10; 
		++res;
	}
		
	return res;
}

int main()
{
	int i = 0;
	
	while(std::cin.good())
	{
	std::cout << "Enter a number: ";
	std::cin >> i;
	
	// std::cout << "1/10 = " << 1/10 << std::endl; // 0
	std::cout << "digit_capacity(i) " << digit_capacity(i) << std::endl;
	}
	std::cout << "Done!";
	
	return 0;
}