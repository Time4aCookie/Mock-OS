#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;
public:
	RemoveCommand(AbstractFileSystem* afs);
	int execute(std::string args) override;
	void displayInfo() override;
};
