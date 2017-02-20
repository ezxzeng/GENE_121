//Emily ZhiXuan Zeng

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

const int numCol = 78; // in x direction
const int numRows = 82; // in y direction

bool finArray(ifstream & fin, int depth[78][82])
{
	bool status = 0;
	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCol; x++)
		{
			status = fin >> depth[x][y];
		}
	}
	return status;
}

void drawLake(int depth[78][82], double bound)
{
	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCol; x++)
		{
			char depict = 'l';
			if (depth[x][y]/10.0 <= bound)
				depict = 'w';
			cout<< depict;
		}
		cout << endl;
	}
}

void SAandVolume(int depth[78][82], double bound, double&SA, double&V)
{
	SA = 0;
	V = 0;
	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCol; x++)
		{
			if (depth[x][y]/10.0 <= bound)
			{
				SA += 100;
				V += (abs(depth[x][y])/10.0 + bound) * 100;
			}
		}
	}
}

struct Coordinates{
	int x;
	int y;
};

void extremePoint(int depth[78][82], bool isLand, Coordinates extreme[], int & numTies)
{
	int maxOrMin = -1;
	if (isLand)
		maxOrMin = 1;
	numTies = 0;

	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCol; x++)
		{
			if (maxOrMin*depth[x][y] > maxOrMin*depth[extreme[numTies].x][extreme[numTies].y])
			{
				numTies=0;
				extreme[numTies].x = x;
				extreme[numTies].y = y;
			}
			else if ((maxOrMin*depth[x][y] == maxOrMin*depth[extreme[numTies].x][extreme[numTies].y]))
			{
				numTies++;
				extreme[numTies].x = x;
				extreme[numTies].y = y;
			}
		}
	}
}

int main()
{
	ifstream fin("depths.txt");
	
	if (!fin)
	{
		cout << "unable to ope file" << endl;
		return EXIT_FAILURE;
	}
	
	int depth[numCol][numRows] = {0};
	finArray(fin, depth);
	
	double SA = 0, V = 0;
	SAandVolume(depth, 0, SA, V);
	
	cout << "surface area of lake: " << SA << "m^2" << endl
		 << "volume of lake: " << V << "m^3" << endl;
	
	SAandVolume(depth, -2.50, SA, V);
	
	cout << "After water level falls 250m" << endl
		 << "surface area of lake: " << SA << "m^2" << endl
		 << "volume of lake: " << V << "m^3" << endl;
		 
	
	drawLake(depth, -2.50);
	
	fin.close();
	return 0;
}

/*
surface area of lake: 352800m^2
volume of lake: 8.90308e+006m^3
After water level falls 250m
surface area of lake: 326700m^2
volume of lake: 8.06288e+006m^3
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
lllllllllllllllllllllllllllllllllllllllllllwwwwwwwwwwwwwwwwwwwllllllllllllllll
llllllllllllllllllllllllllllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwlllllllwlllll
lllllllllllllllllllllllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllwlllll
lllllllllllllllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllwwllll
llllllllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllwwllll
lllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllwwwlll
lllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllwwwlll
llllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllwwwlll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllwwwlll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllwwllll
lllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllwwllll
llllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllwwllll
llllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllwlllll
lllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllll
lllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllll
llllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllll
llllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllll
lllllllllllllllllwwwwwlwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllll
llwlllllllllllllllwwwwlwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllll
llwwwllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllll
llwwwwllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllll
llwwwwllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllll
llwwwwllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllll
llwwwwlllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllll
llwwwwwllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llwwwwwwwwwwlllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llwwwwwwwwwwlwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllwlwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
llllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllll
lllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
lllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
lllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllllll
llwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllll
lllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllll
llllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllllllllll
lllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllllll
lllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllllllll
llllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllllllllllll
lllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllllllllllllllllll
lllllllllllwwwwwwwwwwwwwwwwwwwwwwwwwwlllllllllllllllllllllllllllllllllllllllll
llllllllllllwwwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllllllllllllllll
llllllllllllllwwwwwwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllllllllllllllll
lllllllllllllllllwwwwwwwwwwwwwwwwwllllllllllllllllllllllllllllllllllllllllllll
lllllllllllllllllllwwwwwwwwwwwllwlllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllwwwwwwllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllwwwlllllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll

--------------------------------
Process exited after 0.8534 seconds with return value 0
Press any key to continue . . .
*/
