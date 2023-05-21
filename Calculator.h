// Created by Rohan Tatikonda on 5/20/23.
#pragma once
#include "AbstractMethods.h"

class Calc: public Calculator{
public:
	double add(double x, double y) override;
	double subtract(double x, double y) override;
	double multiply(double x, double y) override;
	double divide(double x, double y) override;
	double square(double x) override;
	double squareRoot(double x) override;
	double log(double base, double x) override;
	~Calc();
};