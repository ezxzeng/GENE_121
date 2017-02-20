// Emily ZhiXuan Zeng
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	double m, r2, r1;
	
	cout << "please enter the mass of the sphere:";
	cin >> m;
	cout << "please enter the radius of the sphere:";
	cin >> r2;
	cout << "please enter the hollow cavity radius of the sphere:";
	cin >> r1;
	
	double I = (2*m/5)*((pow (r2,5)-pow(r1,5))/(pow(r2,3)-pow(r1,3)));
	cout << "the moment of inertia is " << I << endl;	

	return 0;
}

/*
test case 1
please enter the mass of the sphere:25
please enter the radius of the sphere:4
please enter the hollow cavity radius of the sphere:2
the moment of inertia is 177.143

--------------------------------
Process exited after 4.863 seconds with return value 0
Press any key to continue . . .

test case 2
please enter the mass of the sphere:51
please enter the radius of the sphere:24
please enter the hollow cavity radius of the sphere:22
the moment of inertia is 18042.6

--------------------------------
Process exited after 9.504 seconds with return value 0
Press any key to continue . . .
*/
