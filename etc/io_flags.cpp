#include <iostream>

int main()
{
	using namespace std;
	
	cout << "ios::goodbit\t" << ios::goodbit << endl;
	cout << "ios::badbit\t" << ios::badbit << endl;
	cout << "ios::eofbit\t" << ios::eofbit << endl;
	cout << "ios::failbit\t" << ios::failbit << endl;
	
	cin.clear(ios::badbit);
	//cin.setstate(ios::eofbit);
	
	cout << "\ncin.rdstate()\t" << cin.rdstate() << endl << endl;
	
	cout << "cin.good()\t" << cin.good() << endl;
	cout << "cin.bad()\t" << cin.bad() << endl;
	cout << "cin.eof()\t" << cin.eof() << endl;
	cout << "cin.fail()\t" << cin.fail() << endl;
	
	return 0;
}