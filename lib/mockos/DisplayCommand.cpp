#include "../../include/mockos/DisplayCommand.h"
#include <sstream>
#include <string>
#include <iostream>
#include "../../include/mockos/BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs): afs(afs) {
	afv = new BasicDisplayVisitor();
}

int DisplayCommand::execute(string args) {
	istringstream iss(args);
	bool rawData = false;
	string fileName;
	
	string tmp;
	while(iss >> tmp) {
		if (tmp == "-d") {
			rawData = true;
		} else {
			fileName = tmp;
		}
	}

	AbstractFile* file = afs->openFile(fileName);
	if (file == nullptr) {
		return fileNotFound;	
	}

	if (rawData) {
		auto bytes = file->read();
		for (int i = 0; i < bytes.size(); ++i) {
			cout << bytes[i];
		}
		cout << endl;
	} else {
		file->accept(afv);
	}
	return afs->closeFile(file); 
}

void DisplayCommand::displayInfo() {
	cout << "ds - displays the contents of a file\nUsage:\n\tds <filename> [-d]\n\nOptions:\n\t-d: show the raw, unprocessed bytes" << endl;
}
