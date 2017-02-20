//Emily Zeng and Scott Smith 

void buttonPress(float&time, int&button)
{
	SensorType[S2]=sensorTouch;
	while(nNxtButtonPressed==-1&& SensorValue[S2]==0)
	{}
	button = nNxtButtonPressed;
	time1[T1]=0;
	while(nNxtButtonPressed!=-1 || SensorValue[S2]==1)
	{}
	time = time1[T1];

}

void stopMoving()
{
		motor[motorA]=0;
		motor[motorC]=0;
}

void driveForward(int forward, float time)
{
		SensorType[S3]=sensorSONAR;
		time1[T1]=0;
			motor[motorA]=forward*75;
		motor[motorC]=forward*75;

		while(time1[T1]<time)
		{
			if(SensorValue[S3]<45&&forward!=-1)
			{
				motor[motorA]=30;
				motor[motorC]=30;
			}
		}
		stopMoving();
}
void turn90(int leftTurn, float time)
{
		time1[T1]=0;
		motor[motorA]=75*leftTurn;
		motor[motorC]=-75*leftTurn;
		while(time1[T1]<time)
		{}
		stopMoving();
		//leftTurn is -1 for right turn
}
void robotControls(float time, int button)
{

	if(button ==-1)
	{
		driveForward(-1, time);
	}else if(button ==0)
	{}else if (button ==1)
		{
			turn90(1, time);
		} else if (button ==2)
		{
			turn90(-1, time);
		} else {
		driveForward(1,time);
		}

}

task main()
{
	float time;
	int button;
	displayString(0,"Group 33, Mon Oct. 24");

	for (int i = 0; i < 5; i ++)
	{
		buttonPress(time, button);
		eraseDisplay();
		if(button<0)
		{
			displayString(1,"Button = Touch");
		} else {
			displayString(1, "Button = %i", button);
		}

		displayString (2, "time = %f", time/1000);
		robotControls(time, button);
		eraseDisplay();
	}
}
