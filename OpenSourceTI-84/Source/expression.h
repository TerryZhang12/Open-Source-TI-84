#pragma once

struct Expression
{
	float coefficient;

	Expression();

	virtual float evaluate(float value) const;
};