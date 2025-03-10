#pragma once

struct Expression
{
	float coefficient;

	virtual float evaluate(float value) const;
};