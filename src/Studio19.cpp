#include "../include/mockos/ImageFile.h"
#include "../include/mockos/Constants.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	AbstractFile* test = new ImageFile("hello");
	vector<char> input = {'X', 'X', 'X', 'X', '2'};
	test->write(input);
	vector<char> contents = test->read();

	for(int i = 0; i < contents.size(); ++i){
		cout << contents[i];
	}
	cout << endl;

	vector<char> input2 = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
	int status = test->write(input2);
	cout << status << endl;
	contents = test->read();
	for(int i = 0; i < contents.size(); ++i){
		cout << contents[i];
	}
	cout << endl;
	return 0;
}


