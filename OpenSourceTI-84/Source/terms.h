#pragma once

#include "expression.h"

struct Polynomial : public Expression
{
	float coefficient;
	float exponent;

	Polynomial(float coefficient, float exponent) : coefficient(coefficient),
													exponent(exponent)
	{ }

	float evaluate(float value) const override;
};