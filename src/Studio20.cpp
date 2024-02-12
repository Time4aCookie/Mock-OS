#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/TextFile.h"
#include <vector>
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

int main(int argc, char* argv[]) {
	AbstractFile * file = new TextFile("textfile");
	PasswordProxy* protectedFile = new PasswordProxy(file, "johnson");
	vector<char> v = { 'r', 'e', 'p', 's' };
	protectedFile->write(v);
	protectedFile->read();
	MetadataDisplayVisitor vis;
	protectedFile->accept(&vis);
}