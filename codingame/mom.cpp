#include <iostream>
#include <string>
//#include <vector>
#include <algorithm>	//toupper

using namespace std;

string mom(string const &str)
{
    string word;
	string res;
	size_t size;
	bool apo = false;
	
    for (char ch : str)
    {
		
        if (ch!=' ' && ch!='?' && ch!='!' && ch!='.')
        {
			if (ch=='\'') apo = true;
				word.push_back(ch);
        }
        else
        {
			if (apo) 
			{
				size=word.size()-1;
				apo = false;
			}
			else size=word.size();
			
			//cout << word << '\t' << size << endl;
			
            if (size%2 == 0)
            {
                for (char &ch : word)
                    ch = toupper(ch);
            }

            res+=word+ch;
            word.clear();
        }
    }

    return res;
}

void test(string test, string str)
{
	test = mom(test);
	if (test != str)
	{
		cout << "FAIL:\t\t"<<test<<endl;
		cout << "EXPECTED:\t"<<str<<endl;
	}
	else cout << "SUCCESS:\t"<<test<<endl;
}

int main()
{
    // string s;
    // getline(cin, s);
    
	string test1 = "Are you stupid?";
	string test2 = "WHY have YOU done that?";
	string test3 = "I don't want you anymore! You are stressful.";
	string test4 = "Stop programming and do your homework!";
	
	test(test1, "Are you STUPID?");
	test(test2, "WHY HAVE YOU DONE THAT?");
	test(test3, "I DON'T WANT you anymore! You are stressful.");
	test(test4, "STOP programming and DO YOUR HOMEWORK!");
}

/*
Are you stupid? 
Are you STUPID?
WHY have YOU done that?
WHY HAVE YOU DONE THAT?
I don't want you anymore! You are stressful.
I DON'T WANT you anymore! You are stressful.
Stop programming and do your homework!
STOP programming and DO YOUR HOMEWORK!
*/
