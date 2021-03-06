/*
 * WiggleFingers.h
 *
 *  Created on: May 22, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_WIGGLEFINGERS_H_
#define COMMANDS_WIGGLEFINGERS_H_

#include <CommandBase.h>
#include "Hand.h"
#include "PinDefinitions.h"

class WiggleFingers: public CommandBase {
public:
	WiggleFingers(int minPosition, int maxPosition, int thumbMin, int thumbMax, int fingerDelay, int cycleDelay, int repeats);
	virtual ~WiggleFingers();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	static Hand *hand;
	int cycleCount[5];
	int fingerDelay;
	int repeats;
	bool minAchieved;
	bool direction;
	bool state[5];
	int minPosition;
	int maxPosition;
	int thumbMin;
	int thumbMax;
	unsigned long cycleStart;
	int cycleDelay;
};

#endif /* COMMANDS_WIGGLEFINGERS_H_ */
