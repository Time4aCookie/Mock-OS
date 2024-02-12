#include "../../include/mockos/CommandPrompt.h"
#include <utility>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

CommandPrompt::CommandPrompt() {
	system = nullptr;
	factory = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	system = afs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	factory = aff;
}

int CommandPrompt::addCommand(string str, AbstractCommand* ac) {
	auto result = comm.insert(pair<string, AbstractCommand*>(str, ac));
	if (result.second) {
		return success;
	}
	return addFailed;
}

void CommandPrompt::listCommands() {
	auto current = comm.begin();
	while (current != comm.end()) {
		cout << current->first << endl;
		++current;
	}
}

std::string CommandPrompt::prompt() {
	string input;
	cout << "$ " << flush;

#ifdef _WIN32
	getline(cin, input);
	return input;
#endif

	std::system("stty raw -echo");
	bool inEscape = false;
	bool quit = false;
	int historyProgress = 0;
	char backspace = 8;

	while (true) {		int c = getchar();

		char ch = char(c);
		string cs(1, ch);

		if (ch >= 32 && ch <= 126 && !inEscape) { // ascii characters
			cout << cs << flush;
			input += cs;
		} else if (ch == '\n' || ch == '\r') { // return
			break;
		} else if (ch == 127) { // reimplement backspace
			if (input.size() > 0) {
				cout << backspace << " " << backspace << flush;
				input = input.substr(0, input.size()-1);
			}
		} else if (ch == 27) {
			inEscape = true;
		} else if (inEscape) { // escaped control characters
			if (c == 91) { // arrow keys
				int c2 = getchar();
				if (c2 == 65 && historyProgress < history.size()) { // up
					++historyProgress;
				} else if (c2 == 66 && historyProgress > 0) { // down
					--historyProgress;
				}
				string newCommand;
				if (historyProgress > 0) {
					newCommand = history[history.size() - historyProgress];
				} else {
					newCommand = "";	
				}
				for (int i = 0; i < input.size(); i++) {
					cout << backspace << " " << backspace << flush;
				}
				cout << newCommand;
				input = newCommand;
			}
			inEscape = false;
		} else if (ch == 3) { // control-c to quit
			quit = true;
			break;
		} else if (ch == '\t') { // tab autocomplete
			int lastSpaceIndex = 0;
			for (int i = input.size() - 1; i >= 0; --i) {
				if (input[i] == ' ') {
					lastSpaceIndex = i + 1;
					break;
				}
			}
			string wordToComplete = input.substr(lastSpaceIndex);
			if (wordToComplete.size() > 0) {

				auto fileNames = system->getFileNames();
				auto current = fileNames.cbegin();
				while (current != fileNames.cend()) {
					if (wordToComplete.size() < current->size()) {
						if (current->substr(0, wordToComplete.size()) == wordToComplete) {
							string remainder = current->substr(wordToComplete.size());	
							input += remainder;
							cout << remainder << flush;
							break;
						}
					}
					++current;
				}
			}
		}
	}

	std::system("stty -raw echo");
	cout << endl;

	return quit ? "q" : input;
}

int CommandPrompt::run() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	while (true) {
		string input = prompt();
		if (input == "q" || input == "exit") {
			return quit;
		}
		string word;
		istringstream iss(input);
		vector<string> words;

		while (iss >> word) {
			words.push_back(word);
		}

		if (words.size() == 0) {
			continue;
		}

		history.push_back(input);

		if (words[0] == "help") {
			if (words.size() == 2) {
				auto command = comm.find(words[1]);
				if (command != comm.end()) {
					command->second->displayInfo();
				} else {
					cout << "No help information for " << words[1] << endl;
				}
			}	else {
				listCommands();
			}
		} else {
			auto command = comm.find(words[0]);
			if (command != comm.end()) {
				string args;
				for (int i = 1; i < words.size(); ++i) {
					args += words[i] + ((i == words.size() - 1) ? "" : " ");
				}
				int status = command->second->execute(args);
				if (status != success) {
					cout << words[0] << ": command failed" << endl;
				}
			} else {
				cout << words[0] << ": unknown command" << endl;
			}
		}
	}
}
