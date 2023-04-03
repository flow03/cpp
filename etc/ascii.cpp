#include <iostream>
#include <Windows.h>

int main()
{
	//setlocale(LC_ALL, "RUS");
	
	for (int i = 0; i < 256; ++i)
	{
		setlocale(LC_ALL, "RUS");
		std::cout << i << ' ' << static_cast<char>(i);
		setlocale(LC_ALL, "C");
		std::cout << ' ' << static_cast<char>(i) << std::endl;
	}
	
	return 0;
}