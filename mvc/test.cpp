#include <iostream>
// #include <locale>
// #include <Windows.h>


int main()
{
	// unsigned char u = 0;
	// signed char s = 0;
	// char c = 0;
	
	// u = 255;
	// s = -128;
	// c = 128;
	
	// setlocale(LC_ALL, "Russian");
	
	// std::cout << "u " << u << ' ' << (int)u << std::endl;
	// std::cout << "s " << s << ' ' << (int)s << std::endl;
	// std::cout << "c " << c << ' ' << (int)c << std::endl;
	
	// for (int i = -128; i <= 127; ++i)
		// std::cout << i << '\t' << (char)i << std::endl;
	
	int a;
	int *p;
	int *s;
	
	p = &a;
	s = nullptr;
	
	*p = 3;
	// *s = 3;	// segmentation fault, спроба розіменувати нульовий вказівник
	
	std::cout << a;
	
	
	return 0;
}












