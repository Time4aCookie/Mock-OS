#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileVisitor.h"

class DisplayCommand: public AbstractCommand {
private:
	AbstractFileSystem* afs;
	AbstractFileVisitor* afv;
public:
	DisplayCommand(AbstractFileSystem* afs);
	int execute(std::string);
	void displayInfo();
};
