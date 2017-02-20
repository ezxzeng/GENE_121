double encoderspeed (int colour, int speed)
{
	SensorType[S1] = sensorColorNxtFULL;
	nMotorEncoder[motorA] = 0;
	clearTimer(T1);

	motor[motorA] = speed;
	motor[motorC] = speed;
	while (SensorValue[S1] != colour)
		{}

	motor[motorA] = 0;
	motor[motorC] = 0;

	double seconds = time1[T1]/1000.0;
	double distance = nMotorEncoder[motorA] * PI * 1.5 / 180;

	return distance/seconds;

}

task main()
{

}
