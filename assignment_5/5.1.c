float EncoderSpeed (int colour, int speed)
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

	float seconds = time1[T1]/1000.0;
	float distance = nMotorEncoder[motorA] * PI * 1.5 / 180;

	return distance/seconds;
}

float UltraSonarSpeed(int colour, int motorPower)
{
	SensorType[S1] = sensorColorNxtFULL;
	SensorType[S4] = sensorSONAR;
	float distance1 = SensorValue[S4];
	time1[T1] = 0;

	motor[motorA] = motorPower;
	motor[motorC] = motorPower;

	while(SensorValue[S1] != colour)
	{}

	float distance2 = SensorValue[S4];
	motor[motorA] = 0;
	motor[motorC] = 0;

	return (distance1-distance2)/(time1[T1]/1000.0);
}

void orangeButtonPress()
{

	while (nNxtButtonPressed != 3)
	{}

	while (nNxtButtonPressed != -1)
	{}

}

task main()
{
	displayString(0, "Friday 31");
	float AvePercentError = 0;
	int colour = 2;
	int power = 40;

	for (int i = 1; i < 4; i++)
	{
		orangeButtonPress();

		float encSpeed = EncoderSpeed(colour, power);
		eraseDisplay();
		displayString(0, "%f", encSpeed);

		orangeButtonPress();

		float USSpeed = UltraSonarSpeed(colour, power);
		displayString(1, "%f", USSpeed);

		float PercentError = 100*(fabs(USSpeed-encSpeed))/encSpeed;
		displayString(2, "%f", PercentError);

		AvePercentError += PercentError/3;

		colour ++;
		power += 20;
	}

	displayString (3, "the average");
	displayString (4, "%% error is");
	displayString (5, "%f %%", AvePercentError);

	wait1Msec(5000);
}
