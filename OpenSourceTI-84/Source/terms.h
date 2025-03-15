#pragma once

#include "expression.h"

struct Polynomial : public Expression
{
	float coefficient;
	unsigned int exponent;

	Polynomial(unsigned int exponent);

	float evaluate(float value) const override;
};

