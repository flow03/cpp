// strtype4.cpp -- line input
#include <iostream>
#include <string>               // make string class available
#include <cstring>              // C-style string library
#include <Windows.h>			// SetConsoleCP, SetConsoleOutputCP
#include <io.h>
#include <fcntl.h>

int main()
{
	//setlocale(LC_ALL,"RUS");
    using namespace std;
	
	// SetConsoleCP(CP_UTF8);		// Unicode (UTF-8) CP_UTF8 65001
	// SetConsoleOutputCP(CP_UTF8);	// Unicode (UTF-8)
	
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	
	char arr0[]		=  "Текст для прикладу";
	wchar_t arr1[] 	= L"Текст для прикладу";
	char16_t arr2[] = u"Текст для прикладу";
    char32_t arr3[] = U"Текст для прикладу";
	
	string str0		=  "Текст для прикладу";
	wstring str1	= L"Текст для прикладу";
	u16string str2	= u"Текст для прикладу";
	u32string str3	= U"Текст для прикладу";
	
	wchar_t arr_en[]= L"Some text";
	wstring str_en	= L"Some text";
		
	wcout << setlocale(LC_ALL, "RUS") << endl << endl;	// RUS or .1251, without this ru wcout will fail(flagged std::ios::failbit)
	// std::setlocale(LC_ALL, "C");
	// setlocale(LC_CTYPE, ".UTF-8");
	
	// -finput-charset=UTF-8 -fexec-charset=UTF-8
	
	cout << "cout char:\t\t" << arr0 << endl;
	cout << "cout wchar_t:\t\t" << arr1 << endl;		// 0x22fe00
	cout << "cout wchar_t eng:\t" << arr_en << endl;	// 0x22fd10
	cout << "cout string:\t\t" << str0 << endl << endl;
	// cout << "cout  wstring: " << str1 << endl;	// compilation error
	// cout << "cout  wstring eng: " << str_en;		// compilation error
	// cout << "cout u16string: " << str2 << endl;	// compilation error
	// cout << "cout u32string: " << str3 << endl;	// compilation error
	
	wcout << "wcout char:\t\t" << arr0 << endl;
	wcout << "wcout wchar_t:\t\t" << arr1 << endl;
	wcout << "wcout wchar_t eng:\t" << arr_en << endl;
	// wcout << "wcout string: " << str0 << endl;	// compilation error
	wcout << "wcout wstring:\t\t" << str1 << endl;
	wcout << "wcout wstring eng:\t" << str_en << endl;
	// wcout << "wcout u16string: " << str2 << endl;// compilation error
	// wcout << "wcout u32string: " << str3 << endl;// compilation error
	
	// wcout << endl;
	
	wcout << "\nНазвание\tЭлемент\tМассив\tКоличество" << endl << endl; 
	// wcout << "char\t\t" 
	// << sizeof(arr0[0]) 
	// << '\t' << sizeof(arr0) 
	// << '\t' << strlen(arr0) + 1 << endl; // \0
	// wcout << "wchar_t \t" 
	// << sizeof(arr1[0]) 
	// << '\t' << sizeof(arr1) 
	// << '\t' << sizeof(arr1)/sizeof(arr1[0]) << endl;
	// wcout << "char16_t\t" 
	// << sizeof(arr2[0]) 
	// << '\t' << sizeof(arr2) 
	// << '\t' << sizeof(arr2)/sizeof(arr2[0]) << endl;
	// wcout << "char32_t\t" 
	// << sizeof(arr3[0]) 
	// << '\t' << sizeof(arr3) 
	// << '\t' << sizeof(arr3)/sizeof(arr3[0]) << endl << endl;
	
	// wcout << "string\t\t"
	// << sizeof(str0[0]) 
	// << '\t' << sizeof(str0)
	// << '\t' << str0.size() + 1 << endl;
	// wcout << "wstring\t\t"
	// << sizeof(str1[0])
	// << '\t' << sizeof(str1)
	// << '\t' << str1.size() + 1 << endl;
	// wcout << "u16string\t"
	// << sizeof(str2[0])
	// << '\t' << sizeof(str2)
	// << '\t' << str2.size() + 1 << endl;
	// wcout << "u32string\t"
	// << sizeof(str3[0])
	// << '\t' << sizeof(str3)
	// << '\t' << str3.size() + 1 << endl;
	
	wcout << endl << L"Ну шо, шановні, догрались?\n";
	
	cout << endl << endl;
	if (wcout.good()) cout << "wcout.good\n";
	else if (wcout.fail()) cout << "wcout.fail\n";
	if (cout.good()) cout << "cout.good\n";
	else if (cout.fail()) cout << "cout.fail\n";
    
	// while (!cin.fail())
	// {
		// cout << "Ввод строки: ";			// Кириллица занимает 2 байта в памяти.
		// cin.get(arr, size_).get();		// Соответственно, при попытке считать 1 байт 2-байтового символа 
											// с помощью второго метода get(), который призван считывать символ конца строки,
											// второй байт кириллического слова остаётся во входной очереди. Как следствие, 
											// он попадает в следующий вызов метода get() наряду с оставшимися двухбайтовыми символами
		// cout << arr << endl;
		// cout << "Длина arr в конце: " << strlen(arr) << endl;
	// }
	
	// Symbols
	const unsigned char symbolHero = 2;
	// const unsigned char symbolWall = 219;
	// const unsigned char symbolBox = 254;
	// const unsigned char symbolExit = 176;
	const unsigned char symbolCrystal = 3;
	const unsigned char symbolDoorV = 186;
	const unsigned char symbolDoorG = 205;
	// const unsigned char symbolPortal = 79;
	// const unsigned char symbolKey = 21;
	// const unsigned char symbolBomb = 15;
	
	// std::wcout << "symbolWall " << (wchar_t)symbolWall << std::endl;
	// std::wcout << "symbolExit " << (wchar_t)symbolExit << std::endl;
	wchar_t * str = L"Мій рядок\x2660\n";
    std::wcout<<str<<std::endl;
	
	std::cout << "symbolDoorV " << symbolDoorV << std::endl;
	std::cout << "symbolDoorG " << symbolDoorG << std::endl;
	
	std::wcout << L"\x00FF" << std::endl; 
	
	// std::wcout << (wchar_t)1062 << std::endl;
	// std::wcout << (wchar_t)1030 << std::endl;
	// std::wcout << (wchar_t)1031 << std::endl;
	// std::wcout << (wchar_t)1132<< std::endl;
	// std::wcout << (wchar_t)1066 << std::endl;
	
	//█⑬
	
    return 0; 
}
