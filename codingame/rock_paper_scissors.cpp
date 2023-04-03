#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 vector<string> get_vec(string str)
 {
    string r_str;
    vector<string> vec;
    for (int i = 0; i <= str.size(); ++i)	// size+1
    {
        if (str[i]!=' ' && str[i]!='\0')
            r_str.push_back(str[i]);
        else
        {
            vec.push_back(r_str);
            r_str.clear();
        }
    }

    return vec;
 }
 
  vector<string> get_vec_new(string str)
 {
    string r_str;
    vector<string> vec;
    for (int i = 0; i < str.size(); ++i)
    {
		r_str.push_back(str[i]);
		
        if (str[i+1]==' ' || str[i+1]=='\0')
        {
			++i;// пропускаємо наступний символ
            vec.push_back(r_str);
            r_str.clear();
        }
    }

    return vec;
 }
 
 
 // Можливо, вдосконалити гру до 3-х, або більше гравців?
 void input(int &n, string &string_1, string &string_2)
 {
	cout << "Введіть n: "; // Кількість раундів
    cin >> n; cin.ignore();
    
	cout << "Введіть string_1: ";	// список спроб першого гравця
    getline(cin, string_1);
	
	cout << "Введіть string_2: ";	// список спроб другого гравця
    getline(cin, string_2);
 }

enum Drop
{
	ROCK = 0,
	PAPER = 1,
	SCISSORS = 2
};

bool operator>(Drop left, Drop right)
{
	if (left==ROCK && right==SCISSORS)
		return true;
	else if (left==SCISSORS && right==ROCK)
		return false;
	
	return static_cast<int>(left)>static_cast<int>(right);
}

static bool operator>(const Drop &left, const Drop &right)
{
	if (left==ROCK && right==SCISSORS)
		return true;
	else if (left==SCISSORS && right==ROCK)
		return false;
	
	return static_cast<int>(left)>static_cast<int>(right);
}

bool operator<(const Drop &left, const Drop &right)
{
	if (left==ROCK && right==SCISSORS)
		return false;
	else if (left==SCISSORS && right==ROCK)
		return true;
	
	return static_cast<int>(left)<static_cast<int>(right);
}

bool operator==(const Drop &left, const Drop &right)
{
	return static_cast<int>(left)==static_cast<int>(right);
}

int main()
{
    int n;
    string string_1;
    string string_2;
	
	n = 3;
	string_1 = "ROCK PAPER SCISSORS";
	string_2 = "PAPER SCISSORS ROCK";

    vector<string> v1 = get_vec(string_1);
    vector<string> v2 = get_vec(string_2);
	
	for (string str : v1) cout << str << endl;
	cout << endl;
	for (string str : v2) cout << str << endl;
	
    // for (int i = 0; i<n; ++i)
    // {
        // if (v1[i] == "ROCK" && v1[i] == "ROCK")

    // }
	
	bool result = ROCK>PAPER;
	cout << "ROCK > PAPER = " << result << endl;
	// cout << "ROCK > SCISSORS = " << ROCK > SCISSORS << endl;
	// cout << "SCISSORS < PAPER = " << SCISSORS < PAPER << endl;
	// cout << "SCISSORS < ROCK = " << SCISSORS < ROCK << endl;
	// cout << "ROCK == ROCK = " << ROCK == ROCK << endl;

    //cout << "2-0" << endl;
}