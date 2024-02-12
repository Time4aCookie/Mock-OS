#include "../include/mockos/ImageFile.h"
#include "../include/mockos/Constants.h"
#include <iostream>
#include "../include/mockos/SimpleFileSystem.h"

using namespace std;

int main(int arc, char* argv[]) {
	string imgName = "hello.img";
	vector<char> imgData = { ' ', 'X', 'X', ' ', '2' };
	ImageFile image(imgName);
	image.write(imgData);

	SimpleFileSystem sfs;
	sfs.addFile(imgName, &image);

	sfs.createFile("Johnson.txt");
	AbstractFile* f = sfs.openFile("Johnson.txt");
	f->write({'h','e','l','l','o',' ','w','o','r','l','d'});
	f->read();
	sfs.closeFile(f);

	AbstractFile* i = sfs.openFile("hello.img");
	i->read();
	sfs.closeFile(i);
}
