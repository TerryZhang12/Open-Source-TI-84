#pragma once

#include "terms.h"
#include <memory>

struct ConstPolynomial : public Polynomial
{
	float value;

	ConstPolynomial(float value);

	float evaluate(float value) const override;
};