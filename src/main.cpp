#include <Arduino.h>
#include <LibRobus.h>

#define MAX_RIGHTlarge 12800
#define MAX_LEFTlarge 18560

#define MAX_RIGHTshort 8827
#define MAX_LEFTshort 12800



#define NB_SECTIONS 10

void largeTurn()
{
	int rightPulse = 0;
	int leftPulse = 0;

	int totalRight = 0;
	int totalLeft = 0;

	for (int section = 0; section < NB_SECTIONS; section++)
	{

		Serial << "Currently at section " << section << '\n';

		ENCODER_Reset(RIGHT);
		ENCODER_Reset(LEFT);

		rightPulse = 0;
		leftPulse = 0;

		while (rightPulse < (MAX_RIGHTlarge / NB_SECTIONS) && leftPulse < (MAX_LEFTlarge / NB_SECTIONS))
		{
			MOTOR_SetSpeed(RIGHT, 0.32);
			MOTOR_SetSpeed(LEFT, 0.4);

			rightPulse = ENCODER_Read(RIGHT);
			leftPulse = ENCODER_Read(LEFT);

			totalRight += rightPulse;
			totalLeft += leftPulse;
		}

		Serial << "Finished session " << section << '\n';
	}

	MOTOR_SetSpeed(RIGHT, 0);
	MOTOR_SetSpeed(LEFT, 0);
}

void shortTurn()
{
	int rightPulse = 0;
	int leftPulse = 0;

	int totalRight = 0;
	int totalLeft = 0;

	for (int section = 0; section < NB_SECTIONS; section++)
	{

		Serial << "Currently at section " << section << '\n';

		ENCODER_Reset(RIGHT);
		ENCODER_Reset(LEFT);

		rightPulse = 0;
		leftPulse = 0;

		while (rightPulse < (MAX_RIGHTshort / NB_SECTIONS) && leftPulse < (MAX_LEFTshort / NB_SECTIONS))
		{
			MOTOR_SetSpeed(RIGHT, 0.28);
			MOTOR_SetSpeed(LEFT, 0.4);

			rightPulse = ENCODER_Read(RIGHT);
			leftPulse = ENCODER_Read(LEFT);

			totalRight += rightPulse;
			totalLeft += leftPulse;
		}

		Serial << "Finished session " << section << '\n';
	}

	MOTOR_SetSpeed(RIGHT, 0);
	MOTOR_SetSpeed(LEFT, 0);
}


void setup()
{
	// put your setup code here, to run once:

	BoardInit();

	delay(3000);
}

void loop()
{
	// put your main code here, to run repeatedly:

	shortTurn();

	delay(2000);
}