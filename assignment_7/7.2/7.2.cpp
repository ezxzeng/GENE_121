//Emily ZhiXuan Zeng and Sai Shruthi Srinivasan
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream fin("resist.txt");
	ofstream fout("report.txt");
	if (!fin)
	{
        cout << "Unable to open file" << endl;
        return EXIT_FAILURE;
    }
    
    int value[10] = {0};
    
	int hundreds = 100;
    
    int count;
    int resistor = 0;
    while (fin>>count)
    {
    	for (int i = 0; i < count; i ++)
    	{
    		fin >> resistor;
    		resistor = resistor/100 - 1;
    		value[resistor] ++;
		}
	}
	
	fout << "to buy:" << endl;
	hundreds = 100;
	int mostCount[10] = {0};
	int mostValue[10] = {0};
	int index = 0;
	for (int i = 0; i < 10; i ++)
	{
		if (value[i] < 275)
			fout << hundreds << ": " << 275 - value[i] << endl;
		if (value[i] > mostCount[index])
		{
			if (value[i] == mostCount[index])
				index++;
			mostCount[index] = value[i];
			mostValue[index] = hundreds;
		}
		hundreds += 100;
	}
    
    fout << "resistors with most inventory:" << endl;
    
    for (int i = 0; i <= index; i++)
    {
    	fout << mostValue[i] << ": " << mostCount[i] << endl;
	}
	
	return 0;
}
