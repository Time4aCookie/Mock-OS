#include "../../include/mockos/EditDisplayParsingStrategy.h"
#include <sstream>

using namespace std;

std::vector<std::string> EditDisplayParsingStrategy::parse(std::string args) {
	istringstream iss(args);
	string editAndDisplay;
	string optionalAppend;
	if (!(iss >> editAndDisplay)) { // fix this later
		return {};
	}
	if (iss >> optionalAppend) {
		return { editAndDisplay + " " + optionalAppend, editAndDisplay };
	}
	return { editAndDisplay, editAndDisplay };
}