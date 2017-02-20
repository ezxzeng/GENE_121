// Emily ZhiXuan Zeng and Hayden Drew Ruston

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream fin("worldTime.txt");
	string place = "";
	int time = 0;
	int timehour = 0;
	double timeminute = 0;
	
	if (!fin)
	{
		cout << "file open error";
		return EXIT_FAILURE;
	}
	double hourx = 0;
	double houry = 0;
	double minutex = 0;
	double minutey = 0;	
	double radians = 0;
	while (fin >> place >> time)	
	{
		timehour = time/100;
		timeminute = time - timehour*100;
		cout << place << " ";
		string minutemodifier = "";
		if (timeminute < 10)
		{
			minutemodifier = "0";
		}
		if (timehour < 12)
		{
			cout << timehour << ":" << minutemodifier << timeminute << "am" << endl;
		}
		else if (timehour == 12)
		{
			cout << timehour << ":" << timeminute << minutemodifier << "pm" << endl;			
		}
		else
		{
			timehour = timehour-12;
			cout << timehour << ":" << timeminute << minutemodifier << "pm" << endl;
		}
		double timeminutepercent = 0;
		timeminutepercent = timeminute*5/3; //convert time minute to percentage of hour
		radians = -(2*M_PI*((timehour*100)+timeminutepercent)/1200) + (M_PI/2); //calculated the radians around the clock
		hourx = 6*(cos(radians));
		houry = 6*(sin(radians));
		if (abs(hourx) < 0.005)
			hourx = 0;
		if (abs(houry) < 0.005)
			houry = 0;
		cout << "hour hand (x,y): (" << hourx << ", " << houry << ")" << endl;
		
		radians = -(timeminutepercent*M_PI*2/100) + (M_PI/2);
		minutex = 10*(cos(radians));
		minutey = 10*(sin(radians));
		if (abs(minutex) < 0.005)
			minutex = 0;
		if (abs(minutey) < 0.005)
			minutey = 0;
		cout << "minute hand (x,y): (" << minutex << ", " << minutey << ")" << endl << endl;
		
	}
	
	fin.close();
	
	return EXIT_SUCCESS;
}

/*
Output

Waterloo 12:00pm
hour hand (x,y): (0, 6)
minute hand (x,y): (0, 10)

Newfoundland 1:30pm
hour hand (x,y): (4.24264, 4.24264)
minute hand (x,y): (0, -10)

Vancouver 9:00am
hour hand (x,y): (-6, 0)
minute hand (x,y): (0, 10)

Casablanca 5:00pm
hour hand (x,y): (3, -5.19615)
minute hand (x,y): (0, 10)

Kathmandu 10:45pm
hour hand (x,y): (-3.65257, 4.76012)
minute hand (x,y): (-10, 0)

Beijing 1:00am
hour hand (x,y): (3, 5.19615)
minute hand (x,y): (0, 10)

Hawaii 7:00am
hour hand (x,y): (-3, -5.19615)
minute hand (x,y): (0, 10)
*/


