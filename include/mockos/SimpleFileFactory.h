#pragma once
#include"AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
	public:
		AbstractFile* createFile(std::string fileName);
};
