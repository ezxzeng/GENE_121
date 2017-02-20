// Emily ZhiXuan Zeng and Hayden Drew Ruston

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	int numDigits = 0;
	
	do
	{
		cout << "Enter number of digits to use in calculation: ";
		cin >> numDigits;
	}while(numDigits <= 0);
	
	int counter = 0;
	double num = 2.6*pow(10,(numDigits-1)), den = 1*pow(10,(numDigits-1))-1;
	double approximation = num/den;
	double NewPercentError = 0, OldPercentError = 1;
	double NewNum = 0, NewDen = 0;
	
	while (num < pow(10, numDigits))
	{
		den ++;
		approximation = num/den;
		NewPercentError = abs((approximation - M_E)/M_E);
		counter ++;
		
		while (approximation < M_E)
		{
			num ++;
			approximation = num/den;
			NewPercentError = abs((approximation - M_E)/M_E);;
			counter ++;
		}
	
		if (NewPercentError < OldPercentError && num < pow(10, numDigits))
		{
			OldPercentError = NewPercentError;
			NewNum = num;
			NewDen = den;
		}
	}
	
	cout << "best approximation is " << NewNum << "/" << NewDen
			<< " = " << NewNum/NewDen << endl 
			<< "percent error: " << OldPercentError << endl
			<< " # iterations: " << counter;

	return 0;
}

/*
Trial with 2:

Enter number of digits to use in calculation: 2
best approximation is 87/32 = 2.71875
percent error: 0.000172231
 # iterations: 103
--------------------------------
Process exited after 3.255 seconds with return value 0
Press any key to continue . . .

Trial with 3:

Enter number of digits to use in calculation: 3
best approximation is 386/142 = 2.71831
percent error: 1.03119e-005
 # iterations: 1010
--------------------------------
Process exited after 3.017 seconds with return value 0
Press any key to continue . . .

Trial with 4

Enter number of digits to use in calculation: 4
best approximation is 9620/3539 = 2.71828
percent error: 6.33143e-008
 # iterations: 10081
--------------------------------
Process exited after 2.744 seconds with return value 0
Press any key to continue . . .

Trial with 5

Enter number of digits to use in calculation: 5
best approximation is 49171/18089 = 2.71828
percent error: 1.01774e-010
 # iterations: 100790
--------------------------------
Process exited after 1.454 seconds with return value 0
Press any key to continue . . .

*/
