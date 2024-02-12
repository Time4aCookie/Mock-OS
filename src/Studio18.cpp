#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"

int main(int argc, char* argv[]) {
	AbstractFileSystem* afs = new SimpleFileSystem();
	AbstractFileFactory* aff = new SimpleFileFactory();

	afs->addFile("johnson.txt", aff->createFile("johnson.txt"));
	AbstractFile* file = afs->openFile("johnson.txt");
	file->write({'r','e','p','s'});
	file->read();
	afs->closeFile(file);
}
