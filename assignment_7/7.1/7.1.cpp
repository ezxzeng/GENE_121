//Emily ZhiXuan Zeng and Shruthi Srinivasan
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	char AnsKey[30];
	int numQuestions = 0;
	
	ifstream fin("answers2016.txt");
	ifstream filein("pascal2016.txt");
	ofstream fout("results.txt");
	
	if (!fin || !filein)
	{
		cout << "error opening file";
		return EXIT_FAILURE;
	}
	
	while (filein >> AnsKey[numQuestions])
		numQuestions ++;

	string school;
	string ID;
	char ans;
	
	
	cout << "School     ID  Marks (%)" << endl;
	
	while (fin >> school >> ID)
	{
		int pointCount = 0, NoAnswerCount = 0;
		
		for (int i = 0; i < numQuestions; i++)
		{
			fin >> ans;
			if (ans == AnsKey[i])
				pointCount += 5;
			else if (ans == '0' && NoAnswerCount < 10)
			{
				pointCount += 2;
				NoAnswerCount ++;
			}
		}
		
		cout<< fixed << setprecision(1)
			<< setw(6) << school
			<< setw(7) << ID
			<< setw(11) << double(pointCount)/numQuestions/5*100
			<< endl;
	}
	
	return 0;
}
