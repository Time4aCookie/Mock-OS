#pragma once
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

class AbstractFile {
	public:
		virtual std::vector<char> read() = 0;
		virtual int write(std::vector<char> bytes) = 0;
		virtual int append(std::vector<char> bytes) = 0;
		virtual unsigned int getSize() = 0;
		virtual std::string getName() = 0;
		virtual ~AbstractFile() = default;
		virtual void accept(AbstractFileVisitor* visitor) = 0;
		virtual AbstractFile* clone(std::string name) = 0;
	//	bool operator == (AbstractFile* file);
};



