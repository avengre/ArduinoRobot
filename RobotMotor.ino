#include "Motor.h"

void setup()  // We'll control our own loops so we have deleted loop()
{
	MotorController LeftMotor,RightMotor;
		LeftMotor.setPins(9, 12, 3, 0);
		RightMotor.setPins(8, 13, 11, 1);
	
	MovementManager mMovementManager;

	mMovementManager.SetMotors(LeftMotor, RightMotor);






}

void loop()
{

}




