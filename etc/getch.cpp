#include <iostream>
#include <conio.h>
// #include <Windows.h>

int main()
{
	int key;
	
	std::cout << "Input some key. Press Esc or Ctrl+C to exit. Ctrl + Z to clear" << std::endl;
	while(key != 27 && key != 3)
	{
		key = _getch();		// bash do not work properly with getch
		std::cout << key << std::endl;
		
		if (key == 26) system("cls");
		// Sleep(1000);
		// FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		// fflush(STDIN_FILENO);				
		// std::cin.ignore(256,'\n');
		//STDIN_FILENO
	}
	


	return 0;
}