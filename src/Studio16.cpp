#include "../include/mockos/TextFile.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	string s = "hi";
	vector<char> example;
	for(int i = 0; i < 5; i++){
		example.push_back('h');
	}
	TextFile tFile(s);
	AbstractFile & a = tFile;
	a.write(example);
	a.read();
	cout << a.getName() << endl;
}
