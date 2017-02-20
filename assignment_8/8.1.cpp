// Emily Zeng and Sam Sun
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void handleData(ifstream & input, int data[9][4])
{
	int temp, coarse, score;
	while (input >> temp >> coarse >> score)
	{
		data[temp - 91][coarse - 1] += score;
	}
}

void dataOutput(int coffee[9][4])
{
	cout << setw(4) << "Temp" << setw(9) << "Coarse" << setw(15) << "Sum of Rank" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			cout<< setw(4) << (i + 91)
				<< setw(9) << (j + 1)
				<< setw(15) << coffee[i][j] << endl;
		}
	}
}

int sum(int coffee[9][4], bool temperature, int index)
{
	int sum = 0;

	if (temperature)
	{
		for (int i = 0; i < 4; i++)
		{
			sum += coffee[index][i];
		}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			sum += coffee[i][index];
		}
	}

	return sum;
}

void bestComb(int coffee[9][4], int & bestTemp, int & bestCoarse)
{
	bestTemp = 0;
	bestCoarse = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (coffee[i][x] > coffee[bestTemp][bestCoarse])
			{
				bestTemp = i;
				bestCoarse = x;
			}
		}
	}
}

int main()
{
	int data[9][4] = { 0 };
	ifstream coffee1("coffee1.txt");
	ifstream coffee2("coffee2.txt");
	ifstream coffee3("coffee3.txt");
	handleData(coffee1, data);
	handleData(coffee2, data);
	handleData(coffee3, data);

	dataOutput(data);

	int bestTemp = 0;
	int bestScore = 0;
	for (int i = 0; i < 9; i++)
	{
		int score = sum(data, true, i);
		if (score > bestScore) {
			bestScore = score;
			bestTemp = i;
		}
	}

	cout << "The best temperature is " << (bestTemp + 91) << endl;

	bestTemp = 0;
	int bestCoarse = 0;

	bestComb(data, bestTemp, bestCoarse);

	cout<< "The best temperature and coarseness is "
		<< (bestTemp + 91) << " and " << (bestCoarse + 1) << endl;

	coffee1.close();
	coffee1.close();
	coffee3.close();

    return 0;
}

/*
Temp   Coarse    Sum of Rank
  91        1              0
  91        2              0
  91        3              0
  91        4              0
  92        1              0
  92        2              0
  92        3              0
  92        4              0
  93        1              0
  93        2              0
  93        3              0
  93        4              0
  94        1              0
  94        2              0
  94        3              0
  94        4              0
  95        1              0
  95        2              0
  95        3              0
  95        4              0
  96        1              0
  96        2              0
  96        3              0
  96        4              0
  97        1              0
  97        2              0
  97        3              0
  97        4              0
  98        1              0
  98        2              0
  98        3              0
  98        4              0
  99        1              0
  99        2              0
  99        3              0
  99        4              0
The best temperature is 91
The best temperature and coarseness is 91 and 1

--------------------------------
Process exited after 0.7198 seconds with return value 0
Press any key to continue . . .
*/

