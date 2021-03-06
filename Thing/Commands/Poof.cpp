/*
 * Poof.cpp
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#include "Poof.h"

Poofer* Poof::poofer = Poofer::getInstance();

Poof::Poof(unsigned long poofLength)
	: finished(false),
	  poofLength(poofLength),
	  startTime(0)
{
}

Poof::~Poof() {
	// TODO Auto-generated destructor stub
}

void Poof::init(){
	startTime = millis();
	poofer->openFire();
}

void Poof::execute(){
	unsigned long currentTime = millis();
	if((currentTime-startTime) >= poofLength){
		stop();
	}
}

bool Poof::isFinished(){
	return finished;
}

void Poof::stop(){
	poofer->ceaseFire();
	finished = true;
}
