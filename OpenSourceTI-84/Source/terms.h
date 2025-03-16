#pragma once

#include "expression.h"
#include <iostream>

struct Polynomial : public Expression
{
	unsigned int exponent;

	Polynomial(unsigned int exponent);

	float evaluate(float value) const override;
};

struct Sin : public Expression
{

	Sin();

	float evaluate(float value) const override;
};

