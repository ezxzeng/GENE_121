// Emily ZhiXuan Zeng
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ofstream fout("square.txt");

    int a = 9;
    
    cout << "enter value for a to be squared and cubed" << endl;
    cin >> a;

    cout << "The square of " << a << " is " << a*a << endl;
    fout << "The squre of " << a << " is " << a*a << endl;

    cout << a << " cubed is " << a*a*a << endl;

    fout.close();
    return 0;
}

/*
enter value for a to be squared and cubed
4
The square of 4 is 16
4 cubed is 64

--------------------------------
Process exited after 6.18 seconds with return value 0
Press any key to continue . . .

the file output is:
The squre of 4 is 16
*/
