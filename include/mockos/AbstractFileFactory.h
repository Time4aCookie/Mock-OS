#pragma once
#include "AbstractFile.h"
#include "Constants.h"

class AbstractFileFactory {
	public:
		virtual AbstractFile* createFile(std::string fileName) = 0;
};
