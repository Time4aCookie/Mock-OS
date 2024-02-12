#include "../../include/mockos/RenameParsingStrategy.h"
#include <sstream>
#include <vector>

using namespace std;

vector<string> RenameParsingStrategy::parse(string args) {
	istringstream iss(args);
	string existingFile;
	string newName;

	if (!(iss >> existingFile)) {
		return {};
	}

	if (!(iss >> newName)) {
		return {};
	}

	return {
		existingFile + " " + newName,
		existingFile
	};
}
