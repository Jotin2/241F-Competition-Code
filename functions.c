#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    accel,          sensorAccelerometer)
#pragma config(Motor,  port2,           RF,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RM,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           RB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LF,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LM,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           launcher,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           intake,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * @file functions.c
 * @brief This file contains all functions to be used by
 * the competition code.
 *
 * @warning DO NOT compile this file
 * by itself, it will not work. Instead, save it
 * and compile main.c
 *
 * Also, you must include your motor and sensor setup somewhere in this file.
 *
 * @author	 Sean Kelley      sgtkode01@gmail.com
 * @author   Bernard Suwirjo  bsuwirjo@gmail.com
 *
 */

// GLOBAL VARIABLES
 int array[20];
 int leftButton = 1;
 int centerButton = 2;
 int rightButton = 4;
 int isMain = 1;
 int isBattery = 0;
 int isTest = 0;
 string mainbattery;


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Table of Contents
//
//			Function Name              Arguments  *x is defualt for motor speed
//
// 			drive()--------------------bool half
//			clearMotor()---------------None
//			motorcheck()---------------None
//			fullStop()-----------------int x=118,int direction=0, bool fancy=false
//			forwardSeconds()-----------float s, float x=118
//			backwardSeconds()----------float s, float x=118
//			turnRightDegrees()---------float degree, float x=90
//			turnLeftDegrees()----------float degree, float x=90
//			turnRightSeconds()---------float seconds, float x=118
//			turnLeftSeconds()----------float seconds, float x=118
//      getAccel()-----------------None
//			runLauncher()--------------int rotations, int speed
//			runIntake()----------------float seconds
//			clearLine()----------------None
//      battery()------------------None
//      testLCD()------------------None
//      mainLCD()------------------None
//
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 DRIVETRAIN
//
/////////////////////////////////////////////////////////////////////////////////////////

/**
* Gives drive control to VexNET controller
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*
* @param  half  determines if motors should be running at half speed
*/
void drive(bool half=false)
{
			if (half==false)//Check if drive toggles half speed.
			{
				motor[LF] = -vexRT[Ch3]; //give drive direct control.
				motor[LM] = -vexRT[Ch3];
				motor[LB] = -vexRT[Ch3];
				motor[RF] = vexRT[Ch2];
				motor[RM] = vexRT[Ch2];
				motor[RB] = vexRT[Ch2];
			}
			else if(half ==true)
			{
				motor[LF] = vexRT[Ch3]/3;//give drive control but all motor maxes are a third of their orignal max.
				motor[LM] = vexRT[Ch3]/3;
				motor[LB] = vexRT[Ch3]/3;
				motor[RF] = vexRT[Ch2]/3;
				motor[RM] = vexRT[Ch2]/3;
				motor[RB] = vexRT[Ch2]/3;
			}
}


/**
* Clears all the motors
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*/
void clearMotor()
{
	//Set all motor values to 0
	motor[LF] = 0;
	motor[LM] = 0;
	motor[LB] = 0;

	motor[RF] = 0;
	motor[RM] = 0;
	motor[RB] = 0;
}

/**
* Runs each motor for 1.5 seconds
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*/
void motorcheck()
{
	/*
	motor[FR]=118;//Set individual motor
	wait10Msec(1.5); //Wait 1.5 seconds
	clearMotor(); //clear motor(s)
	motor[BR]=118;
	wait10Msec(1.5);
	clearMotor();
	motor[FL]=118;
	wait10Msec(1.5);
	clearMotor();
	motor[BL]=118;
	wait10Msec(1.5);
	clearMotor();*/
}

/**
* Completely stops all motors without drift
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*
* @param x speed of motors
* @param direction 1=forwards, 2=backwards
* @param fancy use special stuff to stop???
*
*/
void fullStop(int x=118,int direction=0, bool fancy=false)
{
	if(fancy)
	{
		if(direction==1)
		{
			int FR = x;
			int FL = 0;
			int BR = x;
			int BL = 0;
			motor[FR]=FR*-.1;
			motor[FL]=FL*-.1;
			motor[BR]=BR*-.1;
			motor[BL]=BL*-.1;
			wait1Msec(150);
			clearMotor();
		}
		else if(direction==2)
		{
			int FR = 0;
			int FL = x;
			int BR = 0;
			int BL = x;
			motor[FR]=FR*-.1;
			motor[FL]=FL*-.1;
			motor[BR]=BR*-.1;
			motor[BL]=BL*-.1;
			wait1Msec(150);
			clearMotor();
		}
	}
	else
	{
		if(direction==1)
		{
			int FR = x;
			int FL = -x;
			int BR = x;
			int BL = -x;
			motor[FR]=FR*-.1;
			motor[FL]=FL*-.1;
			motor[BR]=BR*-.1;
			motor[BL]=BL*-.1;
			wait1Msec(150);
			clearMotor();
		}
		else if(direction==2)
		{
			int FR = -x;
			int FL = x;
			int BR = -x;
			int BL = x;
			motor[FR]=FR*-.1;
			motor[FL]=FL*-.1;
			motor[BR]=BR*-.1;
			motor[BL]=BL*-.1;
			wait1Msec(150);
			clearMotor();
		}
		else
		{
			int FR = x;
			int FL = x;
			int BR = x;
			int BL = x;
			motor[FR]=FR*-.1;
			motor[FL]=FL*-.1;
			motor[BR]=BR*-.1;
			motor[BL]=BL*-.1;
			wait1Msec(150);
			clearMotor();
		}
	}
}

/**
* Moves bot forward for a given amount of seconds
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*
* @params  s  amount of seconds to move forward
*	@params  x  speed of motors
*
*/
void forwardSeconds(float s,float x=118)
{/*
	//Set all motors to target value
  motor[FL]=x;
	motor[FR]=x;
	motor[BL]=x;
	motor[BR]=x;
	wait1Msec(s*1000);//Wait given amount of time
	fullStop(x);//stop <-- kind of interchangeble with clearMotor()*/
}

/*
* Moves bot backward for a given amount of seconds
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*
* @params  s  amount of seconds to move backward
*	@params  x  speed of motors
*
*/
void backwardSeconds(float s, float x=118)
{/*
	//Set all motors to negative target value
  motor[FL]=-x;
	motor[FR]=-x;
	motor[BL]=-x;
	motor[BR]=-x;
	wait1Msec(s*1000);//Wait given amount of time
	fullStop(x); //Stop*/
}

/**
* Turns bot right a given amount of degrees
*
* @warning requires gyro
* @author Bernard Suwirjo  bsuwirjo@gmail.com
* @author Sean Kelley  sgtkode01@gmail.com
*
* @params  degree  amount of degrees to turn right
*	@params	 x       speed of motors
*
*/
void turnRightDegrees(float degree, float x=90)
{/*
	//Reset gyro
	SensorValue[gyro]=0;
	//gyro takes degrees from 0-3600, so we multiply by 10 to get a gyro processable number
	degree=degree*10;
	//We want to slow down when we approach the target, so we calculate a first turn segment as 60% of the total
	float first=degree*.6;
	while(abs(SensorValue[gyro]) < first) //Turn the first 60%
	{
			//Since it's turn right, we want to set right motors backwards and left motors forward.
			motor[FL] = x;
    	motor[FR] = -x;
    	motor[BL] = x;
    	motor[BR] = -x;
	}
	while(abs(SensorValue[gyro]) <degree) //Turn the remainin amount.
	{
		//We don't want the motors to run too slow, so we set a a safety net. The motor can't have a power less than 40.
		if(x*.35<40)//If 35% of the motor power is less than 40, set the power to 40.
		{
			motor[FL] = 40;
    	motor[FR] = -40;
    	motor[BL] = 40;
    	motor[BR] = -40;
		}
		else //If not set it to 35%
		{
				motor[FL] = x*.35;
	    	motor[FR] = -x*.35;
	    	motor[BL] = x*.35;
	    	motor[BR] = -x*.35;
    }
	}
	clearMotor();*/
}

/**
* Turns bot left a given amount of degrees
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
* @author Sean Kelley  sgtkode01@gmail.com
*
* @params  degree  amount of degrees to turn left
*	@params	 x       speed of motors
*
*/

void turnLeftDegrees(float degree, float x=90)
{/*
	//Reset gyro
	SensorValue[gyro]=0;
	//gyro takes degrees from 0-3600, so we multiply by 10 to get a gyro processable number
	degree=degree*10;
	//We want to slow down when we approach the target, so we calculate a first turn segment as 60% of the total
	float first=degree*.6;
	while(abs(SensorValue[gyro]) < first)
	{
			//Since it's turn left, we want to set right motors forwards and left motors backwards.
				motor[FL] = -x;
  	    motor[FR] = x;
  	    motor[BL] = -x;
  	    motor[BR] = x;
	}
	while(abs(SensorValue[gyro]) < degree)
	{
		//We don't want the motors to run too slow, so we set a a safety net. The motor can't have a power less than 40.
		if(x*.35<40)//If 35% of the motor power is less than 40, set the power to 40.
		{
				motor[FL] = -40;
		    motor[FR] = 40;
		    motor[BL] = -40;
		    motor[BR] = 40;
		}
		else //If not set it to 35%
		{
				motor[FL] = -x*.35;
  	    motor[FR] = x*.35;
  	    motor[BL] = -x*.35;
  	    motor[BR] = x*.35;
    }
	}
	clearMotor();*/
}

/**
* Turns bot right a given amount of seconds
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*
* @params  seconds   amount of seconds to turn right
* @params	 x         speed of motors
*
*/
void turnRightSeconds(float seconds, float x=118)
{/*
	//Since turn right, we want to set left motors forwards and right motors backwards.
	motor[FL]=x;
	motor[BL]=x;
	motor[FR]=-x;
	motor[BR]=-x;
	wait1Msec(seconds*1000); //Wait desired amount of time
	fullStop(); //Stop*/
}

/**
* Turns bot left a given amount of seconds
*
* @author Bernard Suwirjo  bsuwirjo@gmail.com
*
* @params  seconds   amount of seconds to turn left
* @params	 x         speed of motors
*
*/
void turnLeftSeconds(float seconds, float x=118)
{/*
	//Since turn left, we want to set the right motors forward and the left motors backwards
	motor[FL] = -x;
	motor[BL] = -x;
	motor[FR] = x;
	motor[BR] = x;
	wait1Msec(seconds*1000); //Wait desired amount of time
	fullStop(); //Stop*/
}

void getAccel()
{/*
	int current;
  for (int i = 0; i<19; i++)
	  {
	  	current = abs(SensorValue[AccelX]);
	  	array[i] = current;
	  }*/
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 LAUNCHER FUNCTIONS
//
/////////////////////////////////////////////////////////////////////////////////////////
/**
* Runs the launcher with a specific speed for a number of rotations
*
* @author Joshua Asari  josh.asari@gmail.com
*
* @params rotations			the amount of times the launcher will rotate
* @params speed 				the speed at which the motor turns
*/
void runLauncher(int rotations, int speed)
{
	int currentRotation;
	sensorValue[tlaunch] = 0;
	while(currentRotation < rotations)
	{
		while(tball == 0)
		{
			motor[intake] = 118;
			while(sensorValue[tlaunch] == 1)
			{
				motor[intake] = 0;
				motor[launcher] = speed;
			}
			currentRotation++;
		}
	}
	motor[launcher] = 0;
	motor[intake] = 0;
}

void launcherCont()
{
	if(vexRT[Btn6D] == 1)
	{
		motor[launcher] = 118;
	}
	else if(vexRT[Btn5D] == 1)
	{
		motor[launcher] = -118;
	}
	else
	{
		motor[launcher] = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 INTAKE FUNCTIONS
//
/////////////////////////////////////////////////////////////////////////////////////////
/**
* Runs the launcher with a specific speed for a number of rotations
*
* @author Joshua Asari  josh.asari@gmail.com
*
* @params seconds		    amount of time the intake will run for
*/
void runIntake(float seconds)
{
	motor[intake] = 118;
	wait10Msec(seconds*10);
	motor[intake] = 0;
}

void intakeCont()
{
	if(vexRT[Btn6U] == 1)
	{
		motor[intake] = -118;
	}
	else if(vexRT[Btn5U] == 1)
	{
		motor[intake] = 118;
	}
	else
	{
		motor[intake] = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 LCD FUNCTIONS
//
/////////////////////////////////////////////////////////////////////////////////////////
/**
* Clears the lines of the LCD
*
* @author Joshua Asari  josh.asari@gmail.com
*/
void clearline()
{
	clearLCDLine(0);
	clearLCDLine(1);
}

/**
* Shows the battery voltage
*
* @author Joshua Asari  josh.asari@gmail.com
*/
void battery()
{
		  displayLCDString(0, 0, "Primary: ");
		  sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
		  displayNextLCDString(mainBattery);
		  if(nLCDButtons == centerButton)
		  {
		  	isBattery = 0;
		  	isMain = 1;
		  	clearLine();
		  }
}

/**
* Test screen for LCD
*
* @author Joshua Asari  josh.asari@gmail.com
*/
void testLCD()
{
	 displayLCDString(0, 0, "Ben sucks ");
	 if(nLCDButtons == centerButton)
			  {
			  	isTest = 0;
			  	isMain = 1;
			  	clearLine();
			  }
}

/**
* Home screen for LCD
*
* @author Joshua Asari  josh.asari@gmail.com
*/
void mainLCD()
{
	if(nLCDButtons == leftButton)
		{
			isBattery = 1;
			isMain = 0;
			clearline();
		}
	if(nLCDButtons == rightButton)
		{
			isTest = 1;
			isMain = 0;
			clearline();
		}
	if(isMain == 1)
		{
			displayLCDString(0, 0, "Team 241Nautilus");
			displayLCDString(1, 0, "Version 1.1");
		}
	if(isMain == 0 && isBattery == 1)
			{
				while(isMain == 0 && isBattery == 1)
				{
					battery();
				}
		  }
	if(isMain == 0 && isTest == 1)
		{
			while(isMain == 0 && isTest == 1)
			{
				testLCD();
			}
		}
}
