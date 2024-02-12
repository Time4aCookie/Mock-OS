#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem: public AbstractFileSystem {
	private:
		std::map<std::string, AbstractFile*> files;
		std::set<AbstractFile*> openFiles;
	public:
		int addFile(std::string fileName, AbstractFile* file);
		int deleteFile(std::string fileName);
		AbstractFile* openFile(std::string fileName);
		int closeFile(AbstractFile* file);
		std::set<std::string> getFileNames();
};
