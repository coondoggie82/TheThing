/*
 * Finger.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#include <Finger.h>

Finger::Finger(int controlPin, int counterPin)
	:	counter(counterPin),
		fingerMotor(controlPin),
		targetPos(0),
		currentPos(0),
		direction(FWD),
		finished(true)
{
	fingerMotor.setSpeed(0);
}

void Finger::startMotion(int targetPosition, int motionSpeed){
	//int targetPosition: The desired counter value to move to
	//double motionSpeed: The speed to move (number between 0 and 100)
	finished = false;
	targetPos = targetPosition;
	direction = (targetPos>currentPos)?FWD:REV;
	if(direction==FWD){
		fingerMotor.setSpeed(motionSpeed);
	}else{
		fingerMotor.setSpeed(-motionSpeed);
	}
}

void Finger::stopMotion(){
	//Set motor speed to zero;
	fingerMotor.setSpeed(0);
	finished = true;
}

void Finger::update(){
	counter.update(direction);
	currentPos = counter.getCount();
	if((direction&&currentPos>=targetPos)|(!direction&&currentPos<=targetPos)){
		stopMotion();
	}
}

bool Finger::isFinished(){
	return finished;
}

