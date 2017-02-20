// Emily ZhiXuan Zeng and Shruthi Srinivasan
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	int num = 0;
	cout << "please enter a number in the thousands ";
	cin >> num;
	
	if (num < 1000 || num > 999999||num > -1000 || num < -1000000)
		cout << "invalid input";
	
	else
	{
		int b = log10 (abs(num));
		int a = pow(10, b);

		for (int x= a; x>0; x /=10)
		{
			int digit = num/x;
			if (x == 1000)
				cout << digit << ",";
			else
				cout << digit;
			num = abs(num%x);
		}
	}
	return 0;
}

/*
Test Case 1
please enter a number in the thousands 425981
425,981
--------------------------------
Process exited after 8.094 seconds with return value 0
Press any key to continue . . .

Test Case 2
please enter a number in the thousands -11028
-11,028
--------------------------------
Process exited after 8.474 seconds with return value 0
Press any key to continue . . .

Test Case 3
please enter a number in the thousands 1002345
invalid input
--------------------------------
Process exited after 3.528 seconds with return value 0
Press any key to continue . . .


Test case 4
please enter a number in the thousands -1002346
invalid input
--------------------------------
Process exited after 5.999 seconds with return value 0
Press any key to continue . . .

*/
