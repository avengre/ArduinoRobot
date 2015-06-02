#ifndef _MOTOR_H__
#define _MOTOR_H__

#include "Arduino.h"


typedef unsigned char PinNum;
typedef unsigned char uchar;
enum Direction
{
	MOTOR_UNDEFINED,
	MOTOR_FORWARD,
	MOTOR_BACKWARDS,
	MOTOR_HALTED
};
// This will control each motor, there may be multiple Motor Controllers
class MotorController
{
public:
	MotorController():bIsBraked(false),BrakePin(0),DirectionPin(0),PowerPin(0),SensingPin(0){};
	void setPins(PinNum inBrakePin, PinNum inDirectionPin, PinNum inPowerPin, PinNum inSensingPin)
	{
		BrakePin = inBrakePin;
		DirectionPin = inDirectionPin;
		PowerPin = inPowerPin;
		SensingPin = inSensingPin;
	};

	bool getBrake(){ return bIsBraked; };
	void setBrake(bool inBraked)
	{
		bIsBraked = inBraked;
		digitalWrite(BrakePin, inBraked);
	};

	void setMotorForward(uchar inPower = 255)
	{
		DirectionPin = HIGH;
		
	};

	void setPower(uchar inPower)
	{
		PowerPin = inPower;
	};
	uchar getPower()
	{
		return PowerPin;
	};
private:
	bool bIsBraked;
	PinNum BrakePin, DirectionPin, PowerPin; // Digital
	PinNum SensingPin;  // Analog
	Direction eMotorDirection;
};

// This will control movement of the robot
class MovementManager
{
public:
	void SetMotors(MotorController Controller1, MotorController Controller2)
	{
		LeftMotor = Controller1;
		RightMotor = Controller2;
	};
	
	void MoveForward(uchar inSpeed)
	{

	}
	void MoveBackward(uchar inSpeed)
	{

	}
	void FullStop(bool UseBrake = false)
	{

	}
	void BrakesOn()
	{

	}
	void BrakesOff()
	{

	}


private:
	MotorController LeftMotor, RightMotor;

};

#endif