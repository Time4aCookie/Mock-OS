#include "../../include/mockos/LSCommand.h"
#include <iostream>
#include <set>
#include "../../include/mockos/MetadataDisplayVisitor.h"
#include <iomanip>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* afs) {
	this->afs = afs;
}

void LSCommand::displayInfo() {
	cout << "ls - prints a list of files in the file system.\nUsage:\n\tls [-m]\n\nOptions:\n\t-m: show file metadata" << endl;
}

int LSCommand::execute(string arg) {
	int count = 0;
	int maxWidth = 20;
	int buffer = 1;
	set<string> files = afs->getFileNames();
	auto begin = files.begin();
	while (begin != files.end()) {
		if (arg.empty()) {
			++count;
			if (count != 0 && count % 2 == 0)
			{
				cout << *begin << endl;
			} else {
				cout << *begin;
				for (int i = 0; i < (maxWidth + buffer) - begin->size(); i++) {
					cout << " ";
				}
			}
		}
		else if (arg == "-m") {
			MetadataDisplayVisitor* visitor = new MetadataDisplayVisitor();
			AbstractFile* file = afs->openFile(*begin);
			file->accept(visitor);
			int result = afs->closeFile(file);
			if (result != success) {
				return result;
			}
		} else {
			return badArguments;
		}
		++begin;
	}
	cout << endl;
	return success;
}
