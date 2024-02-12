#include "../../include/mockos/CatCommand.h"
#include "../../include/mockos/AbstractFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs): afs(afs) {};

void CatCommand::displayInfo() {
	cout << "cat - edit a file.\nUsage:\n\tcat <filename> [-a]\n\nOptions:\n\t-a: append to the file instead of overwriting\n\nEditor commands:\n\t:q\tquit without saving\n\t:wq\tsave file and quit" << endl;
}

int CatCommand::execute(string args) {
	istringstream iss(args);
	bool append = false;
	string fileName;
	
	string tmp;
	int numArgs = 2;
	for (int i = 0; i < numArgs + 1; i++) {
		if (i == 0) {
			if (!(iss >> tmp)) {
				return badArguments;
			}
			fileName = tmp;
		}
		else if (i == 1) {
			if (iss >> tmp) {
				if (tmp == "-a") {
					append = true;
				} else {
					return badArguments;
				}
			}
		}
		else {
			if (iss >> tmp) {
				return badArguments;
			}
		}
	}
	string input;
	int result = success;
	AbstractFile* openedFile = afs->openFile(fileName);
	if (openedFile == nullptr) {
		return fileNotFound;
	}
	if (append) {
		vector<char> existingContents = openedFile->read();
		for (int i = 0; i < existingContents.size(); i++) {
			cout << existingContents[i] << flush;
		}
	}
	string newData;
	while (true) {
		getline(cin, input);
		if (!(input != ":q" && input != ":wq")) {
			break;
		}
		if (newData.size() != 0) {
			newData += "\n";
		}
		newData += input;
	}
	if (input == ":wq") {
		std::vector<char> charInput(newData.begin(), newData.end());
		if (append) {
			result = openedFile->append(charInput);
		} else {
			result = openedFile->write(charInput);
		}
	}
	afs->closeFile(openedFile);
	return result;
}
