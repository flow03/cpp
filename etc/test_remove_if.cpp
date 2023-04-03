#include <iostream>  
#include <algorithm>
#include <vector>

int main() 
{
	using namespace std;

	vector<int> vec = {10, 50, 10, 19, 76, 10, 99, 12, 43, 12};
	vector<int> new_vec;

	// auto res = find(vec.begin(), vec.end(), 90);
	// copy_if(vec.begin(), vec.end(), back_inserter(new_vec), [](const int &a)
	// {
		// return a == 12;
	// });
	for (int el : vec) cout << el << ' ';
	cout << endl;

	auto res = remove_if(vec.begin(), vec.end(), [](int a)
	{
		return a > 15 && a <= 50;
	});

	for (int el : vec) cout << el << ' ';
	cout << endl;

	if (res != vec.end())
		cout << "Первый граничащий элемент " << *res << endl;
	else cout << "Нет граничащего элемента" << endl;

	vec.erase(res, vec.end());

	for (int el : vec) cout << el << ' ';
	cout << endl;

	return 0;
}
