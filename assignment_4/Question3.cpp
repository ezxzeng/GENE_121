#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

double convDeg (int deg, int mins) //changed deg and min from double to int
{
	double decDeg=mins/60.0;
	
	return deg+decDeg;
}

double xCoord (double latitude, double longitude)
{
	double x=longitude*111.0*cos(((latitude)/180)*M_PI);
	
	return x;
}

double yCoord (double lats)
{
	double y=111*lats;
	
	return y;
}

int main()
{
	ifstream fin ("message.txt");
	cout << "Assumption: For the following distances in degrees, angle 0 corresponds to the location of Chris' launch site." << endl;
	cout << endl;
	if (!fin)
	{
		cout<<"Unable to open file";
		return EXIT_FAILURE; 
	}
	else
	{	
		double a, b, c, d;
		fin >> a >> b >> c >> d;
		
		double afterLatConv1= convDeg (a,b);
		double afterLongConv1= convDeg (c,d);
		
		double lat1= yCoord (afterLatConv1);
		double longt1= xCoord (afterLatConv1,afterLongConv1);
		
		int n;
		fin >> n;
		for  (int i=0; i<n; i++)
		{
			double e, f, g, h, dist;
			fin >> e >> f >> g >> h;
			
			double afterLatConv2= convDeg (e,f);
			double afterLongConv2= convDeg (g,h);
			
			double lat2= yCoord (afterLatConv2);
			double longt2= xCoord (afterLatConv2,afterLongConv2);
			
			double distanceKM= sqrt(pow((lat1-lat2),2)+pow((longt1-longt2),2));
			double distanceDeg= sqrt(pow((afterLatConv1-afterLatConv2),2)+pow((afterLongConv1-afterLongConv2),2));
			
			cout << "The distance between launch site and delivery site is (in km): " << distanceKM << endl;
			cout << "The distance between launch site and delivery site is (in degrees): " << distanceDeg << endl;
			cout << endl;
		}
	}
	fin.close();
	return 0;
}
