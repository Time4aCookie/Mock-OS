#include <iostream>
#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/Constants.h"

ImageFile::ImageFile(string input): size(0){
	name = input;
}

unsigned int ImageFile::getSize() {
	return contents.size();
}

unsigned int ImageFile::getImageDimensions() {
	return size;
}

std::string ImageFile::getName() {
	return name;
}

int ImageFile::write(std::vector<char> bytes) {
	if (bytes.size() < 2) {
		return invalidVectorContents;
	}

	size = bytes[bytes.size() - 1] - '0'; // make sure to check somewhere else in the code that the char passed in is associated with a number
	
	if (size*size != bytes.size()-1) {
		return invalidVectorContents;	
	}

	contents.resize(size*size);
	for (int i = 0; i < bytes.size()-1; i++) {
		if (bytes[i] != 'X' && bytes[i] != ' ') {
			contents.erase(contents.begin(), contents.end());
			contents.resize(0);
			return invalidVectorContents;
		}
		contents[i] = bytes[i];
	}
	return success;
}

int ImageFile::append(std::vector<char> bytes) {
	return methodNotSupported;
}

vector<char> ImageFile::read() {
	return contents;
}

int ImageFile::coordsToIndex(int x, int y) const {
	return size * y + x;
}

void ImageFile::accept(AbstractFileVisitor *visitor) {
	visitor->visit_ImageFile(this);
}

AbstractFile *ImageFile::clone(std::string name) {
	ImageFile* copy = new ImageFile(name+".img");
	copy->size = this->size;
	copy->contents = this->read();

	return copy;
}
