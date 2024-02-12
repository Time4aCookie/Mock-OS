#include "../../include/mockos/CopyCommand.h"
#include <sstream>
#include <iostream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem *afs) : afs(afs){}

int CopyCommand::execute(string args) {
	string word;
	istringstream iss(args);
	vector<string> words;
	while (iss >> word) {
		words.push_back(word);
	}
	if(words.size() == 2) {
		AbstractFile *param = afs->openFile(words[0]);
		if(param != nullptr) {
			AbstractFile *paramClone = param->clone(words[1]);
			int k = afs->addFile(paramClone->getName(), paramClone);
			afs->closeFile(param);
			return k;
		}
		else{
			return badArguments;
		}
	}
	else{
		return badArguments;
	}
}
void CopyCommand::displayInfo() {
	cout << "cp - copies file and stores with different name\n\nUsage:\n\tcp <file to copy> <new name with no extension> " << endl;
}



