// Emily Zeng and Himel Saha
bool UltrasonicAndBumberTest(int power, float distance)
{
	motor[motorA] = power;
	motor[motorC] = power;

	distance = distance + 15;

	SensorType[S1] = sensorTouch;
	SensorType[S4] = sensorSONAR;

	while (SensorValue[S4] > distance)
	{

		if (SensorValue[S1] == 1)
		{
			motor[motorA] = 0;
			motor[motorC] = 0;

			return false;
		}
	}

	motor[motorA] = 0;
	motor[motorC] = 0;

	motor[motorA] = 75;
	motor[motorC] = -75;
	wait1Msec(1350);

	motor[motorA] = 0;
	motor[motorC] = 0;
	return true;
}

task main()
{
	displayString (0, "Monday 29");
	displayString (1, "Press the big");
	displayString (2, "orange button");
	while (nNxtButtonPressed != 3)
	{}
	if (nNxtButtonPressed == 3)
	{
		while (nNxtButtonPressed != -1)
		{}
	}
		
while (UltrasonicAndBumberTest(75,20))
		{}
}