// Created by Rohan Tatikonda on 5/20/23.
#include "Calculator.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	Calc *test = new Calc;
	cout << test->subtract(5,2) << endl;
	cout << test->squareRoot(16) << endl;
	cout << test->log(3,81 ) << endl;
	cout << test->square(2) << endl;
	delete(test);
	test = nullptr;

	}


