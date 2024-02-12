#include "../../include/mockos/SimpleFileFactory.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"
#include <string>

using namespace std;

AbstractFile* SimpleFileFactory::createFile(std::string fileName) {
	int dotIndex = fileName.size() - 1;
	while (fileName[dotIndex] != '.') {
		--dotIndex;
		if (dotIndex == -1) {
			return nullptr;
		}
	}

	string extension = fileName.substr(dotIndex + 1, fileName.size() - dotIndex - 1);

	AbstractFile* file;

	if (extension == "txt") {
		file = new TextFile(fileName);
	} else if (extension == "img") {
		file = new ImageFile(fileName);
	} else {
		return nullptr;
	}
	return file;
}
