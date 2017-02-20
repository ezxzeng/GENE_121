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
		if (approximation < M_E)
		{
			num++;
			approximation = num/den;
		}
		
		if (approximation > M_E)
		{
			den++;
			approximation = num/den;
		}
	
		NewPercentError = abs((approximation - M_E)/M_E);
		
		if (NewPercentError < OldPercentError && num < pow(10, numDigits))
		{
			OldPercentError = NewPercentError;
			NewNum = num;
			NewDen = den;
		}
		
		counter ++;
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
best approximation is 38/14 = 2.71429
percent error: 0.00147009
 # iterations: 75
--------------------------------
Process exited after 2.441 seconds with return value 0
Press any key to continue . . .

Trial with 3:

Enter number of digits to use in calculation: 3
best approximation is 878/323 = 2.71827
percent error: 5.72957e-006
 # iterations: 740
--------------------------------
Process exited after 3.39 seconds with return value 0
Press any key to continue . . .

Trial with 4:

Enter number of digits to use in calculation: 4
best approximation is 2721/1001 = 2.71828
percent error: 4.0532e-008
 # iterations: 7400
--------------------------------
Process exited after 2.356 seconds with return value 0
Press any key to continue . . .

Trial with 5:

Enter number of digits to use in calculation: 5
best approximation is 75117/27634 = 2.71828
percent error: 6.34174e-010
 # iterations: 74000
--------------------------------
Process exited after 2.687 seconds with return value 0
Press any key to continue . . .

*/

