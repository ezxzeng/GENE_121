//Emily ZhiXuan Zeng
#include <cmath>
#include <fstream>

using namespace std;

#include "ccc_win.h"

void drawShape(Point drawLocation)
{
	double clickX = drawLocation.get_x();
	double clickY = drawLocation.get_y();
	
	Circle face(drawLocation, 3);

	Line LEye1(Point(clickX-1.5, clickY+1.5), Point(clickX-0.5, clickY+0.5));
	Line LEye2(Point(clickX-0.5, clickY+1.5), Point(clickX-1.5, clickY+0.5));
	Line REye1(Point(clickX+1.5, clickY+1.5), Point(clickX+0.5, clickY+0.5));
	Line REye2(Point(clickX+0.5, clickY+1.5), Point(clickX+1.5, clickY+0.5));
	
	cwin <<face << LEye1 << LEye2 << REye1 << REye2;
	
	Line mouth(Point(clickX-1.5, clickY-1), Point(clickX+1.5, clickY-1));
	Line tongueR(Point(clickX+1.5, clickY-1), Point(clickX+1.5, clickY-2));
	Line tongueB(Point(clickX+1.5, clickY-2), Point(clickX+0.5, clickY-2));
	Line tongueL(Point(clickX+0.5, clickY-2), Point(clickX+0.5, clickY-1));
	Line tongueM(Point(clickX+1, clickY-1), Point(clickX+1, clickY-1.75));
	
	cwin << mouth << tongueR << tongueB << tongueL << tongueM;
}

int ccc_win_main()
{
	int n = cwin.get_int("enter the number of spooky shapes");
	for (int i = 0; i < n; i++)
	{
		Point drawLocation =cwin.get_mouse("where do you want the shape to go"); 
		drawShape(drawLocation); 
	}
	
	return 0;
}

