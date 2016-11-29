#pragma config(Motor,  port1,           left,          tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port7,           Hook,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           openclose,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           touchclaw,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          right,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
void pre_auton()
{
	bStopTasksBetweenModes = true;
}
//do not mess with anthing above this!


//****************************************autonomus****************************************
void doAutonomous()
{
	if(vexRT[Btn7L])
	{
 //go forward for three seconds
		motor[right] = 127;
		motor[left] = 127;
		wait1Msec(3000);
		motor[right] = 0;
		motor[left] = 0;
 //go left 90 degrees
		motor[right] = 127;
		motor[left] = 0;
		wait1Msec(2500);
		motor[right] = 0;
		motor[left] = 0;
 //go forward
		motor[right] = 127;
		motor[left] = 127;
		wait1Msec(0500);
		motor[right] = 0;
		motor[left] = 0;
 //go right 90 degrees
		motor[right] = 0;
		motor[left] = 127;
		wait1Msec(0500);
		motor[right] = 0;
		motor[left] = 0;
 //go forward
		motor[right] = 127;
		motor[left] = 127;
		wait1Msec(0400);
		motor[right] = 127;
		motor[left] = 127;
 //lift arm
		motor[touchclaw] = 127;
		wait1Msec(2000);
		motor[touchclaw] = 0;
 //use gear rail
		motor[openclose] = 127;
		wait1Msec(2000);
		motor[openclose] = 0;
 //reverse gear rail
		motor[openclose] = -127;
		wait1Msec(2000);
		motor[openclose] = 0;
 //turn left 90 degrees
		motor[right] = 127;
		motor[left] = 0;
		wait1Msec(1000);
		motor[right] = 0;
		motor[left] = 0;
 //go forward
		motor[right] = 127;
		motor[left] = 127;
		wait1Msec(0500);
		motor[right] = 0;
		motor[left] = 0;
 //turn right
		motor[right] = 0;
		motor[left] = 127;
		wait1Msec(1000);
		motor[right] = 0;
		motor[left] = 0;
 //
	}


}

task autonomous()
{
	doAutonomous();
}

//****************************************usercontrol***************************************
task usercontrol()
{
	while (true)
	{
		if(vexRT[Btn7L] == 1)
		{
			doAutonomous();
		}


		//joystick controls for driving
		motor[right] = vexRT[Ch2];
		motor[left] = vexRT[Ch3];

		//Buttons to move arm
		if(vexRT[Btn5UXmtr2]==1)
		{
			motor[touchclaw] = 120;
		}
		else if(vexRT[Btn5DXmtr2]==1)
		{
			motor[touchclaw] = -80;
		}
		else
		{
			motor[touchclaw] = 0;
		}

		//Buttons to open / close claw
		if(vexRT[Btn6UXmtr2]==1)
		{
			motor[openclose] = 127;
		}
		else if(vexRT[Btn6DXmtr2]==1)
		{
			motor[openclose] = -127;
		}
		else
		{
			motor[openclose] = 0;
			//Buttons to hook for hang hook
			if(vexRT[Btn7UXmtr2]==1)
			{
				motor[Hook] = -127;

			  wait1Msec(0500);

				motor[Hook] = 0;
		  }
		}
	}
}
	//fun code of the day "log.output("hi");" what will this code do and what langwedge
