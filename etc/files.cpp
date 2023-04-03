#include <iostream>
#include <string>
#include <fstream> 
//#include <Windows.h>

class Point
{
public:
	Point(){}
	Point(int a, int b) : a_(a), b_(b) {}
	
	void print() const { std::cout << this->a_ << ' ' <<  this->b_ << std::endl; }
	
private:
	int a_;
	int b_;

};

int main(int argc, char * argv[]) 
{
	
	setlocale(LC_ALL, "");
	
	for ( int i = 0; i < argc ; i++ )
		std::cout << argv[i] << std::endl ;

	std::string path = "d:\\bytes.txt";
	
	std::fstream fs;
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::trunc | std::ios::binary); // | std::fstream::out | std::fstream::app
	
	Point point(17, 198);
	
	if (fs.is_open())
	{	
		std::cout << "Файл " << path << " открыт\n\n";
		//getline(std::cin, path);
		fs.write((char*)&point, sizeof(Point));
		
		char arr[] = "some file text";
		fs.write(arr, sizeof(arr));
		
		char ch = 0;
		
		fs.seekg(0);	// возврат указателя потока в начало файла
		
		Point temp;
		fs.read((char*)&temp, sizeof(Point));
		temp.print();
		
		while (fs.read(&ch, sizeof(char)))  //!fs.eof()
		{
			// getline(fs, path);
			// fs >> path; // double last file string
			// std::cout << path << std::endl;
			std::cout << ch;
		}
		
		

	}
	else std::cout << "Файл НЕ открыт" << std::endl;
	
	fs.close();
	std::cout << "\n\nФайл закрыт";
	
	
	return 0;
}