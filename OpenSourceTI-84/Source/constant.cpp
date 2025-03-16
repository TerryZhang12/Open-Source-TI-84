#include "constant.h"

ConstPolynomial::ConstPolynomial(float value) : Polynomial::Polynomial(1)
{
	this->value = value;
}

float ConstPolynomial::evaluate(float value) const
{
	return this->value;
}
