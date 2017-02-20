//Emily Zeng

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Fraction
{
	public:
		Fraction()
		{
			(*this).num = 0; 
			(*this).den = 1;
		}
		Fraction(int numerator, int denominator)
		{
			if (denominator < 0)
			{
				numerator *= -1;
				denominator *= -1;
			}
			
			else if (denominator == 0)
			{
				cout << "dividing by 0, fraction set to 0/1" << endl;
				(*this).num = 0; 
				(*this).den = 1;
			}
			else
			{
				(*this).num = numerator; 
				(*this).den = denominator;
			}
		}
		int getNum() const
		{
			return (*this).num;
		}
		int getDen() const
		{
			return (*this).den;
		}
		void setNum(int numerator)
		{
			(*this).num = numerator;
		}
		void setDen(int denominator)
		{
			if (denominator < 0)
			{
				(*this).num *= -1;
				denominator *= -1;
			}
			
			else if (denominator == 0)
			{
				cout << "dividing by 0, den not changed" << endl;
			}
			else
				(*this).den = denominator;
		}
		double getApprox(int decPlace) const
		{
			double precision = pow(10,decPlace);
			return round(precision*(*this).num/(*this).den)/precision;
		}
		bool isExactlySame(Fraction const & other) const
		{
			double multFactor = double((*this).num)/other.getNum();
			if (other.getDen()*multFactor == (*this).den)
				return 1;
			else
				return 0;
		}
		void consolOutput() const
		{
			cout << (*this).num << "/" << (*this).den << endl;
		}
	private:
		int num;
		int den;
};
void sameCout(Fraction Test1, Fraction Test2)
{
	if (Test1.isExactlySame(Test2))
	{
		cout << "functions are the same" << endl;
	}
	else
	{
		cout << "functions are different"<< endl;
	}
}
int main()
{
	Fraction defCon;
	Fraction Test1(135,4520);
	Fraction equalTest1(1350,45200);
	Fraction equalTest2(6,4);
	Fraction zeroTest(3,0);
	
	cout << endl << "outputting default constructor and zero test" << endl;
	defCon.consolOutput();
	zeroTest.consolOutput();
	
	cout << endl << "testing getAprox function" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << fixed << setprecision(i) << Test1.getApprox(i) << endl;		
	}

	cout << endl << "testing if same function" << endl;
	Test1.consolOutput();
	equalTest1.consolOutput();
	sameCout(Test1, equalTest1);
	cout << endl;
	Test1.consolOutput();
	equalTest2.consolOutput();
	sameCout(Test1, equalTest2);
	
	cout<< endl << "testing set numerator: ";
		Test1.consolOutput();
	int num = 0;
	cin >> num;
	Test1.setNum(num);
	Test1.consolOutput();
	
	cout<< endl << "testing set denominator for: ";
		Test1.consolOutput();
	
	int den = 1;
	do
	{
		cin >> den;
		Test1.setDen(den);
		Test1.consolOutput();
		if (den != 0)
			cout << "test again with 0 as denominator" << endl;
	} while (den != 0);
	
	return 0;
}

/*
test results:
dividing by 0, fraction set to 0/1

outputting default constructor and zero test
0/1
0/1

testing getAprox function
0
0.0
0.03
0.030
0.0299
0.02987
0.029867
0.0298673
0.02986726
0.029867257

testing if same function
135/4520
1350/45200
functions are the same

135/4520
6/4
functions are different

testing set numerator: 135/4520
264
264/4520

testing set denominator for: 264/4520
36
264/36
test again with 0 as denominator
0
dividing by 0, den not changed
264/36

--------------------------------
Process exited after 10.13 seconds with return value 0
Press any key to continue . . .
*/
