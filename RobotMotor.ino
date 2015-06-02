#include "Motor.h"

#define SPEED 175

void setup()  // We'll control our own loops so we have deleted loop()
{
	MotorController LeftMotor,RightMotor;
	RightMotor.setPins(9, 12, 3, 0); // Channel A
	LeftMotor.setPins(8, 13, 11, 1); // Channel B
	
	RightMotor.setIsInverted(false);
	LeftMotor.setIsInverted(false);
	
	MovementManager mMovementManager;
	mMovementManager.SetMotors(LeftMotor, RightMotor);
	


	
	mMovementManager.BrakesOff();
	mMovementManager.MoveForward(SPEED);
	delay(5000);
	mMovementManager.FullStop(false);
	delay(2000);
	mMovementManager.MoveBackward(SPEED * 0.75);
	delay(7000);
	mMovementManager.FullStop(false);


	while (true){};
	
}

void loop()
{

}




