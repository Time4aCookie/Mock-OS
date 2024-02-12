#pragma once
#include "AbstractFile.h"
#include <vector>
#include <string>

class TextFile: public AbstractFile {
private:
	std::vector<char> contents;
	std::string name;
public:
	TextFile(std::string name);
	std::vector<char> read() override;
	int write(std::vector<char> bytes) override;
	int append(std::vector<char> bytes) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* visitor) override;
	AbstractFile* clone(std::string name) override;
};
