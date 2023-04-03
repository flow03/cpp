#include <iostream>  
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

void fir()
{
	int num = 0;
	cin >> num; cin.ignore();
	
	// int width_ = (num*2)-1;
	int pos = num;
	int count = 1;
	
	for (int i = 0; i < num; ++i)
	{
		cout.width(pos--);
		// cout << setw(pos--);
		for (int j = 0; j < count; ++j)
			cout << '*';
		
		cout << endl;
		count+=2;
	}
	
	pos = 1;
	do
	{
		//cout.width(width_);
		cout << setw(num);
		cout << '|' << endl;
		pos++;
	}
	while (pos <= num/3);
	
	// cout << "pos " << pos << endl;
	// cout << "num " << num << endl;
	// cout << "num/3 " << num/3 << endl;
}

int main() 
{
	
	while(cin.good()) fir();

	return 0;
}
