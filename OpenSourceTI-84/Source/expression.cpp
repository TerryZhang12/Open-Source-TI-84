#include "expression.h"

#include <iostream>

Expression::Expression() : coefficient(1.f)
{}

float Expression::evaluate(float value) const
{
	std::cout << "Expression evaluate method not defined!" << std::endl;
	return 0.f;
}