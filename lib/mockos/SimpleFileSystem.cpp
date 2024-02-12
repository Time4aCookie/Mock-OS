#include "../../include/mockos/SimpleFileSystem.h"
#include "../../include/mockos/Constants.h"
#include <utility>
#include <algorithm>

using namespace std;

int SimpleFileSystem::addFile(std::string fileName, AbstractFile *file) {
	if (files.find(fileName) != files.end()) {
		return fileAlreadyExists;
	}

	if (file == nullptr) {
		return badArguments;
	}

	files.insert(pair<string, AbstractFile*>(fileName, file));

	return success;
}

AbstractFile* SimpleFileSystem::openFile(std::string fileName) {
	AbstractFile* file;
	try {
		file = files.at(fileName);
	} catch (...) {
		return nullptr;
	}

	if (openFiles.find(file) != openFiles.end()) {
		return nullptr;	
	}

	openFiles.insert(file);

	return file;
}

int SimpleFileSystem::closeFile(AbstractFile* file){
	if (openFiles.find(file) != openFiles.end()){
		auto begin = openFiles.begin();
		while (begin != openFiles.end()) {
			AbstractFile* f = *begin;
			if (f == file) {
				openFiles.erase(begin);
				break;
			}
			++begin;
		}
		return success;
	}
	return fileNotFound;
}

int SimpleFileSystem::deleteFile(std::string fileName) {
	AbstractFile* file;
	try {
		file = files.at(fileName);
	} catch (...) {
		return fileNotFound;
	}
	auto begin = openFiles.begin();
	while (begin != openFiles.end()) {
		AbstractFile* f = *begin;
		if (f == file) {
			openFiles.erase(begin);
			break;
		}
		++begin;
	}
	files.erase(fileName);
	delete file;
	return success;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> fileNames;
	auto begin = files.begin();
	while (begin != files.end()) {
		fileNames.insert(begin->first);
		++begin;
	}
	return fileNames;
}
