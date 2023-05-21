// Created by Rohan Tatikonda on 5/20/23.
#pragma once

class Calculator{
public:
	virtual double add(double x, double y) = 0;
	virtual double subtract(double x, double y)= 0;
	virtual double multiply(double x, double y) = 0;
	virtual double divide(double x, double y) = 0;
	virtual double square(double x) = 0;
	virtual double squareRoot(double x) = 0;
	virtual double log(double base, double x) = 0;
};

