#pragma once
#include "AbstractFile.h"
#include "Constants.h"

class AbstractCommand {
public:
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};
