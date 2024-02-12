#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand: public AbstractCommand {
	private:
		std::vector<AbstractCommand*> commands;
		AbstractParsingStrategy* strat;
		std::string helpText;
	public:
		MacroCommand(AbstractFileSystem* afs);
		int execute(std::string);
		void displayInfo();
		void setDisplayInfo(std::string helpText);
		void addCommand(AbstractCommand* cmd);
		void setParseStrategy(AbstractParsingStrategy* strat);
};
