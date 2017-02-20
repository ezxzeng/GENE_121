task main()
{
	for (int i=0; i<5; i++)
		{
			motor[motorA]=75;
			motor[motorC]=75;
			wait1Msec(2000);
			motor[motorA]=0;
			motor[motorC]=0;
			wait1Msec(1000);
		}
}
