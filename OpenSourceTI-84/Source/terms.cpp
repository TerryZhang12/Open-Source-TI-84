#include "terms.h"

#include <cmath>

////////////////////////////////////////
Polynomial::Polynomial(unsigned int exponent) : exponent(exponent)
{
    coefficient = 1;
}

float Polynomial::evaluate(float value) const
{
    //if (value == 1.f) std::cout << exponent << ": " << coefficient * pow(value, exponent) << std::endl;
    return coefficient * pow(value, exponent);
}

////////////////////////////////////////
Sin::Sin()
{
    coefficient = 1;
}

float Sin::evaluate(float value) const
{
    //if (value == 1.f) std::cout << coefficient * sin(value) << std::endl;
    return coefficient * sin(value);
}
