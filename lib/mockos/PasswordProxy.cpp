#include "../../include/mockos/PasswordProxy.h"
#include "../../include/mockos/Constants.h"
#include <iostream>

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile * afPointer, string password) {
	this->afPointer = afPointer;
	this->password = password;
}

PasswordProxy::~PasswordProxy() {
	delete afPointer;
}

string PasswordProxy::passwordPrompt() {
	string input;	
	cout << "Password for " << afPointer->getName() << ": " << flush;
	getline(cin, input);
	return input;
}

std::vector<char> PasswordProxy::read() {
	string password = passwordPrompt();
	if (this->password == password) {
		return afPointer->read();
	}
	return {};
}

int PasswordProxy::write(std::vector<char> bytes) {
	string password = passwordPrompt();
	if (this->password == password) {
		return afPointer->write(bytes);
	}
	return incorrectPassword;
}

int PasswordProxy::append(std::vector<char> bytes) {
	string password = passwordPrompt();
	if (this->password == password) {
		return afPointer->append(bytes);
	}
	return incorrectPassword;
}

unsigned int PasswordProxy::getSize() {
	return afPointer->getSize();
}

string PasswordProxy::getName() {
	return afPointer->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *visitor) {
	string password = passwordPrompt();
	if (this->password == password) {
		afPointer->accept(visitor);
	} else {
		cout << "Incorrect Password" << endl;
	}
}

AbstractFile* PasswordProxy::clone(std::string name){
	return new PasswordProxy(afPointer->clone(name), password);
}

