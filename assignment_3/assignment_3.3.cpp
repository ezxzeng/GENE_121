// Emily ZhiXuan Zeng and Hayden Drew Ruston

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream fin("taxi.txt");
	
	if (!fin)
	{
		cout << "file open error";
		return EXIT_FAILURE;
	}

	int count = 0;
	bool ReturnTrip = 0;
	int TripNumber = 0;
	
	cout << setw(11) << "Trip number"
		<< setw(10) << "return"
		<< setw(10) << "# stop"
		<< setw(15) << "distance"
		<< setw(13) << "cost"
		<< setw(17) << "Total Dist"
		<< setw(17) << "Total Cost"
		<< endl;
	

	double TripDistance = 0, TotalDistance = 0;
	double TripCost = 0, TotalCost = 0;
	
	while (	fin >> ReturnTrip >> TripNumber)
	{
		double NewX = 0, NewY = 0, OldX = 0, OldY = 0;
		
		for (int x = TripNumber; x > 0; x--)
		{
			fin >> NewX >> NewY;
			TripDistance += sqrt(pow((NewX-OldX),2)+pow((NewY-OldY),2));
			OldX = NewX;
			OldY = NewY;

		}
		
		if (ReturnTrip==1)
			TripDistance += sqrt(NewX*NewX+NewY*NewY);
		
		TotalDistance += TripDistance;
		TripCost = TripDistance * 2.10 + TripNumber * 15.00;
		TotalCost += TripCost;
		count++;
		
		if (count%10 == 4 || count < 4)
		{
			cout << setprecision (2) << fixed
				<< setw(11) << count
				<< setw(10) << ReturnTrip
				<< setw(10) << TripNumber
				<< setw(15) << TripDistance
				<< setw(13) << TripCost
				<< setw(17) << TotalDistance
				<< setw(17) << TotalCost
				<< endl;
		}
	}

	cout << setprecision (2) << fixed
		<< setw(11) << count
		<< setw(10) << ReturnTrip
		<< setw(10) << TripNumber
		<< setw(15) << TripDistance
		<< setw(13) << TripCost
		<< setw(17) << TotalDistance
		<< setw(17) << TotalCost
		<< endl; 

	return EXIT_SUCCESS;
}
