//Shraddha Shah and Emily Zeng
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

double areaTri (double S1, double S2, double S3) // Emily 
    {
		double halfP = (S1 + S2 + S3)/2 ;
		return sqrt(halfP* (halfP - S1) * (halfP - S2) * (halfP - S3));
    }

double areaQuad(double S1, double S2, double diag, double S3, double S4) //Shraddha
    {
        return areaTri(S1, S2, diag) + areaTri(diag, S3, S4);
    }

double areaSector(double radius, double angle) // Emily
	{
		return 0.5 * pow(radius,2) * angle;
	}

double perimeterSector(double radius, double angle)//Shraddha
    {
        return radius*M_PI*angle/M_PI + 2 * radius;
    }

double perimeterTri(double S1, double S2, double S3)//Shraddha
    {
        return S1 + S2 + S3;
    }

double perimeterQuad(double S1, double S2, double S3, double S4) // Emily
    {
        return S1 + S2 + S3 + S4;
   }

int costPrint(double area, double perimeter) //Emily 
{
	double costFencing = 0;
	if (perimeter != 0)
		costFencing = 26.0 * ceil(perimeter) + 120.0;
		
	double costPaving = 18.5 * ceil(area);
	double costTotal = costFencing + costPaving + 35;
	double taxes = costTotal * 0.13;
	costTotal += taxes;
	
	cout << setw(12) << area
		<< setw(12) << costPaving
		<< setw(11) << perimeter
		<< setw(11) << costFencing
		<< setw(11) << taxes
		<< setw(11) << costTotal
		<< endl;
	
	return 0;
}

int main()
    {
        int job = 0;
        bool fence = 0;
        string shape;
        double area = 0, perimeter = 0;
        ifstream fin("jobs.txt");
        if (!fin)
        {
            cout << "Unable to open file" << endl;
            return EXIT_FAILURE;
        }

        cout << "Job #  Paved Area   Pave Cost   F Length "
             << "Fence Cost      Taxes Total Cost" << endl;
		
        while (fin >> job >> fence >> shape)
        {
        	cout << setw(5)<< job;
            if (shape == "tri")
            {
            	double S1 = 0, S2 = 0, S3 = 0;
                fin >> S1 >> S2 >> S3;
                area = areaTri(S1, S2, S3);
                perimeter = perimeterTri(S1, S2, S3);
            }
            else if (shape == "quad")
            {
            	double S1 = 0, S2 = 0, S3 = 0, S4 = 0, diag = 0;
                fin >> S1 >> S2 >> diag >> S3 >> S4;
                area = areaQuad(S1, S2, diag, S3, S4);
                perimeter = perimeterQuad(S1, S2, S3, S4);
            }
            else
            {
            	double radius = 0, angle = 0;
                fin >> radius >> angle;
                area = areaSector(radius, angle);
                perimeter = perimeterSector(radius, angle);
            }
			
			if (!fence)
				perimeter = 0;
				
			costPrint(area, perimeter);
        }

        fin.close();
        return 0;
    }

/*
Job #  Paved Area   Pave Cost   F Length Fence Cost      Taxes Total Cost
 7100         600       11100        120       3240    1868.75    16243.8
 7101     8.99999       166.5          0          0     26.195    227.695
 7102         135      2497.5          0          0    329.225    2861.72
 7103         784       14504        112       3032    2284.23    19855.2
 7104        9000      166500       1820      47440    27816.8     241792
 7105     70.1619      1313.5          0          0    175.305    1523.81
 7106     2323.24       42994      192.8       5138    6261.71    54428.7
 7107     11289.6      208865          0          0      27157     236057
 7108      501.76        9287          0          0    1211.86    10533.9
 7109     5152.05     95330.5      984.4      25730    15742.4     136838
 7110     8.38599       166.5          0          0     26.195    227.695
 7111     3.89711          74          9        354      60.19     523.19
 7112       70.56      1313.5       33.6       1004    305.825    2658.32

--------------------------------
Process exited after 0.08093 seconds with return value 0
Press any key to continue . . .

*/
