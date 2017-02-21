//Emily Zeng and Shraddha Shah
int recieveColour_motorPower(int colour, double motorPower)
{
	sensorType[s1] = sensorColorNxtFULL;
	sensorType[s4] = sensorSONAR;
	time[T1] = 0;
	double distance1 = SensorValue[s4];

	motor[motorA] = motorPower;
	motor[motorC] = motorPower;

	while(SensorValue[S1] != colour)
	{}

	double distance2 = SensorValue[s4];
	motor[motorA] = 0;
	motor[motorC] = 0;

	return (distance2-distance1)/(time1[T1]/1000);
}
