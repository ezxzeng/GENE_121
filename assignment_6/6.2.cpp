// Scott Smith and Emily Zeng
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void position(int latDeg,int latMin,int longDeg,int longMin,double&x,double&y)
{
	double lattitude = latDeg + latMin/60.0;
	double longitude = longDeg + longMin/60.0;
	x=longitude*cos((lattitude*M_PI)/180)*111;
	y=lattitude*111;
}

double calcDist(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2-x1), 2)+pow((y2-y1),2));
}

double calcTime(double dist, double speed)
{
	if(speed <=0)
	{
		return -1;
	} else {
	
		return dist/speed;
	}
}

int main ()
{
	int latDeg, latMin, longDeg, longMin;
	double shipX, shipY, helpX, helpY;
	double currSpeed, closeSpeed=0;
	double currDist, closeDist=100000;
	double time, closeTime=0;
	//variables with current and closest versions grouped together for clarity
	string shipName, closeShip;
	ifstream fin("ships.txt");
	
	if (!fin)
	{
		cout << "File open error";
		return -1;
	}
	
	cout << "Enter lattitude and longitude of ship in trouble: ";
	cin >> latDeg >> latMin >> longDeg >> longMin;
	position(latDeg, latMin, longDeg, longMin, shipX, shipY);
	while(fin>>shipName)
	{
		fin >> latDeg >> latMin >> longDeg >> longMin >> currSpeed;
		currSpeed*=1.852;
		//converting nautical miles into km/h
		position(latDeg, latMin, longDeg, longMin, helpX, helpY);
		currDist= calcDist(shipX, shipY, helpX, helpY);
		time = calcTime(currDist, currSpeed);
		cout <<setw(21) <<shipName <<setw(9)<< helpX<<setw(8)<< helpY <<setw(8)<< currSpeed <<setw(8)<< currDist;
		if(time <0){
			cout <<setw(8)<< "NEVER" << endl; 
		}else{
			cout <<setw(8)<< time << endl;
		}
		if(currDist < closeDist && currSpeed>0)
		{
			closeShip = shipName;
			closeDist = currDist;
			closeTime = time;
			
		}
		
	}
	cout << "Closest Ship:" << setw(21) <<  closeShip <<setw(8)<< closeTime << "h";
	
	return 0;
	
}
/*
Enter lattitude and longitude of ship in trouble: 32 17 64 49
              America  6360.48 3472.45  3.8892 299.337 76.9663
         Andrea_Doria  6089.15 3638.95       0 55.8998   NEVER
              Bismark  6163.69 3772.15 15.1864 205.434 13.5275
          Black_Pearl  6037.63 4467.75   6.482 885.437 136.599
             Bluenose  6029.43  3193.1 36.2992 393.939 10.8526
      BoatyMcBoatFace  7650.55 3576.05 13.3344 1568.09 117.597
           C.A.Larson  5178.35 3775.85 11.8528 924.372 77.9876
              Calypso  6208.36 2869.35  22.224  725.11 32.6273
     Campbell's_Sloop  6071.96 3598.25  2.2224 18.1583 8.17056
            ChiChiMon  6561.34 2832.35 21.8536  890.76 40.7603
         Constitution  6486.27  2852.7  3.8892 834.889 214.669
             DOS_Boat  6046.18 3690.75 11.8528 113.274 9.55671
           Eisenhower  5387.77 4460.35 30.1876 1118.74 37.0596
           Enterprise  5521.15 4874.75 39.0772 1408.03  36.032
      Flying_Dutchman  6175.54 3527.95 18.7052 108.353 5.79268
           HMS_Terror  5728.44  4121.8       0 644.335   NEVER
             Kon_Tiki  6079.07  3563.1   2.778 20.6333 7.42738
            Love_Boat  6149.13  3119.1 27.0392 469.109 17.3492
         Lucitania_II  6187.63 4915.45 17.0384 1336.14 78.4196
     Maid_of_the_Mist  6074.66 3583.45  1.2964 7.82011 6.03217
            Mayflower  6859.76  2874.9    4.63 1051.76 227.162
             Nautilus   5167.1    3774 41.1144 935.003 22.7415
                 Nina  5470.38 4478.85  8.7044 1084.62 124.606
           Noah's_Ark  5947.02 5107.85       0 1530.41   NEVER
        Old_Ironsides  5960.05 3613.05  2.5928 125.958   48.58
                 Orca  6383.75  1058.2  2.5928 2543.16 980.854
     Pacific_Princess  5847.03 3942.35  24.076 429.242 17.8286
                Pinta  5849.16  3936.8  8.5192 423.433 49.7034
              Polaris  4961.33 5152.25 26.4836 1928.24 72.8089
             Poseidon  6166.29  4025.6  2.0372 450.023 220.903
   Queen_Elizabeth_II  6062.47 3280.05 12.7788 304.059  23.794
        Rights_of_Man  7522.13 3916.45   13.89 1477.66 106.383
         Royal_Viking  5904.84  3862.8  8.7044 331.046 38.0321
        Ship_of_Fools  6139.63  3474.3  7.7784 123.205 15.8394
   SHIELD_Helicarrier  6123.41  3496.5       0 96.0996   NEVER
 Sir_James_Clark_Ross   5148.7    3774 11.6676 953.028 81.6816
            SS_Minnow  6067.51  3592.7  2.0372  17.598 8.63835
           Star_Ferry  5318.84 5033.85  4.0744 1639.15 402.304
               Tardis   2105.7  6256.7 66.8572 4791.77 71.6717
          The_Batboat  6428.55 3361.45   23.15 411.158 17.7606
              Titanic   8457.7 1489.25       0  3166.6   NEVER
               U-Boat  6166.14  3252.3  7.0376 341.554 48.5327
               Valdez  4291.51    4699 15.0012 2109.99 140.654
Closest Ship:     Maid_of_the_Mist 6.03217h
--------------------------------
Process exited after 6.516 seconds with return value 0
Press any key to continue . . .
*/


/*for 6.3

5.1:
void SpeedTest (int Colour, int Speed, float&encoderSpeed, float&USSpeed)

5.2:
void triangle (int S1, int S2, int S3, double&triArea, double&triPerim)

*/
