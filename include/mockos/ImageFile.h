#include <iostream>
#include "AbstractFile.h"
#pragma once

using namespace std;

class ImageFile : public AbstractFile {
	public:
		ImageFile(string input);
		unsigned int getSize() override;
		std::string getName() override;
		int write(vector<char> bytes) override;
		int append(vector<char> bytes) override;
		vector<char> read() override;
		void accept(AbstractFileVisitor* visitor) override;
		int coordsToIndex(int x, int y) const;
		unsigned int getImageDimensions();
		AbstractFile* clone(std::string name) override;
	private:
		string name;
		vector<char> contents;
		char size;
};
