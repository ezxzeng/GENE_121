// Emily ZhiXuan Zeng and Shruthi Srinivasan
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	double side1 = 0, side2 = 0, cdegrees = 0;
	ifstream fin ("stones.txt");
	fin >> side1 >> side2 >> cdegrees;
	double aTOL = 0.5;
	double sTOL = 0.1;	
	
	ofstream fout("assignment_2.3.txt");
	
	if (side1 <= 0 || side2 <= 0 || cdegrees < 0 || cdegrees >= 180)
	{
		fout<< "invalid input";
	}

	else 
	{
		fout << "side 1: " << side1 << endl
			<<"side 2: " << side2 << endl
			<<"contained angle: " << cdegrees << endl
			<< "the paving stone shape is a ";
		if (abs(side1 - side2) <= sTOL)
		{
			if (abs(cdegrees - 90) <= aTOL)
				fout << "square";
			else
				fout << "rhombus";	
		}
		else
		{
			if (abs(cdegrees - 90) <= aTOL)
				fout << "rectangle";
			else
				fout << "parallelogram";
		}
	fin.close();
	fout.close ();		
	}
		
	return 0;
}

/*
Test Case 1
input: -5 5 30
Output: invalid input

Test case 2
input: 5 10 -20
output: invalid input

Test case 3
input: 35 67 189
output: invalid input

Test case 4
input: 2 2 10
output: 
side 1: 2
side 2: 2
contained angle: 10
the paving stone shape is a rhombus

Test Case 5
input: 2 2 90
Output: 
side 1: 2
side 2: 2
contained angle: 90
the paving stone shape is a square

Test Case 6
input: 2 4 90
Output: 
side 1: 2
side 2: 4
contained angle: 90
the paving stone shape is a rectangle

Test Case 7
input: 2 4 60
Output: 
side 1: 2
side 2: 4
contained angle: 60
the paving stone shape is a parallelogram

*/
