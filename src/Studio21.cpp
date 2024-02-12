#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/CommandPrompt.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	SimpleFileSystem* sfs = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	TouchCommand* tComm = new TouchCommand(sfs, sff);
	CommandPrompt* cPrompt = new CommandPrompt();
	cPrompt->addCommand("touch", tComm);
	cPrompt->setFileSystem(sfs);
	cPrompt->setFileFactory(sff);
	cPrompt->run();

	// test if file is there
	AbstractFile * file = sfs->openFile("johnson.txt");
	if (file != nullptr) {
		cout << "success!" << endl;
	}
}
