// Emily ZhiXuan Zeng, waterloo id: 20678953
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
	double a, b, dC;
	cout << "please enter value for side a: ";
	cin >> a;
	cout << "please enter value for side b: ";
	cin >> b;
	cout << "please enter value for angle C in degrees: ";
	cin >> dC;
	double C = dC*M_PI/180;
	
	double c = sqrt(pow(a,2)+pow(b,2)-(2*a*b*cos(C)));
	double sinlawA = asin((a*sin(C))/c);
	sinlawA = sinlawA*180/M_PI;
	
	double coslawA = acos((a*a-b*b-c*c)/(-2*b*c));
	coslawA = coslawA*180/M_PI;
	
	double sinlawB = asin((b*sin(C))/c);
	sinlawB = sinlawB*180/M_PI;
	
	double coslawB = acos((b*b-a*a-c*c)/(-2*a*c));
	coslawB = coslawB*180/M_PI;
	
	double s = (a+b+c)/2; 
	double area = sqrt(s*(s-a)*(s-b)*(s-c));
	
	cout << "the side lengths are (a,b,c): ";
	cout << a << ", " << b << ", " << c << endl;
	cout << "the cos law angles are (A,B,C): ";
	cout << coslawA << ", " << coslawB << ", " << dC << endl;
	cout << "the sin law angles are (A,B,C): ";
	cout << sinlawA << ", " << sinlawB << ", " << dC << endl;
	cout << "the area is: " << area << endl;
	
	return 0;
}

/*
test case 1:
please enter value for side a: 30
please enter value for side b: 3
please enter value for angle C in degrees: 15
the side lengths are (a,b,c): 30, 3, 27.1133
the cos law angles are (A,B,C): 163.359, 1.64103, 15
the sin law angles are (A,B,C): 16.641, 1.64103, 15
the area is: 11.6469

--------------------------------
Process exited after 9.469 seconds with return value 0
Press any key to continue . . .

test case 2:
please enter value for side a: 2
please enter value for side b: 20
please enter value for angle C in degrees: 30
the side lengths are (a,b,c): 2, 20, 18.2953
the cos law angles are (A,B,C): 3.13328, 146.867, 30
the sin law angles are (A,B,C): 3.13328, 33.1333, 30
the area is: 10

--------------------------------
Process exited after 9.212 seconds with return value 0
Press any key to continue . . .

test case 3:
please enter value for side a: 3
please enter value for side b: 4
please enter value for angle C in degrees: 90
the side lengths are (a,b,c): 3, 4, 5
the cos law angles are (A,B,C): 36.8699, 53.1301, 90
the sin law angles are (A,B,C): 36.8699, 53.1301, 90
the area is: 6

--------------------------------
Process exited after 7.61 seconds with return value 0
Press any key to continue . . .

*/
