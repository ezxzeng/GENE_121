

task main()
{
	displayString (0, "Monday 29");

	for (int i = 1; i <= 3; i++)
	{
		while (nNxtButtonPressed == -1)
		{}

			if (nNxtButtonPressed == 2)
			{
				while (nNxtButtonPressed != -1)
					{}

				motor[motorA] = -75;
				motor[motorC] = 75;
				wait1Msec(720);
				motor[motorA] = 0;
				motor[motorC] = 0;
			}

			else if (nNxtButtonPressed == 1)
			{
				while (nNxtButtonPressed != -1)
					{}

				motor[motorA] = 75;
				motor[motorC] = -75;
				wait1Msec(720);
				motor[motorA] = 0;
				motor[motorC] = 0;
			}

			else if (nNxtButtonPressed == 3)
			{
				while (nNxtButtonPressed != -1)
					{}

				displayString (1, "Allons-y!");
				motor[motorA] = 100;
				motor[motorC] = 100;
				wait1Msec(2000);
				motor[motorA] = 0;
				motor[motorC] = 0;
			}
	}

	wait1Msec(1000);


		motor[motorA] = 100;
		motor[motorC] = 100;
		wait1Msec(2000);
		motor[motorA] = 75;
		motor[motorC] = -75;
		wait1Msec(1420);
		motor[motorA] = 0;
		motor[motorC] = 0;


		displayString (3, "THOU SHALT");
		displayString (4, "NOT PASS");

		wait1Msec(1000);

		motor[motorA] = -75;
		motor[motorC] = 175;
		wait1Msec(100);
		motor[motorA] = 75;
		motor[motorC] = -75;
		wait1Msec(200);
		motor[motorA] = -75;
		motor[motorC] = 75;
		wait1Msec(150);
		motor[motorA] = 0;
		motor[motorC] = 0;

		motor[motorA] = -75;
		motor[motorC] = 175;
		wait1Msec(100);
		motor[motorA] = 75;
		motor[motorC] = -75;
		wait1Msec(200);
		motor[motorA] = -75;
		motor[motorC] = 75;
		wait1Msec(150);
		motor[motorA] = 0;
		motor[motorC] = 0;

		wait1Msec(2000);

}
