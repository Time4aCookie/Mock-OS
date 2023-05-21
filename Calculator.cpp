// Created by Rohan Tatikonda on 5/20/23.
#include "Calculator.h"

double Calc::add(double x, double y) {
	return x+y;
}
double Calc::divide(double x, double y) {
	return x/y;
}
double Calc::log(double base, double x) { // returns a rounded up whole numer
	int counter = 0;
	int constant = base;
	while (base < x){
		base = base*constant;
		counter++;
	}
	return counter+1;
}
double Calc::multiply(double x, double y) {
	return x*y;
}
double Calc::square(double x) {
	return x*x;
}
double Calc::squareRoot(double x) {
	int answer = 0;
	for(int i = 0; i < x; i++){
		if(i*i >= x){
			answer = i;
			break;
		}
	}
	return answer;
}
double Calc::subtract(double x, double y) {
	return x-y;
}

Calc::~Calc(){}