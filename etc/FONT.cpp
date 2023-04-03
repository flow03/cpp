//#define FILE_
#define FONT

#include <iostream>
//#include <fstream>
//#include <vector>
#include <Windows.h>
//#include <cwchar>
//#include "PREDICAT.h"
#include <conio.h>

#ifdef FONT
//typedef BOOL(WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);     // прототип недокументированый функции
//SETCONSOLEFONT SetConsoleFont;
#endif

#ifdef FILE_
union Chars {
	char charValue;
	unsigned char ucharValue;
	wchar_t wcharValue;
};
#endif

const char* changeFamily(UINT _family, PCONSOLE_FONT_INFOEX font) {
	const char* family_name = "";

	switch (_family)
	{
	case 0:
		font->FontFamily = FF_DONTCARE;
		family_name = "FF_DONTCARE";
		break;
	case 16:
		font->FontFamily = FF_ROMAN;
		family_name = "FF_ROMAN";
		break;
	case 32:
		font->FontFamily = FF_SWISS;
		family_name = "FF_SWISS";
		break;
	case 48:
		font->FontFamily = FF_MODERN;
		family_name = "FF_MODERN";
		break;
	case 54:
		font->FontFamily = 54;
		family_name = "FF_LUCIDA";
		break;
	case 64:
		font->FontFamily = FF_SCRIPT;
		family_name = "FF_SCRIPT";
		break;
	case 80:
		font->FontFamily = FF_DECORATIVE;
		family_name = "FF_DECORATIVE";
		break;
	}
	
	
	return family_name;
}

void changeSize(UINT newN, UINT _nameCounter, PCONSOLE_FONT_INFOEX font) {

	if (_nameCounter == 0)
		switch (newN)
	{
	case 0:
		font->dwFontSize.X = 4;
		font->dwFontSize.Y = 6;
		break;
	case 1:
		font->dwFontSize.X = 16;
		font->dwFontSize.Y = 8;
		break;
	case 2:
		font->dwFontSize.X = 6;
		font->dwFontSize.Y = 9;
		break;
	case 3:
		font->dwFontSize.X = 8;
		font->dwFontSize.Y = 9;
		break;
	case 4:
		font->dwFontSize.X = 5;
		font->dwFontSize.Y = 12;
		break;
	case 5:
		font->dwFontSize.X = 7;
		font->dwFontSize.Y = 12;
		break;
	case 6:
		font->dwFontSize.X = 8;
		font->dwFontSize.Y = 12;
		break;
	case 7:
		font->dwFontSize.X = 16;
		font->dwFontSize.Y = 12;
		break;
	case 8:
		font->dwFontSize.X = 12;
		font->dwFontSize.Y = 16;
		break;
	case 9:
		font->dwFontSize.X = 10;
		font->dwFontSize.Y = 18;
		break;
	}
	else if (_nameCounter == 1)
	{
		switch (newN)
		{
		case 0:
			font->dwFontSize.X = 3;
			font->dwFontSize.Y = 5;
			break;
		case 1:
			font->dwFontSize.X = 4;
			font->dwFontSize.Y = 6;
			break;
		case 2:
			font->dwFontSize.X = 4;
			font->dwFontSize.Y = 7;
			break;
		case 3:
			font->dwFontSize.X = 5;
			font->dwFontSize.Y = 8;
			break;
		case 4:
			font->dwFontSize.X = 6;
			font->dwFontSize.Y = 10;
			break;
		case 5:
			font->dwFontSize.X = 7;
			font->dwFontSize.Y = 12;
			break;
		case 6:
			font->dwFontSize.X = 8;
			font->dwFontSize.Y = 14;
			break;
		case 7:
			font->dwFontSize.X = 10;
			font->dwFontSize.Y = 16;
			break;
		case 8:
			font->dwFontSize.X = 11;
			font->dwFontSize.Y = 18;
			break;
		case 9:
			font->dwFontSize.X = 12;
			font->dwFontSize.Y = 20;
			break;
		case 10:
			font->dwFontSize.X = 14;
			font->dwFontSize.Y = 24;
			break;
		case 11:
			font->dwFontSize.X = 17;
			font->dwFontSize.Y = 28;
			break;
		case 12:
			font->dwFontSize.X = 22;
			font->dwFontSize.Y = 36;
			break;
		case 13:
			font->dwFontSize.X = 43;
			font->dwFontSize.Y = 72;
			break;
		}
	}
	else if (_nameCounter == 2)
	{
		switch (newN)
		{
		case 0:
			font->dwFontSize.X = 2;
			font->dwFontSize.Y = 5;
			break;
		case 1:
			font->dwFontSize.X = 3;
			font->dwFontSize.Y = 6;
			break;
		case 2:
			font->dwFontSize.X = 3; 
			font->dwFontSize.Y = 7; ///-----------------
			break;
		case 3:
			font->dwFontSize.X = 4;
			font->dwFontSize.Y = 8;
			break;
		case 4:
			font->dwFontSize.X = 5;
			font->dwFontSize.Y = 10;
			break;
		case 5:
			font->dwFontSize.X = 6; 
			font->dwFontSize.Y = 12;
			break;
		case 6:
			font->dwFontSize.X = 7;
			font->dwFontSize.Y = 14;
			break;
		case 7:
			font->dwFontSize.X = 8;
			font->dwFontSize.Y = 16;
			break;
		case 8:
			font->dwFontSize.X = 8;
			font->dwFontSize.Y = 18;
			break;
		case 9:
			font->dwFontSize.X = 9;
			font->dwFontSize.Y = 20;
			break;
		case 10:
			font->dwFontSize.X = 11;
			font->dwFontSize.Y = 24;
			break;
		case 11:
			font->dwFontSize.X = 13;
			font->dwFontSize.Y = 28;
			break;
		case 12:
			font->dwFontSize.X = 17;
			font->dwFontSize.Y = 36;
			break;
		case 13:
			font->dwFontSize.X = 34;
			font->dwFontSize.Y = 72;
			break;
		}
	}
}

void changeName(UINT _nameCounter, PCONSOLE_FONT_INFOEX font)
{
	const wchar_t* _newName = L"";
	switch (_nameCounter)
	{
	case 0:
		_newName = L"Terminal";
		break;
	case 1:
		_newName = L"Lucida Console";
		font->FontFamily = 54;
		font->nFont = 6;
		break;
	case 2:
		_newName = L"Consolas";
		font->FontFamily = 54;
		font->nFont = 5;
		break;
	}
	wcscpy_s(font->FaceName, _newName);
}

int main() {

#ifdef FONT
	//HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");     // функция здесь
	//SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");   // берем ее адрес
	//if (!SetConsoleFont)
	//{
	//	std::cout << "error\n"; exit(1);
	//}   //   если ошибка
	//SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 14);  // устанавливаем 14 шрифт..


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получить консоль

	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);

	CONSOLE_SCREEN_BUFFER_INFOEX scrBuffer;
	scrBuffer.cbSize = sizeof(scrBuffer);

	_CONSOLE_CURSOR_INFO cursorInfo;

	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт
	GetConsoleScreenBufferInfoEx(hConsole, &scrBuffer);
	GetConsoleCursorInfo(hConsole, &cursorInfo);

	//Размер окна консоли
	scrBuffer.srWindow = SMALL_RECT{0,0,80,25};
	//Максимальный(растягиваемый) размер окна консоли
	scrBuffer.dwMaximumWindowSize = COORD{ 80,25 };
	//Размер буфера консоли
	scrBuffer.dwSize = COORD{ 80,25 };
	//Делаем курсор невидимым
	cursorInfo.bVisible = false;

	SetConsoleScreenBufferInfoEx(hConsole, &scrBuffer);
	SetConsoleCursorInfo(hConsole, &cursorInfo);


	UINT family = fontInfo.FontFamily; //unsigned int
	const char* family_name = "FF_DONTCARE";
	UINT newWeight = fontInfo.FontWeight;
	DWORD newN = fontInfo.nFont;
	const wchar_t* newName = fontInfo.FaceName;

	int currentKey = 0;
	UINT nameCounter = 0;
	UINT mainCounter = 0;
	
	
	short sizeX = 8;//fontInfo.dwFontSize.X;
	short sizeY = 12;//fontInfo.dwFontSize.Y;
	COORD fontSize = { sizeX, sizeY };
	
	//do
	//{
	//	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	//	system("cls");
	//	//Name
	//	std::wcout << fontInfo.FaceName << ' ' << nameCounter << '\n';
	//	//Family 
	//	std::cout << family_name << ' ' << fontInfo.FontFamily << '\n';
	//	//nFont
	//	std::cout << "nFont " << fontInfo.nFont << "\n";
	//	//FontSize
	//	fontSize = GetConsoleFontSize(hConsole, fontInfo.nFont);
	//	std::cout << "fontSize "
	//		<< fontSize.Y << ' '
	//		<< fontSize.X << '\n';
	//}
	//while (true);

	

	do {
		GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт

		//Изменение главного счётчика
		if (currentKey == 72) //↑
		{
			if (mainCounter > 0)
				--mainCounter;
		}
		else if (currentKey == 80) //↓
		{
			if (mainCounter < 3)
				++mainCounter;
		}
		else if (currentKey == 102) //F
		{
		family = 48; //unsigned int
		newWeight = 400;
		newN = 6;
		newName = L"Terminal";
		}

		//Выбор из вариантов главного счётчика
		switch (mainCounter)
		{
		case 0: //Font Name
		{
			if (currentKey == 75) //←
			{
				if (nameCounter > 0)
					--nameCounter;
				else
					nameCounter = 2;
			}
			else if (currentKey == 77) //→
			{
				if (nameCounter < 2)
					++nameCounter;
				else
					nameCounter = 0;
			}
			//changeName(nameCounter, &fontInfo);
			break;
		}
		case 1: //Family
			if (currentKey == 75) //←
			{
				if (family != 54)
				{
					if (family > 0)
						family -= 16;
					else
						family = 80;
				}
				else family = 48;
			}
			else if (currentKey == 77) //→
			{
				if (family != 54)
				{
				if (family < 80)
					family += 16;
				else
					family = 0;
				}
				else family = 64;
			}
			//changeSize(newN, &fontInfo);
		break;
		//Weight
		case 2:
			if (currentKey == 75) //←
			{
				if (newWeight > 0)
					newWeight -= 100;
			}
			else if (currentKey == 77) //→
			{
				if (newWeight < 900)
					newWeight += 100;
			}
			
		break;
		//newN
		case 3:
			if (nameCounter == 0)
			{
				if (currentKey == 75) //←
				{
					if (newN > 0)
						--newN;
				}
				else if (currentKey == 77) //→
				{
					if (newN < 9)
						++newN;
					else newN = 9;
				}
			}
			else
			{
				if (currentKey == 75) //←
				{
					if (newN > 0)
						--newN;
				}
				else if (currentKey == 77) //→
				{
					if (newN < 13)
						++newN;
				}
			}
			break;
			
		default:
		break;
		}

		changeSize(newN, nameCounter, &fontInfo);
		family_name = changeFamily(family, &fontInfo);
		changeName(nameCounter, &fontInfo);
		fontInfo.FontWeight = newWeight;

		//wcscpy_s(fontInfo.FaceName, newName);
		
		
		//fontInfo.dwFontSize.X = sizeX; //80
		//fontInfo.dwFontSize.Y = sizeY; //59 //44
		//fontInfo.FontFamily = family;  //48;
		//wcscpy_s(fontInfo.FaceName, L"Lucida Console");
		//wcscpy_s(fontInfo.FaceName, L"Arial");
		//wcscpy_s(fontInfo.FaceName, L"");

		SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый

		GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Контрольная проверка

		system("cls"); 
		//Name
		if (mainCounter == 0) std::cout << char(16) << ' ';
		std::wcout << fontInfo.FaceName << ' ' << nameCounter <<'\n';
		//Family 
		if (mainCounter == 1) std::cout << char(16) << ' ';
		std::cout << family_name << ' ' << fontInfo.FontFamily<<' '<< family <<'\n';
		if (mainCounter == 2) std::cout << char(16) << ' ';
		std::cout << "FontWeight " << fontInfo.FontWeight <<' '<< newWeight << "\n\n";
		//fontSize
		fontSize = GetConsoleFontSize(hConsole, fontInfo.nFont);
		//nFont
		if (mainCounter == 3) std::cout << char(16) << ' ';
		std::cout << "nFont " << fontInfo.nFont << " newN " << newN << "\n\n";
		//SetConsoleFontSize();
		std::cout << "fontSize "
			<< fontSize.X << ' '
			<< fontSize.Y << '\n';
		
		//sizeX и sizeY
		std::cout << "sizeX " << sizeX << " sizeY " << sizeY << "\n\n";
		//dwFontSize
		std::cout << "dwFontSize " 
			<< fontInfo.dwFontSize.X << ' ' 
			<< fontInfo.dwFontSize.Y << '\n';
		
		//Прочее
		std::cout << char(30) << char(31) << char(17) << char(16) << char(10);
		std::wcout << char(10);
		std::cout << "currentKey " << currentKey <<std::endl;
		
		std::cout << "mainCounter " << mainCounter << std::endl;
		
	} while (currentKey = _getch()); //_kbhit() проверяет была ли нажата клавиша

	//up_rows
	//const wchar_t u = 30;
	////down rows
	//const wchar_t d = 31;
	////left rows
	//const wchar_t l = 17;
	////right rows
	//const wchar_t r = 16;
	//Shape_symbol
	//const wchar_t symbol = 10;

	/*std::vector<std::vector<wchar_t>> v = {
		{L'a', L' ', 10 , 31 , 't' , '0'},
		{L'b', 16 , 17 , 'j', 't' , '0'},
		{L'c', L' ', L' ', 'j', 't' , '0'},
		{L'd', L' ', L' ', 'j', 't' , '0'}
	};
	for (auto a : v)
	{
		printContainer(a); 
		std::cout << std::endl;
	}
	std::cout << std::endl << "soignieugw efnei fbsdkh bHBSDFDSHGF Hskjdnf" << std::endl;

	auto iter = v.begin(); iter += 2;
	v.erase(iter);
	v.shrink_to_fit();

	for (auto a : v)
	{
		printContainer(a);
		std::cout << std::endl;
	}
	std::cout << std::endl;*/

#endif

#ifdef CHAR_INFO
	//const wchar_t u = 30;
	////down rows
	//const wchar_t d = 31;
	////left rows
	//const wchar_t l = 17;
	////right rows
	//const wchar_t r = 16;

	CHAR_INFO info;

	info.Char.UnicodeChar = 0;

	while (true)
	{
		++info.Char.UnicodeChar;
		std::wcout << info.Char.UnicodeChar << std::endl;
		std::cout << info.Char.UnicodeChar << std::endl;
		std::wcout << info.Char.AsciiChar << std::endl;
		std::cout << info.Char.AsciiChar << std::endl;

		
		_getch();
		system("cls");
	}
#endif

#ifdef FILE_
	/*std::cout << sizeof(char) << " char\n";
	std::cout << sizeof(wchar_t) << " wchar_t\n";
	std::cout << sizeof(unsigned char) << " unsigned char\n";
	std::cout << sizeof(signed char) << " signed char\n";*/

	Chars t;
	t.charValue = 100;
	
	std::cout << t.charValue << ' ' << sizeof(t.charValue) << " t.charValue\n";
	std::cout << t.ucharValue << ' ' << sizeof(t.ucharValue) << " t.ucharValue\n";
	std::cout << t.wcharValue << ' ' << sizeof(t.wcharValue) << " t.wcharValue\n";
	std::wcout << t.wcharValue << ' ' << sizeof(t.wcharValue) << " t.wcharValue\n";
	std::cout << sizeof(t) << " sizeof(t)\n";

	//setlocale(LC_ALL, "ru");
	

#endif

	std::cin.get();

	return 0;
}