#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    cerr <<"width "<<width<<" height "<<height<<endl;

    vector<string> nodes;
    pair<int,int> n1,n2,n3;

    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        nodes.push_back(line);
    }

    auto find_down = [&nodes, &height](int x, int y)->pair<int,int>
    {
        pair<int,int> res = make_pair(-1,-1);
        
        if (y!=height-1)
        {
        for (int j = y+1; j < height; ++j) 
        {
            //cerr<<x<<' '<<j<<endl;
            if (nodes[j][x]=='0')
            {
                //cerr<<x<<' '<<j<<endl;
                res = make_pair(x,j);
                break;
            }
        }
        }

        return res;
    };

    auto find_right = [&nodes, &width](int x, int y)->pair<int,int>
    {
        pair<int,int> res = make_pair(-1,-1);
        
        if (x!=width-1)
        {
        string line = nodes.at(y);
        for (int i = x+1; i < width; ++i) 
        {
            if (line[i]=='0')
            {
                //cerr<<i<<' '<<y<<endl;
                res = make_pair(i,y);
                break;
            }
        }
        }

        return res;
    };

    for (int i = 0; i < width; ++i)
    {
    for (int j = 0; j < height; ++j) 
    {
        cerr<<i<<' '<<j<<endl;
        if (nodes[j][i] == '0')
        {
            n1 = make_pair(i,j);
            n2 = find_right(i,j);
            n3 = find_down(i,j);

            cout<<n1.first<<' '<<n1.second<<' '
            <<n2.first<<' '<<n2.second<<' '
            <<n3.first<<' '<<n3.second<<endl;
        }
    }
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "0 0 1 0 0 1" << endl;
}