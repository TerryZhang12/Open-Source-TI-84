#include "terms.h"

#include <cmath>

Polynomial::Polynomial(unsigned int exponent) : coefficient(1),
                                                exponent(exponent)
{
}

float Polynomial::evaluate(float value) const
{
    return coefficient * pow(value, exponent);
}
