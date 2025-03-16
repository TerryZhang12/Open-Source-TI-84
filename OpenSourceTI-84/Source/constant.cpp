#include "constant.h"

ConstNum::ConstNum(float value) : value(value)
{
	this->value = value;
}

float ConstNum::evaluate(float value) const
{
	return this->value;
}
