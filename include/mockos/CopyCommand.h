#pragma once
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include "TextFile.h"
#include "ImageFile.h"

class CopyCommand : public AbstractCommand{
private:
	AbstractFileSystem* afs;
public:
	CopyCommand(AbstractFileSystem* afs);
	int execute(std::string args) ;
	void displayInfo() ;
};