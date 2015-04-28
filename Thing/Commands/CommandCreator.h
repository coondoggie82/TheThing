/*
 * CommandCreator.h
 *
 *  Created on: Apr 27, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_COMMANDCREATOR_H_
#define COMMANDS_COMMANDCREATOR_H_

#include "Arduino.h"
#include "Parameters.h"
#include "CommandCenter.h"
#include "StringHashTable.h"
#include "PrintCommand.h"

class CommandCreator {
public:
	CommandCreator();
	virtual ~CommandCreator();
	bool createCommand(String command, Parameters *params);
private:
	static CommandCenter *commandCenter;
	StringHashTable commandHash;
	static bool printSomething(Parameters *params);
};

#endif /* COMMANDS_COMMANDCREATOR_H_ */