#include "../../include/mockos/MacroCommand.h"
#include <iostream>

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs) {};

int MacroCommand::execute(std::string args) {
	auto params = strat->parse(args);

	if (params.size() != commands.size()) {
		return badArguments; 
	}

	for (int i = 0; i < commands.size(); ++i) {
		int status = commands[i]->execute(params[i]);
		if (status != success) {
			return status;
		}
	}
	return success;
}

void MacroCommand::setDisplayInfo(std::string helpText) {
	this->helpText = helpText;
}

void MacroCommand::displayInfo() {
	cout << helpText << endl;	
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
	commands.push_back(cmd);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy *strat) {
	this->strat = strat;
}
