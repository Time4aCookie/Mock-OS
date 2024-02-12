#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand: public AbstractCommand {
	private:
		AbstractFileSystem* afs;
	public:
		CatCommand(AbstractFileSystem* afs);
		int execute(std::string);
		void displayInfo();
};
