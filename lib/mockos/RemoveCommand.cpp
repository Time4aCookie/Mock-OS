#include "../../include/mockos/RemoveCommand.h"
#include <sstream>
#include <iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem *afs): afs(afs) {}

int RemoveCommand::execute(string args) {
	AbstractFile* file = afs->openFile(args);
	if (file == nullptr) {
		return badArguments;
	}
	return afs->deleteFile(args);
}

void RemoveCommand::displayInfo() {
	cout << "rm - removes file\nUsage:\n\trm <filename>" << endl;
}

