#pragma once
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include <string>
#include <vector>
#include <map>

class CommandPrompt {
	private:
		std::map<std::string, AbstractCommand*> comm;
		AbstractFileSystem* system;
		AbstractFileFactory* factory;
		std::vector<std::string> history;
	public:
		CommandPrompt();
		void setFileSystem(AbstractFileSystem* afs);
		void setFileFactory(AbstractFileFactory* aff);
		int addCommand(std::string str, AbstractCommand* ac);
		int run();
	protected:
		void listCommands();
		std::string prompt();
};
