#include <iostream>
#include <string>
//#include <cstdio>
//#include <cstring>


std::string getName(char * array)
{
	using namespace std;
	//char * result;
	
	string str(array);
	string::iterator iter;
	
	for (auto i = str.rbegin(); i != str.rend(); ++i)
		if (*i == '\\') 
		{
			iter = i.base();
			break;
		}
	
	//cout << *iter << endl;
	str.erase(str.begin(), iter);
	
	// for (int i = strlen(array) - 1; i > 0; --i)
		// if (array[i] == '\\') cout << array[i + 1] << endl;
		
	return str;
}

int main(int argc, char * argv[]) 
{
	using namespace std;
	
	char arr[] = "askjdnaksdkashd\\picture.png";
	
	// std::cout << "argc " << argc << std::endl;
	// for ( int i = 0; i < argc ; i++ )
		// std::cout << getName(argv[i]) << std::endl;
	
	cout << getName(arr) << endl;
	cout << getName(argv[0]);
	//cout << getName(argv[1]);

	std::cin.get();
	return 0;
}