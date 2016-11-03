#pragma config(Motor,  port1,           left,          tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           openclose,     tmotorVex393_MC29, openLoop)
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
	    if (vexRT[Btn7L])
		//go forward for 1.6 seconds
			motor[right] = 127;
			motor[left] = 127;
			wait1Msec(1600);
			motor[right] = 0;
			motor[left] = 0;
			//rotate 90 degrees to the left
			motor[right] = 127;
			motor[left] = -127;
			wait1Msec(0694);
			motor[right] = 0;
			motor[left] = 0;
			//go forward for 1.1 seconds
			motor[right] = 127;
			motor[left] = 127;
			wait1Msec(1100);
			motor[right] = 0;
			motor[left] = 0;
			//rotate right 90 deferes
			motor[right] = -127;
			motor[left] = 127;
			wait1Msec(0600);
			motor[right] = 0;
			motor[left] = 0;
			//go forward for 0.5 second
			motor[left] = 127;
			motor[right] = 127;
			wait1Msec(500);
			motor[right] = 0;
			motor[left] = 0;
			//lift arm for 1.5 seconds
			motor[touchclaw] = 127;
			wait1Msec(1000);
			//close claw
			motor[touchclaw] = -127;
			wait1Msec(1000);
			//stop claw
			motor[touchclaw] = 0;
			motor[left] = -127;
			motor[right] = 127;
			wait1Msec(0900);
			motor[left] = 0;
			motor[right] = 0;
			motor[right] = 127;
			motor[left] = 127;
			wait1Msec(0100);
			motor[right] = 0;
			motor[left] = 0;

}

task autonomous()
{
	doAutonomous();
}

//****************************************usercontrol****************************************
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
		if(vexRT[Btn5UXmtr2])
		{
			motor[touchclaw] = 120;
		}
		else if(vexRT[Btn5DXmtr2])
		{
			motor[touchclaw] = -80;
		}
		else
		{
			motor[touchclaw] = 0;
		}

		//Buttons to open / close claw
		if(vexRT[Btn6DXmtr2])
		{
			motor[openclose] = 120;
		}
		else if(vexRT[Btn6UXmtr2])
		{
			motor[openclose] = -120;
		}
		else
		{
			motor[openclose] = 0;
		}
	}
}
			//fun code of the day "log.output("hi");" what will this code do and what langwedge
