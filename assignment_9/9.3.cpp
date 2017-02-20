//Emily ZhiXuan Zeng

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

bool isPalindrome(int num[], int&start, int&end)
{
	if (start >= end)
		return true;
	else if (num[start] != num[end])
		return false;
	else
	{
		start++;
		end--;
		return isPalindrome(num, start, end);	
	}
}

void IntToArray(int numDig[], int num, int&start, int&end)
{
	start = 0, end = 0;
	while (num >= 10)
	{
		numDig[end] = num%10;
		num /= 10;
		end++;
	}
	numDig[end] = num;
}

int main()
{
	int numDig[10] = {0};
	int num = 0;

	cout << "enter a number with less than 10 digits: ";
	cin >> num;

	while (num >= 0)
	{
		int start = 0, end = 0;
		IntToArray(numDig, num, start, end);
		
		if(isPalindrome(numDig, start, end))
			cout << "is palindrome" << endl;
		else
			cout << "is not palindrome" << endl;
		
		cout << endl << "enter a number with less than 10 digits: ";
		
		cin >> num;
	}
	
	return 0;	
}

/*
enter a number with less than 10 digits: 12111
is not palindrome

enter a number with less than 10 digits: 11121
is not palindrome

enter a number with less than 10 digits: 111111111
is palindrome

enter a number with less than 10 digits: 31526246
is not palindrome

enter a number with less than 10 digits: 346643
is palindrome

enter a number with less than 10 digits: -1

--------------------------------
Process exited after 18.37 seconds with return value 0
Press any key to continue . . .
*/
