#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/AbstractFileVisitor.h"
#include <algorithm>
#include <iostream>

using namespace std;

TextFile::TextFile(string name): name(name) {};

unsigned int TextFile::getSize() {
	return contents.size();
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> bytes) {
	contents = bytes;
	return 0;
}

int TextFile::append(vector<char> bytes) {
	for (int i = 0; i < bytes.size(); ++i) {
		contents.push_back(bytes[i]);
	}
	return 0;
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor *visitor) {
	visitor->visit_TextFile(this);
}

AbstractFile *TextFile::clone(std::string name) {
	TextFile* copy = new TextFile(name+".txt");
	copy->contents = this->read();
	return copy;
}
