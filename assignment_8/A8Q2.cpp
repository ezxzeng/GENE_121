// A8Q2.cpp : Defines the entry point for the console application.
//Sam Sun

#include "stdafx.h"

#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

class Fraction
{
public:
	Fraction()
	{
		this->numerator = 0;
		this->denominator = 1;
	}

	Fraction(int num, int denom)
	{
		this->numerator = num;
		this->denominator = denom;
	}

	int getNumerator()
	{
		return this->numerator;
	}

	int getDenominator()
	{
		return this->denominator;
	}

	void setNumerator(int newNumerator)
	{
		if (abs(newNumerator) > abs(this->denominator))
		{
			stringstream error;
			error << "abs(numerator) of " << abs(newNumerator) << " is greater than the abs(denominator) of " << abs(this->denominator);
			throw runtime_error(error.str());
		}

		this->numerator = newNumerator;
	}

	void setDenominator(int newDenominator)
	{
		if (abs(newDenominator) < abs(this->numerator))
		{
			stringstream error;
			error << "abs(denominator) of " << abs(newDenominator) << " is less than the abs(numerator) of " << abs(this->numerator);
			throw runtime_error(error.str());
		}

		this->denominator = newDenominator;
	}

	double toDouble(int precision)
	{
		double precisionFactor = pow(10, precision);
		return round (precisionFactor * numerator / denominator ) / precisionFactor;
	}

	bool isExactlySame(Fraction const & other) const
	{
		return other.numerator == this->numerator && other.denominator == this->denominator;
	}

	void output()
	{
		stringstream stream;
		stream << "Fraction{numerator=" << this->numerator << ",denominator=" << this->denominator << "}";
		cout << stream.str();
	}

private:
	int numerator;
	int denominator;
};

void setNumeratorOf(Fraction fraction, int numerator)
{
	cout << "Setting numerator of ";
	fraction.output();
	cout << " to " << numerator << endl;
	try
	{
		fraction.setNumerator(numerator);
	}
	catch (exception ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	cout << "Result: ";
	fraction.output();
	cout << endl;
}

void setDenominatorOf(Fraction fraction, int denominator)
{
	cout << "Setting denominator of ";
	fraction.output();
	cout << " to " << denominator << endl;
	try
	{
		fraction.setDenominator(denominator);
	}
	catch (exception ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	cout << "Result: ";
	fraction.output();
	cout << endl;
}

int main()
{
	int amount = 6;
	Fraction fractions[] = {
		Fraction(),
		Fraction(1, 2),
		Fraction(1, 10),
		Fraction(1, 9),
		Fraction(-1, 9),
		Fraction(1, 7)
	};

	cout << fixed;

	for (int i = 0; i < amount; i++)
	{
		Fraction fraction = fractions[i];
		cout << "Testing ";
		fraction.output();
		cout << endl;

		cout << setw(40) << "Precision" << setw(30) << "Value" << endl;

		for (int precision = 1; precision <= 10; precision++)
		{
			cout << setw(40) << precision << setw(30) << setprecision(precision) << fraction.toDouble(precision) << endl;
		}

		cout << setw(40) << "Other fraction" << setw(30) << "Is same" << endl;

		for (int i = 0; i < amount; i++)
		{
			cout << setw(40);
			fractions[i].output();
			cout <<setw(30) << (fraction.isExactlySame(fractions[i]) ? "true" : "false")<< endl;
		}
	}

	Fraction base(7, 17);
	for (int i = -18; i <= 18; i++)
	{
		setNumeratorOf(base, i);
	}
	for (int i = -18; i <= 18; i++)
	{
		setDenominatorOf(base, i);
	}

    return 0;
}

