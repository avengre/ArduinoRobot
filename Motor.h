#ifndef _MOTOR_H__
#define _MOTOR_H__

#include "Arduino.h"


typedef unsigned char PinNum;
typedef unsigned char uchar;
enum Direction
{
	MOTOR_UNDEFINED,
	MOTOR_FORWARD,
	MOTOR_BACKWARD,
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
		setPower(inPower);
		eMotorDirection = MOTOR_FORWARD;
	};
	void setMotorBackward(uchar inPower = 255)
	{
		DirectionPin = LOW;
		setPower(inPower);
		eMotorDirection = MOTOR_BACKWARD;
	};
	void setPower(uchar inPower)
	{
		PowerPin = inPower;
	};
	uchar getPower()
	{
		return PowerPin;
	};

	bool getIsInverted()
	{
		return bIsInverted;
	};
	bool setIsInverted(bool inInverted)
	{
		bIsInverted = inInverted;
	};
private:
	bool bIsInverted; // If motor will be facing opposite direction, will this be inverted  (IE, left motor and right motor, one will have to be inverted)
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