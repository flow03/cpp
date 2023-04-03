#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 0, 1, 2, 3, 4, 5 };

	// if ( v.begin() == v.rend().base() )
		// std::cout << "v.begin() == v.rend().base()" << std::endl;

	// if ( v.end() == v.rbegin().base() )
		// std::cout << "v.end() == v.rbegin().base()" << std::endl;
	
	// std::cout << "v.begin() " << v.begin() << std::endl;
	// std::cout << "v.rend() " << v.rend() << std::endl;
	std::cout << "&*v.begin()\t\t" << &*v.begin() << std::endl;
	std::cout << "&*v.rend()\t\t" << &*v.rend() << std::endl;
	std::cout << "&*(v.rend().base())\t" << &*(v.rend().base()) << std::endl << std::endl;
	
	std::cout << "&*v.end()\t\t" << &*v.end() << std::endl;
	std::cout << "&*v.rbegin()\t\t" << &*v.rbegin() << std::endl;
	std::cout << "&*(v.rbegin().base())\t" << &*(v.rbegin().base()) << std::endl;

	return 0;
}