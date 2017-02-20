// Emily ZhiXuan Zeng and Shruthi Srinivasan
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	double degree = 0, radius1 = 0;
	cout << "please enter the angle of the removed section in degrees ";
	cin >> degree;
	double rad = degree*M_PI/180;
	cout << "please enter the radius of the paper circle ";
	cin >> radius1;
	
	if (radius1 > 0 && rad > 0 && rad < (2*M_PI))
	{
		double radius2 = (rad*radius1)/(2*M_PI);
		double height = sqrt(radius1*radius1+radius2*radius2);
		
		double volume = M_PI*radius2*radius2*height/3;
		cout << "the volume of the cone is " << volume << endl;
	}
	
	else
		cout << "invalid input";
	return 0;
}

/*
test case 1:
please enter the angle of the removed section in degrees-5
please enter the radius of the paper circle10
invalid input
--------------------------------
Process exited after 23.39 seconds with return value 0
Press any key to continue . . .

test case 2:
please enter the angle of the removed section in degrees 15
please enter the radius of the paper circle -3
invalid input
--------------------------------
Process exited after 7.351 seconds with return value 0
Press any key to continue . . .

test case 3:
please enter the angle of the removed section in degrees 15
please enter the radius of the paper circle -3
invalid input
--------------------------------
Process exited after 7.351 seconds with return value 0
Press any key to continue . . .

test case 4:
please enter the angle of the removed section in degrees 15
please enter the radius of the paper circle -3
invalid input
--------------------------------
Process exited after 7.351 seconds with return value 0
Press any key to continue . . .
*/
