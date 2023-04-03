#include <iostream>
#include <string>
//#include <vector>
//#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool is_prime(int num)
{
    bool res = true;
    for (int i = 2; i < num; ++i)
        if ((num%i) == 0) res = false;

    return res;
}

int main()
{
   
    string str;

    for(int i = 2; ; ++i)
	{
        if (is_prime(i)) str+=to_string(i);
		if (str.size() > 14000) break;
	}

    //cout << str << endl;
	cout << "size " << str.size() << endl;
	
	int n;
	while (cin.good())
	{
	cout << "Введіть число: ";
    cin >> n; cin.ignore();

    //cout << stoi(to_string(str[n])) << endl;
	cout << "На позиції " << n << " знаходиться число " << char(str.at(n-1)) << endl;
	}
}