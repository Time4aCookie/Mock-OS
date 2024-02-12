#include "../../include/mockos/TouchCommand.h"
#include "../../include/mockos/PasswordProxy.h"
#include <iostream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff) {
	this->afs = afs;
	this->aff = aff;
}

void TouchCommand::displayInfo() {
	cout << "touch - creates an empty file\nUsage:\n\ttouch <filename> [-p]\n\nOptions:\n\t-p: Protect the file with a password" << endl;
}

int TouchCommand::execute(string fName) {
	if (fName.empty()) {
		return badArguments;
	}
	int index = fName.find(" ");
	if (index == string::npos) {
		AbstractFile* newFile = aff->createFile(fName);
		if (newFile == nullptr) {
			return invalidExtension;
		}
		int result = afs->addFile(fName, newFile);
		if (result != success)
		{
			delete newFile;
		}
		return result;
	}
	if ((fName.substr(index + 1, fName.size() - (index + 1))) == "-p") {
		string password;
		cout << "Set a password for this file: " << flush;
		getline(cin, password);
		AbstractFile* newFile = aff->createFile(fName.substr(0, index));
		if (newFile == nullptr) {
			return invalidExtension;
		}
		PasswordProxy* protectedFile = new PasswordProxy(newFile, password); // trim off the argument: " -p"
		int result = afs->addFile(fName.substr(0, fName.size()-3), protectedFile);
		if (result != success)
		{
			delete newFile;
		}
		return result;
	}
	return badArguments;
}
