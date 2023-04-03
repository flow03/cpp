#include <iostream>
#include <string>
//#include <vector>
//#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 int middle(int a, int b)
 {
    return (a+b)/2;
 }

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    int x_lower = 0;
    int x_upper = w;
    int y_lower = 0;
    int y_upper = h;

    auto move_up = [&y0, &y_lower, &y_upper]()
    {
        y_upper = y0-1;
        y0 = middle(y_upper, y_lower);
    };
    auto move_down = [&y0, &y_lower, &y_upper]()
    {
        y_lower = y0+1;
        y0 = middle(y_lower, y_upper);
    };
    auto move_left = [&x0, &x_lower, &x_upper]()
    {
        x_upper=x0-1;
        x0 = middle(x_upper, x_lower);
    };
    auto move_right = [&x0, &x_lower, &x_upper]()
    {
        x_lower=x0+1;
        x0 = middle(x_lower, x_upper);
    };
    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cerr << "x0="<<x0<<" y0="<<y0<<endl;

        if (bomb_dir == "U")
        {
            move_up();
        }
        else if (bomb_dir == "D")
        {
            move_down();
        }
        if (bomb_dir == "L")
        {
            move_left();
        }
        else if (bomb_dir == "R")
        {
            move_right();
        }
        else if (bomb_dir == "UR")
        {
            move_up();
            move_right();
        }
        else if (bomb_dir == "DR")
        {
            move_down();
            move_right();
        }
        else if (bomb_dir == "DL")
        {
            move_down();
            move_left();
        }
        else if (bomb_dir == "UL")
        {
            move_up();
            move_left();
        }
        
        cerr << bomb_dir << " w="<<w<<" h="<<h<<endl;
        //cerr << "x0="<<x0<<" y0="<<y0<<endl;
        cerr << "x_lower="<<x_lower<<" x_upper="<<x_upper<<endl;
        cerr << "y_lower="<<y_lower<<" y_upper="<<y_upper<<endl;
        // the location of the next window Batman should jump to.
        cout << x0 << ' ' << y0 << endl;
    }
}