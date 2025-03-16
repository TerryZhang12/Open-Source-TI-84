#pragma once

#include "terms.h"
#include <memory>

struct ConstNum : public Expression
{
	float value;

	ConstNum(float value);

	float evaluate(float value) const override;
};