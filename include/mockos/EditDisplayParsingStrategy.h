#pragma once
#include "AbstractParsingStrategy.h"
#include "Constants.h"

class EditDisplayParsingStrategy : public AbstractParsingStrategy {
public:
	std::vector<std::string> parse(std::string args);
};
